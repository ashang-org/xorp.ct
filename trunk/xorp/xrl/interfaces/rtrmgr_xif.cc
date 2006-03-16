/*
 * Copyright (c) 2001-2006 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/rtrmgr_xif.cc,v 1.17 2005/08/19 20:09:42 pavlin Exp $"

#include "rtrmgr_xif.hh"

bool
XrlRtrmgrV0p1Client::send_get_pid(
	const char*	the_tgt,
	const GetPidCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/get_pid");
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_get_pid, cb));
}


/* Unmarshall get_pid */
void
XrlRtrmgrV0p1Client::unmarshall_get_pid(
	const XrlError&	e,
	XrlArgs*	a,
	GetPidCB		cb
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
    uint32_t pid;
    try {
	a->get("pid", pid);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &pid);
}

bool
XrlRtrmgrV0p1Client::send_register_client(
	const char*	the_tgt,
	const uint32_t&	userid,
	const string&	clientname,
	const RegisterClientCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/register_client");
    x.args().add("userid", userid);
    x.args().add("clientname", clientname);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_register_client, cb));
}


/* Unmarshall register_client */
void
XrlRtrmgrV0p1Client::unmarshall_register_client(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterClientCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0);
	return;
    } else if (a && a->size() != 3) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(3));
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0);
	return;
    }
    string filename;
    uint32_t pid;
    uint32_t clientid;
    try {
	a->get("filename", filename);
	a->get("pid", pid);
	a->get("clientid", clientid);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0);
	return;
    }
    cb->dispatch(e, &filename, &pid, &clientid);
}

bool
XrlRtrmgrV0p1Client::send_unregister_client(
	const char*	the_tgt,
	const string&	token,
	const UnregisterClientCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/unregister_client");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_unregister_client, cb));
}


/* Unmarshall unregister_client */
void
XrlRtrmgrV0p1Client::unmarshall_unregister_client(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterClientCB		cb
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

bool
XrlRtrmgrV0p1Client::send_authenticate_client(
	const char*	the_tgt,
	const uint32_t&	userid,
	const string&	clientname,
	const string&	token,
	const AuthenticateClientCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/authenticate_client");
    x.args().add("userid", userid);
    x.args().add("clientname", clientname);
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_authenticate_client, cb));
}


/* Unmarshall authenticate_client */
void
XrlRtrmgrV0p1Client::unmarshall_authenticate_client(
	const XrlError&	e,
	XrlArgs*	a,
	AuthenticateClientCB		cb
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

bool
XrlRtrmgrV0p1Client::send_enter_config_mode(
	const char*	the_tgt,
	const string&	token,
	const bool&	exclusive,
	const EnterConfigModeCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/enter_config_mode");
    x.args().add("token", token);
    x.args().add("exclusive", exclusive);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_enter_config_mode, cb));
}


/* Unmarshall enter_config_mode */
void
XrlRtrmgrV0p1Client::unmarshall_enter_config_mode(
	const XrlError&	e,
	XrlArgs*	a,
	EnterConfigModeCB		cb
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

bool
XrlRtrmgrV0p1Client::send_leave_config_mode(
	const char*	the_tgt,
	const string&	token,
	const LeaveConfigModeCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/leave_config_mode");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_leave_config_mode, cb));
}


/* Unmarshall leave_config_mode */
void
XrlRtrmgrV0p1Client::unmarshall_leave_config_mode(
	const XrlError&	e,
	XrlArgs*	a,
	LeaveConfigModeCB		cb
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

bool
XrlRtrmgrV0p1Client::send_get_config_users(
	const char*	the_tgt,
	const string&	token,
	const GetConfigUsersCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/get_config_users");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_get_config_users, cb));
}


/* Unmarshall get_config_users */
void
XrlRtrmgrV0p1Client::unmarshall_get_config_users(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfigUsersCB		cb
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
    XrlAtomList users;
    try {
	a->get("users", users);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &users);
}

bool
XrlRtrmgrV0p1Client::send_get_running_config(
	const char*	the_tgt,
	const string&	token,
	const GetRunningConfigCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/get_running_config");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_get_running_config, cb));
}


/* Unmarshall get_running_config */
void
XrlRtrmgrV0p1Client::unmarshall_get_running_config(
	const XrlError&	e,
	XrlArgs*	a,
	GetRunningConfigCB		cb
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
    bool ready;
    string config;
    try {
	a->get("ready", ready);
	a->get("config", config);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &ready, &config);
}

bool
XrlRtrmgrV0p1Client::send_apply_config_change(
	const char*	the_tgt,
	const string&	token,
	const string&	target,
	const string&	deltas,
	const string&	deletions,
	const ApplyConfigChangeCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/apply_config_change");
    x.args().add("token", token);
    x.args().add("target", target);
    x.args().add("deltas", deltas);
    x.args().add("deletions", deletions);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_apply_config_change, cb));
}


