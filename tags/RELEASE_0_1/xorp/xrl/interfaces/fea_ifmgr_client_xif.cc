/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/fea_ifmgr_client_xif.cc,v 1.2 2002/11/19 19:31:43 hodson Exp $"

#include "fea_ifmgr_client_xif.hh"

bool
XrlFeaIfmgrClientV0p1Client::send_interface_update(
	const char*	the_tgt, 
	const string&	ifname, 
	const uint32_t&	event, 
	const CB0&	cb
)
{
    Xrl x(the_tgt, "fea_ifmgr_client/0.1/interface_update");
    x.args().add("ifname", ifname);
    x.args().add("event", event);
    return _router->send(x, callback(this, &XrlFeaIfmgrClientV0p1Client::unmarshall0, cb));
}


/* Unmarshall interface_update */
void
XrlFeaIfmgrClientV0p1Client::unmarshall0(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB0		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlFeaIfmgrClientV0p1Client::send_vif_update(
	const char*	the_tgt, 
	const string&	ifname, 
	const string&	vifname, 
	const uint32_t&	event, 
	const CB1&	cb
)
{
    Xrl x(the_tgt, "fea_ifmgr_client/0.1/vif_update");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("event", event);
    return _router->send(x, callback(this, &XrlFeaIfmgrClientV0p1Client::unmarshall1, cb));
}


/* Unmarshall vif_update */
void
XrlFeaIfmgrClientV0p1Client::unmarshall1(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB1		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlFeaIfmgrClientV0p1Client::send_vifaddr4_update(
	const char*	the_tgt, 
	const string&	ifname, 
	const string&	vifname, 
	const IPv4&	addr, 
	const uint32_t&	event, 
	const CB2&	cb
)
{
    Xrl x(the_tgt, "fea_ifmgr_client/0.1/vifaddr4_update");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("event", event);
    return _router->send(x, callback(this, &XrlFeaIfmgrClientV0p1Client::unmarshall2, cb));
}


/* Unmarshall vifaddr4_update */
void
XrlFeaIfmgrClientV0p1Client::unmarshall2(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB2		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlFeaIfmgrClientV0p1Client::send_vifaddr6_update(
	const char*	the_tgt, 
	const string&	ifname, 
	const string&	vifname, 
	const IPv6&	addr, 
	const uint32_t&	event, 
	const CB3&	cb
)
{
    Xrl x(the_tgt, "fea_ifmgr_client/0.1/vifaddr6_update");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("event", event);
    return _router->send(x, callback(this, &XrlFeaIfmgrClientV0p1Client::unmarshall3, cb));
}


/* Unmarshall vifaddr6_update */
void
XrlFeaIfmgrClientV0p1Client::unmarshall3(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB3		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
