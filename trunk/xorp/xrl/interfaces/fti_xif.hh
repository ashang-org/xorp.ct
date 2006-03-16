/*
 * Copyright (c) 2001-2006 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/fti_xif.hh,v 1.11 2005/03/25 02:54:49 pavlin Exp $
 */

#ifndef __XRL_INTERFACES_FTI_XIF_HH__
#define __XRL_INTERFACES_FTI_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFti"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlFtiV0p2Client {
public:
    XrlFtiV0p2Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlFtiV0p2Client() {}

    typedef XorpCallback8<void, const XrlError&, const IPv4Net*, const IPv4*, const string*, const string*, const uint32_t*, const uint32_t*, const string*>::RefPtr LookupRouteByDest4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Lookup a route for a destination host address.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param dst the destination host address to lookup.
     */
    bool send_lookup_route_by_dest4(
	const char*	target_name,
	const IPv4&	dst,
	const LookupRouteByDest4CB&	cb
    );

    typedef XorpCallback8<void, const XrlError&, const IPv6Net*, const IPv6*, const string*, const string*, const uint32_t*, const uint32_t*, const string*>::RefPtr LookupRouteByDest6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Lookup a route for a destination host address.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param dst the destination host address to lookup.
     */
    bool send_lookup_route_by_dest6(
	const char*	target_name,
	const IPv6&	dst,
	const LookupRouteByDest6CB&	cb
    );

    typedef XorpCallback7<void, const XrlError&, const IPv4*, const string*, const string*, const uint32_t*, const uint32_t*, const string*>::RefPtr LookupRouteByNetwork4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Lookup a route for a destination subnet address.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param dst the destination subnet address to lookup.
     */
    bool send_lookup_route_by_network4(
	const char*	target_name,
	const IPv4Net&	dst,
	const LookupRouteByNetwork4CB&	cb
    );

    typedef XorpCallback7<void, const XrlError&, const IPv6*, const string*, const string*, const uint32_t*, const uint32_t*, const string*>::RefPtr LookupRouteByNetwork6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Lookup a route for a destination subnet address.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param dst the destination subnet address to lookup.
     */
    bool send_lookup_route_by_network6(
	const char*	target_name,
	const IPv6Net&	dst,
	const LookupRouteByNetwork6CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr HaveIpv4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Test if the underlying system supports IPv4.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_have_ipv4(
	const char*	target_name,
	const HaveIpv4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr HaveIpv6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Test if the underlying system supports IPv6.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_have_ipv6(
	const char*	target_name,
	const HaveIpv6CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetUnicastForwardingEnabled4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Test whether the IPv4 unicast forwarding engine is enabled or disabled
     *  to forward packets.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_unicast_forwarding_enabled4(
	const char*	target_name,
	const GetUnicastForwardingEnabled4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetUnicastForwardingEnabled6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Test whether the IPv6 unicast forwarding engine is enabled or disabled
     *  to forward packets.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_unicast_forwarding_enabled6(
	const char*	target_name,
	const GetUnicastForwardingEnabled6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetUnicastForwardingEnabled4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the IPv4 unicast forwarding engine to enable or disable forwarding
     *  of packets.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param enabled if true, then enable IPv4 unicast forwarding, otherwise
     *  disable it.
     */
    bool send_set_unicast_forwarding_enabled4(
	const char*	target_name,
	const bool&	enabled,
	const SetUnicastForwardingEnabled4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetUnicastForwardingEnabled6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the IPv6 unicast forwarding engine to enable or disable forwarding
     *  of packets.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param enabled if true, then enable IPv6 unicast forwarding, otherwise
     *  disable it.
     */
    bool send_set_unicast_forwarding_enabled6(
	const char*	target_name,
	const bool&	enabled,
	const SetUnicastForwardingEnabled6CB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_lookup_route_by_dest4(
	const XrlError&	e,
	XrlArgs*	a,
	LookupRouteByDest4CB		cb
    );

    void unmarshall_lookup_route_by_dest6(
	const XrlError&	e,
	XrlArgs*	a,
	LookupRouteByDest6CB		cb
    );

    void unmarshall_lookup_route_by_network4(
	const XrlError&	e,
	XrlArgs*	a,
	LookupRouteByNetwork4CB		cb
    );

    void unmarshall_lookup_route_by_network6(
	const XrlError&	e,
	XrlArgs*	a,
	LookupRouteByNetwork6CB		cb
    );

    void unmarshall_have_ipv4(
	const XrlError&	e,
	XrlArgs*	a,
	HaveIpv4CB		cb
    );

    void unmarshall_have_ipv6(
	const XrlError&	e,
	XrlArgs*	a,
	HaveIpv6CB		cb
    );

    void unmarshall_get_unicast_forwarding_enabled4(
	const XrlError&	e,
	XrlArgs*	a,
	GetUnicastForwardingEnabled4CB		cb
    );

    void unmarshall_get_unicast_forwarding_enabled6(
	const XrlError&	e,
	XrlArgs*	a,
	GetUnicastForwardingEnabled6CB		cb
    );

    void unmarshall_set_unicast_forwarding_enabled4(
	const XrlError&	e,
	XrlArgs*	a,
	SetUnicastForwardingEnabled4CB		cb
    );

    void unmarshall_set_unicast_forwarding_enabled6(
	const XrlError&	e,
	XrlArgs*	a,
	SetUnicastForwardingEnabled6CB		cb
    );

};

#endif /* __XRL_INTERFACES_FTI_XIF_HH__ */
