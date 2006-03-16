// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2006 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/rip/auth.cc,v 1.26 2006/02/15 18:38:03 pavlin Exp $"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "rip_module.h"

#include <functional>
#include <openssl/md5.h>

#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/eventloop.hh"

#include "constants.hh"
#include "auth.hh"

// ----------------------------------------------------------------------------
// AuthHandlerBase implementation

AuthHandlerBase::~AuthHandlerBase()
{
}

const string&
AuthHandlerBase::error() const
{
    return _err;
}

inline void
AuthHandlerBase::reset_error()
{
    if (_err.empty() == false)
	_err.erase();
}

inline void
AuthHandlerBase::set_error(const string& err)
{
    _err = err;
}

// ----------------------------------------------------------------------------
// NullAuthHandler implementation

uint32_t
NullAuthHandler::head_entries() const
{
    return 0;
}

uint32_t
NullAuthHandler::max_routing_entries() const
{
    return RIPv2_ROUTES_PER_PACKET;
}

const char*
NullAuthHandler::name() const
{
    return auth_type_name();
}

const char*
NullAuthHandler::auth_type_name()
{
    return "none";
}

bool
NullAuthHandler::authenticate_inbound(const uint8_t*		packet,
				      size_t			packet_bytes,
				      const PacketRouteEntry<IPv4>*& entries,
				      uint32_t&			n_entries,
				      const IPv4&,
				      bool)
{
    entries = 0;
    n_entries = 0;

    if (packet_bytes > RIPv2_MAX_PACKET_BYTES) {
	set_error(c_format("packet too large (%u bytes)",
			   XORP_UINT_CAST(packet_bytes)));
	return false;
    } else if (packet_bytes < RIPv2_MIN_PACKET_BYTES) {
	set_error(c_format("packet too small (%u bytes)",
			   XORP_UINT_CAST(packet_bytes)));
	return false;
    }

    size_t entry_bytes = packet_bytes - sizeof(RipPacketHeader);
    if (entry_bytes % sizeof(PacketRouteEntry<IPv4>)) {
	set_error(c_format("non-integral route entries (%u bytes)",
			    XORP_UINT_CAST(entry_bytes)));
	return false;
    }

    n_entries = entry_bytes / sizeof(PacketRouteEntry<IPv4>);
    if (n_entries == 0) {
	return true;
    }

    entries = reinterpret_cast<const PacketRouteEntry<IPv4>*>
	(packet + sizeof(RipPacketHeader));

    // Reject packet if first entry is authentication data
    if (entries[0].is_auth_entry()) {
	set_error(c_format("unexpected authentication data (type %d)",
			   entries[0].tag()));
	entries = 0;
	n_entries = 0;
	return false;
    }

    reset_error();
    return true;
}

bool
NullAuthHandler::authenticate_outbound(RipPacket<IPv4>&	packet,
				       list<RipPacket<IPv4> *>& auth_packets,
				       size_t&		n_routes)
{
    // XXX: nothing to do so just create a single copy
    RipPacket<IPv4>* copy_packet = new RipPacket<IPv4>(packet);
    auth_packets.push_back(copy_packet);

    reset_error();

    n_routes = packet.data_bytes() - sizeof(RipPacketHeader);
    n_routes /= sizeof(PacketRouteEntry<IPv4>);

    return (true);
}


// ----------------------------------------------------------------------------
// Plaintext handler implementation

uint32_t
PlaintextAuthHandler::head_entries() const
{
    return 1;
}

uint32_t
PlaintextAuthHandler::max_routing_entries() const
{
    return RIPv2_ROUTES_PER_PACKET - 1;
}

const char*
PlaintextAuthHandler::name() const
{
    return auth_type_name();
}

const char*
PlaintextAuthHandler::auth_type_name()
{
    return "simple";
}

void
PlaintextAuthHandler::set_key(const string& plaintext_key)
{
    _key = string(plaintext_key, 0, 16);
}

const string&
PlaintextAuthHandler::key() const
{
    return _key;
}

