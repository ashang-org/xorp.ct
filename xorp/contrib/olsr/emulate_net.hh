// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-
// vim:set sts=4 ts=8 sw=4:

// Copyright (c) 2001-2009 XORP, Inc.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, Version 2, June
// 1991 as published by the Free Software Foundation. Redistribution
// and/or modification of this program under the terms of any other
// version of the GNU General Public License is not permitted.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. For more details,
// see the GNU General Public License, Version 2, a copy of which can be
// found in the XORP LICENSE.gpl file.
// 
// XORP Inc, 2953 Bunker Hill Lane, Suite 204, Santa Clara, CA 95054, USA;
// http://xorp.net

// $XORP: xorp/contrib/olsr/emulate_net.hh,v 1.3 2008/10/02 21:56:34 bms Exp $

#ifndef __OLSR_EMULATE_NET_HH__
#define __OLSR_EMULATE_NET_HH__

#include <deque>

/**
 * Bind together a set of IO classes in order to form a virtual subnet
 * for testing, one instance per subnet.
 */
class EmulateSubnet {
 public:
    EmulateSubnet(TestInfo& info, EventLoop& eventloop);
    virtual ~EmulateSubnet();

    /**
     * Receive frames
     *
     * All frames generated by an OLSR instance arrive here. Note
     * that a frame arriving from one OLSR instance is not sent
     * directly to another. The frames are queued and only when OLSR
     * instance gives back control to the eventloop are the frames
     * forwarded. This ensures that two OLSR instances are not in each
     * others call graphs, which can cause re-entrancy problems.
     */
    void
    receive_frames(const string& interface, const string& vif,
		   IPv4 dst, uint16_t dport, IPv4 src, uint16_t sport,
		   uint8_t* data, uint32_t len, const string instance);

    /**
     * Bind an interface to the emulated subnet.
     */
    virtual void
    bind_interface(const string& instance,
		   const string& interface, const string& vif,
		   const IPv4& listen_addr, const uint16_t listen_port,
		   DebugIO& io);

    /**
     * Unbind an interface from the emulated subnet.
     */
    void
    unbind_interface(const string& instance,
		     const string& interface, const string& vif,
		     const IPv4& listen_addr, const uint16_t listen_port,
		     DebugIO& io);

    inline void set_all_nodes_addr(IPv4 all_nodes_addr) {
	_all_nodes_addr = all_nodes_addr;
    }

 protected:
    class Multiplex {
    public:
	Multiplex(const string& instance,
		    const string& interface, const string& vif,
		    IPv4 listen_addr, uint16_t listen_port);
	inline bool operator <(const Multiplex& him) const {
	    return him._instance < _instance;
	}
	const string	_instance;
	const string	_interface;
	const string	_vif;
	const IPv4	_listen_addr;
	const uint16_t	_listen_port;
    };

    class Frame {
    public:
	Frame(const string& interface, const string& vif,
	    IPv4 dst, uint16_t dport,
	    IPv4 src, uint16_t sport,
	    uint8_t* data, uint32_t len,
	    string instance);

	// for use by EmulateSubnetHops
	inline vector<uint8_t>& get_buffer() { return _pkt; }

	string		_interface;	// uniquely identifies link
	string		_vif;
	IPv4		_dst;		// IP header fields
	uint16_t	_dport;
	IPv4		_src;
	uint16_t	_sport;
	vector<uint8_t> _pkt;		// payload
	string		_instance;
    };

protected:
    void next();
    virtual void forward(Frame frame);

protected:
    TestInfo&	_info;
    EventLoop&	_eventloop;

    map<const Multiplex, DebugIO *> _ios;

    XorpTimer _timer;
    deque<Frame> _queue[2];
    int _queue_add;
    int _queue_remove;
    IPv4 _all_nodes_addr;
};

/**
 * Bind together a set of IO classes like EmulateSubnet, however,
 * in this case, any OLSR protocol messages which flow through this
 * entity have their hopcount and TTL decremented by a given integer.
 *
 * TODO: Simulate ETX-measurable loss on link. For this we need
 * only drop HELLO messages to create a situation where the measured ETX
 * for the link will increase.
 */
class EmulateSubnetHops : public EmulateSubnet {
 public:
    EmulateSubnetHops(TestInfo& info, EventLoop& eventloop,
		      uint8_t hopdelta = 1, uint8_t maxlinks = 2);

    virtual ~EmulateSubnetHops();

    inline uint8_t hopdelta() const { return _hopdelta; }
    inline size_t empty_pkt_drops() const { return _empty_pkt_drops; }
    inline size_t ttl_msg_drops() const { return _ttl_msg_drops; }

    /**
     * When used to simulate a cloud, enforce any limit on the number
     * of links connected to that cloud by using a run-time assertion.
     */
    void
    bind_interface(const string& instance,
		   const string& interface, const string& vif,
		   const IPv4& listen_addr, const uint16_t listen_port,
		   DebugIO& io);

 protected:
    /**
     * Forward the given OLSR frame, however, decrement the hop counts
     * in the Packet and in any contained Messages.
     * Note that duplicate packet detection is NOT performed; it is always
     * assumed that the given frame will be forwarded in either direction.
     */
    void forward(Frame frame);

 private:
    MessageDecoder	_md;
    uint8_t		_hopdelta;
    uint8_t		_maxlinks;
    size_t		_empty_pkt_drops;
    size_t		_ttl_msg_drops;
};

#endif // __OLSR_EMULATE_NET_HH__