/* Unmarshall apply_config_change */
void
XrlRtrmgrV0p1Client::unmarshall_apply_config_change(
	const XrlError&	e,
	XrlArgs*	a,
	ApplyConfigChangeCB		cb
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

bool
XrlRtrmgrV0p1Client::send_lock_config(
	const char*	the_tgt,
	const string&	token,
	const uint32_t&	timeout,
	const LockConfigCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/lock_config");
    x.args().add("token", token);
    x.args().add("timeout", timeout);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_lock_config, cb));
}


/* Unmarshall lock_config */
void
XrlRtrmgrV0p1Client::unmarshall_lock_config(
	const XrlError&	e,
	XrlArgs*	a,
	LockConfigCB		cb
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
    bool success;
    uint32_t holder;
    try {
	a->get("success", success);
	a->get("holder", holder);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &success, &holder);
}

bool
XrlRtrmgrV0p1Client::send_unlock_config(
	const char*	the_tgt,
	const string&	token,
	const UnlockConfigCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/unlock_config");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_unlock_config, cb));
}


/* Unmarshall unlock_config */
void
XrlRtrmgrV0p1Client::unmarshall_unlock_config(
	const XrlError&	e,
	XrlArgs*	a,
	UnlockConfigCB		cb
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

bool
XrlRtrmgrV0p1Client::send_lock_node(
	const char*	the_tgt,
	const string&	token,
	const string&	node,
	const uint32_t&	timeout,
	const LockNodeCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/lock_node");
    x.args().add("token", token);
    x.args().add("node", node);
    x.args().add("timeout", timeout);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_lock_node, cb));
}


/* Unmarshall lock_node */
void
XrlRtrmgrV0p1Client::unmarshall_lock_node(
	const XrlError&	e,
	XrlArgs*	a,
	LockNodeCB		cb
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
    bool success;
    uint32_t holder;
    try {
	a->get("success", success);
	a->get("holder", holder);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &success, &holder);
}

bool
XrlRtrmgrV0p1Client::send_unlock_node(
	const char*	the_tgt,
	const string&	token,
	const string&	node,
	const UnlockNodeCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/unlock_node");
    x.args().add("token", token);
    x.args().add("node", node);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_unlock_node, cb));
}


/* Unmarshall unlock_node */
void
XrlRtrmgrV0p1Client::unmarshall_unlock_node(
	const XrlError&	e,
	XrlArgs*	a,
	UnlockNodeCB		cb
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

bool
XrlRtrmgrV0p1Client::send_save_config(
	const char*	the_tgt,
	const string&	token,
	const string&	target,
	const string&	filename,
	const SaveConfigCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/save_config");
    x.args().add("token", token);
    x.args().add("target", target);
    x.args().add("filename", filename);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_save_config, cb));
}


/* Unmarshall save_config */
void
XrlRtrmgrV0p1Client::unmarshall_save_config(
	const XrlError&	e,
	XrlArgs*	a,
	SaveConfigCB		cb
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

bool
XrlRtrmgrV0p1Client::send_load_config(
	const char*	the_tgt,
	const string&	token,
	const string&	target,
	const string&	filename,
	const LoadConfigCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/load_config");
    x.args().add("token", token);
    x.args().add("target", target);
    x.args().add("filename", filename);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_load_config, cb));
}


/* Unmarshall load_config */
void
XrlRtrmgrV0p1Client::unmarshall_load_config(
	const XrlError&	e,
	XrlArgs*	a,
	LoadConfigCB		cb
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

bool
XrlRtrmgrV0p1Client::send_set_config_directory(
	const char*	the_tgt,
	const string&	config_directory,
	const SetConfigDirectoryCB&	cb
)
{
    Xrl x(the_tgt, "rtrmgr/0.1/set_config_directory");
    x.args().add("config_directory", config_directory);
    return _sender->send(x, callback(this, &XrlRtrmgrV0p1Client::unmarshall_set_config_directory, cb));
}


/* Unmarshall set_config_directory */
void
XrlRtrmgrV0p1Client::unmarshall_set_config_directory(
	const XrlError&	e,
	XrlArgs*	a,
	SetConfigDirectoryCB		cb
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
