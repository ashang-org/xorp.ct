/*
 * Copyright (c) 2001-2006 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/common_xif.cc,v 1.15 2005/03/25 02:54:44 pavlin Exp $"

#include "common_xif.hh"

bool
XrlCommonV0p1Client::send_get_target_name(
	const char*	the_tgt,
	const GetTargetNameCB&	cb
)
{
    Xrl x(the_tgt, "common/0.1/get_target_name");
    return _sender->send(x, callback(this, &XrlCommonV0p1Client::unmarshall_get_target_name, cb));
}


/* Unmarshall get_target_name */
void
XrlCommonV0p1Client::unmarshall_get_target_name(
	const XrlError&	e,
	XrlArgs*	a,
	GetTargetNameCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string name;
    try {
	a->get("name", name);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &name);
}

bool
XrlCommonV0p1Client::send_get_version(
	const char*	the_tgt,
	const GetVersionCB&	cb
)
{
    Xrl x(the_tgt, "common/0.1/get_version");
    return _sender->send(x, callback(this, &XrlCommonV0p1Client::unmarshall_get_version, cb));
}


/* Unmarshall get_version */
void
XrlCommonV0p1Client::unmarshall_get_version(
	const XrlError&	e,
	XrlArgs*	a,
	GetVersionCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string version;
    try {
	a->get("version", version);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &version);
}

bool
XrlCommonV0p1Client::send_get_status(
	const char*	the_tgt,
	const GetStatusCB&	cb
)
{
    Xrl x(the_tgt, "common/0.1/get_status");
    return _sender->send(x, callback(this, &XrlCommonV0p1Client::unmarshall_get_status, cb));
}


/* Unmarshall get_status */
void
XrlCommonV0p1Client::unmarshall_get_status(
	const XrlError&	e,
	XrlArgs*	a,
	GetStatusCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(2));
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    uint32_t status;
    string reason;
    try {
	a->get("status", status);
	a->get("reason", reason);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &status, &reason);
}

bool
XrlCommonV0p1Client::send_shutdown(
	const char*	the_tgt,
	const ShutdownCB&	cb
)
{
    Xrl x(the_tgt, "common/0.1/shutdown");
    return _sender->send(x, callback(this, &XrlCommonV0p1Client::unmarshall_shutdown, cb));
}


/* Unmarshall shutdown */
void
XrlCommonV0p1Client::unmarshall_shutdown(
	const XrlError&	e,
	XrlArgs*	a,
	ShutdownCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
