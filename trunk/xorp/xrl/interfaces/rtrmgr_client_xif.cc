/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/rtrmgr_client_xif.cc,v 1.11 2004/12/05 23:48:48 mjh Exp $"

#include "rtrmgr_client_xif.hh"

bool
XrlRtrmgrClientV0p2Client::send_new_config_user(
	const char*	the_tgt,
	const uint32_t&	userid,
	const NewConfigUserCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr_client/0.2/new_config_user");
    x.args().add("userid", userid);
    return _sender->send(x, callback(this, &XrlRtrmgrClientV0p2Client::unmarshall_new_config_user, cb));
}


/* Unmarshall new_config_user */
void
XrlRtrmgrClientV0p2Client::unmarshall_new_config_user(
	const XrlError&	e,
	XrlArgs*	a,
	NewConfigUserCB		cb
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
XrlRtrmgrClientV0p2Client::send_config_change_done(
	const char*	the_tgt,
	const bool&	success,
	const string&	errmsg,
	const ConfigChangeDoneCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr_client/0.2/config_change_done");
    x.args().add("success", success);
    x.args().add("errmsg", errmsg);
    return _sender->send(x, callback(this, &XrlRtrmgrClientV0p2Client::unmarshall_config_change_done, cb));
}


/* Unmarshall config_change_done */
void
XrlRtrmgrClientV0p2Client::unmarshall_config_change_done(
	const XrlError&	e,
	XrlArgs*	a,
	ConfigChangeDoneCB		cb
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
XrlRtrmgrClientV0p2Client::send_config_changed(
	const char*	the_tgt,
	const uint32_t&	userid,
	const string&	deltas,
	const string&	deletions,
	const ConfigChangedCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr_client/0.2/config_changed");
    x.args().add("userid", userid);
    x.args().add("deltas", deltas);
    x.args().add("deletions", deletions);
    return _sender->send(x, callback(this, &XrlRtrmgrClientV0p2Client::unmarshall_config_changed, cb));
}


/* Unmarshall config_changed */
void
XrlRtrmgrClientV0p2Client::unmarshall_config_changed(
	const XrlError&	e,
	XrlArgs*	a,
	ConfigChangedCB		cb
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
XrlRtrmgrClientV0p2Client::send_module_status(
	const char*	the_tgt,
	const string&	modname,
	const uint32_t&	status,
	const ModuleStatusCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr_client/0.2/module_status");
    x.args().add("modname", modname);
    x.args().add("status", status);
    return _sender->send(x, callback(this, &XrlRtrmgrClientV0p2Client::unmarshall_module_status, cb));
}


/* Unmarshall module_status */
void
XrlRtrmgrClientV0p2Client::unmarshall_module_status(
	const XrlError&	e,
	XrlArgs*	a,
	ModuleStatusCB		cb
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
