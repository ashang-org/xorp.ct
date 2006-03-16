/*
 * Copyright (c) 2001-2006 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/mld6igmp_client_xif.hh,v 1.12 2005/03/25 02:54:50 pavlin Exp $
 */

#ifndef __XRL_INTERFACES_MLD6IGMP_CLIENT_XIF_HH__
#define __XRL_INTERFACES_MLD6IGMP_CLIENT_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifMld6igmpClient"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlMld6igmpClientV0p1Client {
public:
    XrlMld6igmpClientV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlMld6igmpClientV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddMembership4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Add/delete membership information.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param vif_name the name of the new vif.
     *
     *  @param vif_index the index of the new vif.
     *
     *  @param source the source address that has been joined/left.
     *
     *  @param group the group address that has been joined/left.
     */
    bool send_add_membership4(
	const char*	target_name,
	const string&	xrl_sender_name,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv4&	source,
	const IPv4&	group,
	const AddMembership4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddMembership6CB;

    bool send_add_membership6(
	const char*	target_name,
	const string&	xrl_sender_name,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv6&	source,
	const IPv6&	group,
	const AddMembership6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteMembership4CB;

    bool send_delete_membership4(
	const char*	target_name,
	const string&	xrl_sender_name,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv4&	source,
	const IPv4&	group,
	const DeleteMembership4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteMembership6CB;

    bool send_delete_membership6(
	const char*	target_name,
	const string&	xrl_sender_name,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv6&	source,
	const IPv6&	group,
	const DeleteMembership6CB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_add_membership4(
	const XrlError&	e,
	XrlArgs*	a,
	AddMembership4CB		cb
    );

    void unmarshall_add_membership6(
	const XrlError&	e,
	XrlArgs*	a,
	AddMembership6CB		cb
    );

    void unmarshall_delete_membership4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteMembership4CB		cb
    );

    void unmarshall_delete_membership6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteMembership6CB		cb
    );

};

#endif /* __XRL_INTERFACES_MLD6IGMP_CLIENT_XIF_HH__ */