bool
PlaintextAuthHandler::authenticate_inbound(const uint8_t*	packet,
					   size_t		packet_bytes,
					   const PacketRouteEntry<IPv4>*& entries,
					   uint32_t&		n_entries,
					   const IPv4&,
					   bool)
{
    entries = 0;
    n_entries = 0;

    if (packet_bytes > RIPv2_MAX_PACKET_BYTES) {
	set_error(c_format("packet too large (%u bytes)",
			   XORP_UINT_CAST(packet_bytes)));
	return false;
    }

    if (packet_bytes < RIPv2_MIN_AUTH_PACKET_BYTES) {
	set_error(c_format("packet too small (%u bytes)",
			   XORP_UINT_CAST(packet_bytes)));
	return false;
    }

    size_t entry_bytes = packet_bytes - sizeof(RipPacketHeader);
    if (entry_bytes % sizeof(PacketRouteEntry<IPv4>)) {
	set_error(c_format("non-integral route entries (%u bytes)",
			   XORP_UINT_CAST(entry_bytes)));
	return false;
    }

    const PlaintextPacketRouteEntry4* ppr =
	reinterpret_cast<const PlaintextPacketRouteEntry4*>
	(packet + sizeof(RipPacketHeader));

    if (ppr->addr_family() != PlaintextPacketRouteEntry4::ADDR_FAMILY) {
	set_error("not an authenticated packet");
	return false;
    } else if (ppr->auth_type() != PlaintextPacketRouteEntry4::AUTH_TYPE) {
	set_error("not a plaintext authenticated packet");
	return false;
    }

    string passwd = ppr->password();
    if (passwd != key()) {
	set_error(c_format("wrong password \"%s\"", passwd.c_str()));
	return false;
    }

    reset_error();
    n_entries = entry_bytes / sizeof(PacketRouteEntry<IPv4>) - 1;
    if (n_entries)
	entries = reinterpret_cast<const PacketRouteEntry<IPv4>*>(ppr + 1);

    return true;
}

bool
PlaintextAuthHandler::authenticate_outbound(RipPacket<IPv4>&	packet,
					    list<RipPacket<IPv4> *>& auth_packets,
					    size_t&		n_routes)
{
    PacketRouteEntry<IPv4>* first_entry = NULL;

    if (head_entries() > 0)
	first_entry = packet.route_entry(0);

    static_assert(sizeof(*first_entry) == 20);
    static_assert(sizeof(PlaintextPacketRouteEntry4) == 20);
    XLOG_ASSERT(packet.data_ptr() + sizeof(RipPacketHeader) ==
		reinterpret_cast<const uint8_t*>(first_entry));

    PlaintextPacketRouteEntry4* ppr =
	reinterpret_cast<PlaintextPacketRouteEntry4*>(first_entry);
    ppr->initialize(key());

    // XXX: just create a single copy
    RipPacket<IPv4>* copy_packet = new RipPacket<IPv4>(packet);
    auth_packets.push_back(copy_packet);

    reset_error();

    n_routes = packet.data_bytes() - sizeof(RipPacketHeader);
    n_routes /= sizeof(PacketRouteEntry<IPv4>);
    n_routes--;		// XXX: exclude the first (authentication) entry

    return (true);
}


// ----------------------------------------------------------------------------
// MD5AuthHandler::MD5Key implementation

MD5AuthHandler::MD5Key::MD5Key(uint8_t		key_id,
			       const string&	key,
			       uint32_t		start_secs,
			       XorpTimer	to)
    : _id(key_id), _start_secs(start_secs), _o_seqno(0), _to(to)
{
    string::size_type n = key.copy(_key_data, 16);
    if (n < KEY_BYTES) {
	memset(_key_data + n, 0, KEY_BYTES - n);
    }
}

string
MD5AuthHandler::MD5Key::key() const
{
    return string(_key_data, 0, 16);
}

uint32_t
MD5AuthHandler::MD5Key::end_secs() const
{
    if (_to.scheduled()) {
	return _to.expiry().sec();
    }
    return _start_secs;
}

bool
MD5AuthHandler::MD5Key::persistent() const
{
    return _to.scheduled() == false;
}

