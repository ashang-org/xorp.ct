/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/fea_ifmgr_replicator_xif.cc,v 1.4 2004/06/10 22:41:59 hodson Exp $"

#include "fea_ifmgr_replicator_xif.hh"

bool
XrlIfmgrReplicatorV0p1Client::send_register_ifmgr_mirror(
	const char*	the_tgt,
	const string&	clientname,
	const RegisterIfmgrMirrorCB&	cb
)
{
    Xrl x(the_tgt, "ifmgr_replicator/0.1/register_ifmgr_mirror");
    x.args().add("clientname", clientname);
    return _sender->send(x, callback(this, &XrlIfmgrReplicatorV0p1Client::unmarshall_register_ifmgr_mirror, cb));
}


/* Unmarshall register_ifmgr_mirror */
void
XrlIfmgrReplicatorV0p1Client::unmarshall_register_ifmgr_mirror(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterIfmgrMirrorCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlIfmgrReplicatorV0p1Client::send_unregister_ifmgr_mirror(
	const char*	the_tgt,
	const string&	clientname,
	const UnregisterIfmgrMirrorCB&	cb
)
{
    Xrl x(the_tgt, "ifmgr_replicator/0.1/unregister_ifmgr_mirror");
    x.args().add("clientname", clientname);
    return _sender->send(x, callback(this, &XrlIfmgrReplicatorV0p1Client::unmarshall_unregister_ifmgr_mirror, cb));
}


/* Unmarshall unregister_ifmgr_mirror */
void
XrlIfmgrReplicatorV0p1Client::unmarshall_unregister_ifmgr_mirror(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterIfmgrMirrorCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
