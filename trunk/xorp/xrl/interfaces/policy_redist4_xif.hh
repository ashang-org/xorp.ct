/*
 * Copyright (c) 2001-2006 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/policy_redist4_xif.hh,v 1.3 2005/03/25 02:54:52 pavlin Exp $
 */

#ifndef __XRL_INTERFACES_POLICY_REDIST4_XIF_HH__
#define __XRL_INTERFACES_POLICY_REDIST4_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifPolicyRedist4"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlPolicyRedist4V0p1Client {
public:
    XrlPolicyRedist4V0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlPolicyRedist4V0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddRoute4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Start route redistribution for an IPv4 route.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param network the route to advertise.
     *
     *  @param unicast whether the route is unicast.
     *
     *  @param multicast whether the route is multicast.
     *
     *  @param nexthop the nexthop of the route.
     *
     *  @param metric the metric of the route.
     *
     *  @param policytags the set of policy-tags associated with the route.
     */
    bool send_add_route4(
	const char*	target_name,
	const IPv4Net&	network,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4&	nexthop,
	const uint32_t&	metric,
	const XrlAtomList&	policytags,
	const AddRoute4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteRoute4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Terminate route redistribution for an IPv4 route.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param network the route for which advertisements should cease.
     *
     *  @param unicast whether the route is unicast.
     *
     *  @param multicast whether the route is multicast.
     */
    bool send_delete_route4(
	const char*	target_name,
	const IPv4Net&	network,
	const bool&	unicast,
	const bool&	multicast,
	const DeleteRoute4CB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_add_route4(
	const XrlError&	e,
	XrlArgs*	a,
	AddRoute4CB		cb
    );

    void unmarshall_delete_route4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRoute4CB		cb
    );

};

#endif /* __XRL_INTERFACES_POLICY_REDIST4_XIF_HH__ */