bool
MD5AuthHandler::MD5Key::valid_at(uint32_t when_secs) const
{
    if (persistent())
	return true;

    // XXX Need to deal with clock wrap.
    if (when_secs - start_secs() > 0x7fffffff)
	return false;

    // Subtract start time to partially mitigate problems of clock wrap.
    return (when_secs - start_secs() <= end_secs() - start_secs());
}

void
MD5AuthHandler::MD5Key::reset()
{
    //
    // Reset the seqno
    //
    _lr_seqno.clear();

    //
    // Reset the flag that a packet has been received
    //
    _pkts_recv.clear();
}

void
MD5AuthHandler::MD5Key::reset(const IPv4& src_addr)
{
    map<IPv4, uint32_t>::iterator seqno_iter;
    map<IPv4, bool>::iterator recv_iter;

    //
    // Reset the seqno
    //
    seqno_iter = _lr_seqno.find(src_addr);
    if (seqno_iter != _lr_seqno.end())
	_lr_seqno.erase(seqno_iter);

    //
    // Reset the flag that a packet has been received
    //
    recv_iter = _pkts_recv.find(src_addr);
    if (recv_iter != _pkts_recv.end())
	_pkts_recv.erase(recv_iter);
}

bool
MD5AuthHandler::MD5Key::packets_received(const IPv4& src_addr) const
{
    map<IPv4, bool>::const_iterator iter;

    iter = _pkts_recv.find(src_addr);
    if (iter == _pkts_recv.end())
	return (false);

    return (iter->second);
}

uint32_t
MD5AuthHandler::MD5Key::last_seqno_recv(const IPv4& src_addr) const
{
    map<IPv4, uint32_t>::const_iterator iter;

    iter = _lr_seqno.find(src_addr);
    if (iter == _lr_seqno.end())
	return (0);

    return (iter->second);
}

void
MD5AuthHandler::MD5Key::set_last_seqno_recv(const IPv4& src_addr,
					    uint32_t seqno)
{
    map<IPv4, uint32_t>::iterator seqno_iter;
    map<IPv4, bool>::iterator recv_iter;

    //
    // Set the seqno
    //
    seqno_iter = _lr_seqno.find(src_addr);
    if (seqno_iter == _lr_seqno.end())
	_lr_seqno.insert(make_pair(src_addr, seqno));
    else
	seqno_iter->second = seqno;

    //
    // Set the flag that a packet has been received
    //
    recv_iter = _pkts_recv.find(src_addr);
    if (recv_iter == _pkts_recv.end())
	_pkts_recv.insert(make_pair(src_addr, true));
    else
	recv_iter->second = true;
}


// ----------------------------------------------------------------------------
// MD5AuthHandler implementation

MD5AuthHandler::MD5AuthHandler(EventLoop& e)
    : _e(e)
{
}

uint32_t
MD5AuthHandler::head_entries() const
{
    return 1;
}

uint32_t
MD5AuthHandler::max_routing_entries() const
{
    return RIPv2_ROUTES_PER_PACKET - 1;
}

const char*
MD5AuthHandler::name() const
{
    return auth_type_name();
}

const char*
MD5AuthHandler::auth_type_name()
{
    return "md5";
}

bool
MD5AuthHandler::add_key(uint8_t       key_id,
			const string& key,
			uint32_t      start_secs,
			uint32_t      end_secs)
{
    if (start_secs > end_secs) {
	return false;
    }

    XorpTimer timeout;
    if (start_secs != end_secs) {
	timeout = _e.new_oneoff_at(TimeVal(end_secs, 0),
				   callback(this,
					    &MD5AuthHandler::remove_key_cb,
					    key_id));
    }

    KeyChain::iterator i = _key_chain.begin();
    while (i != _key_chain.end()) {
	if (key_id == i->id()) {
	    *i = MD5Key(key_id, key, start_secs, timeout);
	    return true;
	}
	++i;
    }
    _key_chain.push_back(MD5Key(key_id, key, start_secs, timeout));
    return true;
}

bool
MD5AuthHandler::remove_key(uint8_t key_id)
{
    KeyChain::iterator i =
	find_if(_key_chain.begin(), _key_chain.end(),
		bind2nd(mem_fun_ref(&MD5Key::id_matches), key_id));
    if (_key_chain.end() != i) {
	_key_chain.erase(i);
	return true;
    }
    return false;
}


