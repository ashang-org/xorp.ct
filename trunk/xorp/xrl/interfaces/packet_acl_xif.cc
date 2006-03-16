/*
 * Copyright (c) 2001-2006 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/packet_acl_xif.cc,v 1.4 2005/03/25 02:54:51 pavlin Exp $"

#include "packet_acl_xif.hh"

bool
XrlPacketAclV0p1Client::send_get_backend(
	const char*	the_tgt,
	const GetBackendCB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/get_backend");
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_get_backend, cb));
}


/* Unmarshall get_backend */
void
XrlPacketAclV0p1Client::unmarshall_get_backend(
	const XrlError&	e,
	XrlArgs*	a,
	GetBackendCB		cb
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
XrlPacketAclV0p1Client::send_set_backend(
	const char*	the_tgt,
	const string&	name,
	const SetBackendCB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/set_backend");
    x.args().add("name", name);
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_set_backend, cb));
}


/* Unmarshall set_backend */
void
XrlPacketAclV0p1Client::unmarshall_set_backend(
	const XrlError&	e,
	XrlArgs*	a,
	SetBackendCB		cb
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
XrlPacketAclV0p1Client::send_get_version(
	const char*	the_tgt,
	const GetVersionCB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/get_version");
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_get_version, cb));
}


/* Unmarshall get_version */
void
XrlPacketAclV0p1Client::unmarshall_get_version(
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
XrlPacketAclV0p1Client::send_start_transaction(
	const char*	the_tgt,
	const StartTransactionCB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/start_transaction");
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_start_transaction, cb));
}


/* Unmarshall start_transaction */
void
XrlPacketAclV0p1Client::unmarshall_start_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	StartTransactionCB		cb
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
    uint32_t tid;
    try {
	a->get("tid", tid);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &tid);
}

bool
XrlPacketAclV0p1Client::send_commit_transaction(
	const char*	the_tgt,
	const uint32_t&	tid,
	const CommitTransactionCB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/commit_transaction");
    x.args().add("tid", tid);
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_commit_transaction, cb));
}


/* Unmarshall commit_transaction */
void
XrlPacketAclV0p1Client::unmarshall_commit_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	CommitTransactionCB		cb
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
XrlPacketAclV0p1Client::send_abort_transaction(
	const char*	the_tgt,
	const uint32_t&	tid,
	const AbortTransactionCB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/abort_transaction");
    x.args().add("tid", tid);
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_abort_transaction, cb));
}


/* Unmarshall abort_transaction */
void
XrlPacketAclV0p1Client::unmarshall_abort_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	AbortTransactionCB		cb
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
XrlPacketAclV0p1Client::send_add_entry4(
	const char*	the_tgt,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vifname,
	const IPv4Net&	src,
	const IPv4Net&	dst,
	const uint32_t&	proto,
	const uint32_t&	sport,
	const uint32_t&	dport,
	const string&	action,
	const AddEntry4CB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/add_entry4");
    x.args().add("tid", tid);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("src", src);
    x.args().add("dst", dst);
    x.args().add("proto", proto);
    x.args().add("sport", sport);
    x.args().add("dport", dport);
    x.args().add("action", action);
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_add_entry4, cb));
}


/* Unmarshall add_entry4 */
void
XrlPacketAclV0p1Client::unmarshall_add_entry4(
	const XrlError&	e,
	XrlArgs*	a,
	AddEntry4CB		cb
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
XrlPacketAclV0p1Client::send_delete_entry4(
	const char*	the_tgt,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vifname,
	const IPv4Net&	src,
	const IPv4Net&	dst,
	const uint32_t&	proto,
	const uint32_t&	sport,
	const uint32_t&	dport,
	const DeleteEntry4CB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/delete_entry4");
    x.args().add("tid", tid);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("src", src);
    x.args().add("dst", dst);
    x.args().add("proto", proto);
    x.args().add("sport", sport);
    x.args().add("dport", dport);
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_delete_entry4, cb));
}


