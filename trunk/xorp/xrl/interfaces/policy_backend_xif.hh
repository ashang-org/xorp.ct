/*
 * Copyright (c) 2001-2006 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/policy_backend_xif.hh,v 1.3 2005/03/25 02:54:52 pavlin Exp $
 */

#ifndef __XRL_INTERFACES_POLICY_BACKEND_XIF_HH__
#define __XRL_INTERFACES_POLICY_BACKEND_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifPolicyBackend"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlPolicyBackendV0p1Client {
public:
    XrlPolicyBackendV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlPolicyBackendV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr ConfigureCB;
    /**
     *  Send Xrl intended to:
     *
     *  Configure a policy filter.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param filter the identifier of the filter to configure.
     *
     *  @param conf the configuration of the filter.
     */
    bool send_configure(
	const char*	target_name,
	const uint32_t&	filter,
	const string&	conf,
	const ConfigureCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ResetCB;
    /**
     *  Send Xrl intended to:
     *
     *  Reset a policy filter.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param filter the identifier of the filter to reset.
     */
    bool send_reset(
	const char*	target_name,
	const uint32_t&	filter,
	const ResetCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr PushRoutesCB;
    /**
     *  Send Xrl intended to:
     *
     *  Push all available routes through all filters for re-filtering.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_push_routes(
	const char*	target_name,
	const PushRoutesCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_configure(
	const XrlError&	e,
	XrlArgs*	a,
	ConfigureCB		cb
    );

    void unmarshall_reset(
	const XrlError&	e,
	XrlArgs*	a,
	ResetCB		cb
    );

    void unmarshall_push_routes(
	const XrlError&	e,
	XrlArgs*	a,
	PushRoutesCB		cb
    );

};

#endif /* __XRL_INTERFACES_POLICY_BACKEND_XIF_HH__ */