MD5AuthHandler::KeyChain::const_iterator
MD5AuthHandler::key_at(uint32_t now_secs) const
{
    return find_if(_key_chain.begin(), _key_chain.end(),
		   bind2nd(mem_fun_ref(&MD5Key::valid_at), now_secs));
}

MD5AuthHandler::KeyChain::iterator
MD5AuthHandler::key_at(uint32_t now_secs)
{
    return find_if(_key_chain.begin(), _key_chain.end(),
		   bind2nd(mem_fun_ref(&MD5Key::valid_at), now_secs));
}

uint16_t
MD5AuthHandler::currently_active_key() const
{
    TimeVal now;
    _e.current_time(now);
    KeyChain::const_iterator ki = key_at(now.sec());
    if (_key_chain.end() != ki) {
	return ki->id();
    }
    return 0xffff;	// an invalid key ID
}

void
MD5AuthHandler::reset_keys()
{
    KeyChain::iterator iter;

    for (iter = _key_chain.begin(); iter != _key_chain.end(); ++iter)
	iter->reset();
}

bool
MD5AuthHandler::authenticate_inbound(const uint8_t*		packet,
				     size_t			packet_bytes,
				     const PacketRouteEntry<IPv4>*& entries,
				     uint32_t&			n_entries,
				     const IPv4&		src_addr,
				     bool			new_peer)
{
    static_assert(sizeof(MD5PacketTrailer) == 20);

    entries = 0;
    n_entries = 0;

    if (packet_bytes > RIPv2_MAX_PACKET_BYTES + sizeof(MD5PacketTrailer)) {
	set_error(c_format("packet too large (%u bytes)",
			   XORP_UINT_CAST(packet_bytes)));
	return false;
    }

    if (packet_bytes < RIPv2_MIN_AUTH_PACKET_BYTES) {
	set_error(c_format("packet too small (%u bytes)",
			   XORP_UINT_CAST(packet_bytes)));
	return false;
    }

    const MD5PacketRouteEntry4* mpr =
	reinterpret_cast<const MD5PacketRouteEntry4*>(packet +
						      sizeof(RipPacketHeader));

    if (mpr->addr_family() != MD5PacketRouteEntry4::ADDR_FAMILY) {
	set_error("not an authenticated packet");
	return false;
    }

    if (mpr->auth_type() != MD5PacketRouteEntry4::AUTH_TYPE) {
	set_error("not an MD5 authenticated packet");
	return false;
    }

    if (mpr->auth_bytes() != sizeof(MD5PacketTrailer)) {
	set_error(c_format("wrong number of auth bytes (%d != %u)",
			   mpr->auth_bytes(),
			   XORP_UINT_CAST(sizeof(MD5PacketTrailer))));
	return false;
    }

    if (uint32_t(mpr->auth_offset() + mpr->auth_bytes()) != packet_bytes) {
	set_error(c_format("Size of packet does not correspond with "
			   "authentication data offset and size "
			   "(%d + %d != %u).", mpr->auth_offset(),
			   mpr->auth_bytes(),
			   XORP_UINT_CAST(packet_bytes)));
	return false;
    }

    KeyChain::iterator k = find_if(_key_chain.begin(), _key_chain.end(),
				   bind2nd(mem_fun_ref(&MD5Key::id_matches),
					   mpr->key_id()));
    if (_key_chain.end() == k) {
	set_error(c_format("packet with key ID %d for which no key is "
			   "configured", mpr->key_id()));
	return false;
    }

    if (new_peer)
	k->reset(src_addr);

    uint32_t last_seqno_recv = k->last_seqno_recv(src_addr);
    if (k->packets_received(src_addr) && !(new_peer && mpr->seqno() == 0) &&
	((mpr->seqno() == last_seqno_recv) ||
	 (mpr->seqno() - last_seqno_recv >= 0x7fffffff))) {
	set_error(c_format("bad sequence number 0x%08x < 0x%08x",
			   XORP_UINT_CAST(mpr->seqno()),
			   XORP_UINT_CAST(last_seqno_recv)));
	return false;
    }

    const MD5PacketTrailer* mpt =
	reinterpret_cast<const MD5PacketTrailer*>(packet +
						  mpr->auth_offset());
    if (mpt->valid() == false) {
	set_error("invalid authentication trailer");
	return false;
    }

    MD5_CTX ctx;
    uint8_t digest[16];

    MD5_Init(&ctx);
    MD5_Update(&ctx, packet, mpr->auth_offset() + mpt->data_offset());
    MD5_Update(&ctx, k->key_data(), k->key_data_bytes());
    MD5_Final(digest, &ctx);

    if (memcmp(digest, mpt->data(), mpt->data_bytes()) != 0) {
	set_error(c_format("authentication digest doesn't match local key "
			   "(key ID = %d)", k->id()));
// #define	DUMP_BAD_MD5
#ifdef	DUMP_BAD_MD5
	const char badmd5[] = "/tmp/rip_badmd5";
	// If the file already exists don't dump anything. The file
	// should contain and only one packet.
	if (-1 == access(badmd5, R_OK)) {
	    XLOG_INFO("Dumping bad MD5 to %s", badmd5);
	    FILE *fp = fopen(badmd5, "w");
	    fwrite(packet, packet_bytes, 1 , fp);
	    fclose(fp);
	}
#endif
	return false;
    }

    // Update sequence number only after packet has passed digest check
    k->set_last_seqno_recv(src_addr, mpr->seqno());

    reset_error();
    n_entries = (mpr->auth_offset() - sizeof(RipPacketHeader)) /
	sizeof(PacketRouteEntry<IPv4>) - 1;

    if (n_entries > 0)
	entries = reinterpret_cast<const PacketRouteEntry<IPv4>*>(mpr + 1);

    return true;
}