/* Unmarshall delete_entry4 */
void
XrlPacketAclV0p1Client::unmarshall_delete_entry4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteEntry4CB		cb
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
XrlPacketAclV0p1Client::send_delete_all_entries4(
	const char*	the_tgt,
	const uint32_t&	tid,
	const DeleteAllEntries4CB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/delete_all_entries4");
    x.args().add("tid", tid);
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_delete_all_entries4, cb));
}


/* Unmarshall delete_all_entries4 */
void
XrlPacketAclV0p1Client::unmarshall_delete_all_entries4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAllEntries4CB		cb
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
XrlPacketAclV0p1Client::send_add_entry6(
	const char*	the_tgt,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vifname,
	const IPv6Net&	src,
	const IPv6Net&	dst,
	const uint32_t&	proto,
	const uint32_t&	sport,
	const uint32_t&	dport,
	const string&	action,
	const AddEntry6CB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/add_entry6");
    x.args().add("tid", tid);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("src", src);
    x.args().add("dst", dst);
    x.args().add("proto", proto);
    x.args().add("sport", sport);
    x.args().add("dport", dport);
    x.args().add("action", action);
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_add_entry6, cb));
}


/* Unmarshall add_entry6 */
void
XrlPacketAclV0p1Client::unmarshall_add_entry6(
	const XrlError&	e,
	XrlArgs*	a,
	AddEntry6CB		cb
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
XrlPacketAclV0p1Client::send_delete_entry6(
	const char*	the_tgt,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vifname,
	const IPv6Net&	src,
	const IPv6Net&	dst,
	const uint32_t&	proto,
	const uint32_t&	sport,
	const uint32_t&	dport,
	const DeleteEntry6CB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/delete_entry6");
    x.args().add("tid", tid);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("src", src);
    x.args().add("dst", dst);
    x.args().add("proto", proto);
    x.args().add("sport", sport);
    x.args().add("dport", dport);
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_delete_entry6, cb));
}


/* Unmarshall delete_entry6 */
void
XrlPacketAclV0p1Client::unmarshall_delete_entry6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteEntry6CB		cb
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
XrlPacketAclV0p1Client::send_delete_all_entries6(
	const char*	the_tgt,
	const uint32_t&	tid,
	const DeleteAllEntries6CB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/delete_all_entries6");
    x.args().add("tid", tid);
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_delete_all_entries6, cb));
}


/* Unmarshall delete_all_entries6 */
void
XrlPacketAclV0p1Client::unmarshall_delete_all_entries6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAllEntries6CB		cb
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
XrlPacketAclV0p1Client::send_get_entry_list_start4(
	const char*	the_tgt,
	const GetEntryListStart4CB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/get_entry_list_start4");
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_get_entry_list_start4, cb));
}


/* Unmarshall get_entry_list_start4 */
void
XrlPacketAclV0p1Client::unmarshall_get_entry_list_start4(
	const XrlError&	e,
	XrlArgs*	a,
	GetEntryListStart4CB		cb
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
    uint32_t token;
    bool more;
    try {
	a->get("token", token);
	a->get("more", more);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &token, &more);
}

bool
XrlPacketAclV0p1Client::send_get_entry_list_next4(
	const char*	the_tgt,
	const uint32_t&	token,
	const GetEntryListNext4CB&	cb
)
{
    Xrl x(the_tgt, "packet_acl/0.1/get_entry_list_next4");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlPacketAclV0p1Client::unmarshall_get_entry_list_next4, cb));
}


/* Unmarshall get_entry_list_next4 */
void
XrlPacketAclV0p1Client::unmarshall_get_entry_list_next4(
	const XrlError&	e,
	XrlArgs*	a,
	GetEntryListNext4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 9) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(9));
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    string ifname;
    string vifname;
    IPv4Net src;
    IPv4Net dst;
    uint32_t proto;
    uint32_t sport;
    uint32_t dport;
    string action;
    bool more;
    try {
	a->get("ifname", ifname);
	a->get("vifname", vifname);
	a->get("src", src);
	a->get("dst", dst);
	a->get("proto", proto);
	a->get("sport", sport);
	a->get("dport", dport);
	a->get("action", action);
	a->get("more", more);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &ifname, &vifname, &src, &dst, &proto, &sport, &dport, &action, &more);
}