bool
MD5AuthHandler::authenticate_outbound(RipPacket<IPv4>&	packet,
				      list<RipPacket<IPv4> *>& auth_packets,
				      size_t&		n_routes)
{
    size_t valid_keys = 0;
    TimeVal now;
    RipPacket<IPv4> first_packet(packet);
    vector<uint8_t> first_trailer;

    static_assert(sizeof(MD5PacketTrailer) == 20);

    _e.current_time(now);

    //
    // Create an authenticated copy of the packet for each valid key
    //
    KeyChain::iterator iter;
    for (iter = _key_chain.begin(); iter != _key_chain.end(); ++iter) {
	MD5Key& key = *iter;
	if (! key.valid_at(now.sec()))
	    continue;
	valid_keys++;

	RipPacket<IPv4>* copy_packet = new RipPacket<IPv4>(packet);
	auth_packets.push_back(copy_packet);

	PacketRouteEntry<IPv4>* first_entry = NULL;
	if (head_entries() > 0)
	    first_entry = copy_packet->route_entry(0);

	MD5PacketRouteEntry4* mpr =
	    reinterpret_cast<MD5PacketRouteEntry4*>(first_entry);

	mpr->initialize(copy_packet->data_bytes(), key.id(),
			sizeof(MD5PacketTrailer),
			key.next_seqno_out());

	vector<uint8_t> trailer;
	trailer.resize(sizeof(MD5PacketTrailer));
	MD5PacketTrailer* mpt =
	    reinterpret_cast<MD5PacketTrailer*>(&trailer[0]);
	mpt->initialize();

	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx, copy_packet->data_ptr(), mpr->auth_offset());
	MD5_Update(&ctx, &trailer[0], mpt->data_offset());
	MD5_Update(&ctx, key.key_data(), key.key_data_bytes());
	MD5_Final(mpt->data(), &ctx);

	//
	// XXX: create a copy of the first packet without the trailer
	// and of the trailer itself.
	//
	if (valid_keys == 1) {
	    first_packet = *copy_packet;
	    first_trailer = trailer;
	}

	copy_packet->append_data(trailer);
    }

    if (valid_keys == 0) {
	set_error("no valid keys to authenticate outbound data");
	return (false);
    }

    packet = first_packet;
    n_routes = packet.data_bytes() / sizeof(MD5PacketRouteEntry4) - 1;
    packet.append_data(first_trailer);

    reset_error();

    return (true);
}
