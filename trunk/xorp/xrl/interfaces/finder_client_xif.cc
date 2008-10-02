/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See the XORP LICENSE.lgpl file for licensing, conditions, and warranties
 * on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/finder_client_xif.cc,v 1.23 2008/09/23 08:13:18 abittau Exp $"

#include "finder_client_xif.hh"

bool
XrlFinderClientV0p2Client::send_hello(
	const char*	dst_xrl_target_name,
	const HelloCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "finder_client/0.2/hello");
    }

    x->set_target(dst_xrl_target_name);


    return _sender->send(*x, callback(this, &XrlFinderClientV0p2Client::unmarshall_hello, cb));
}


/* Unmarshall hello */
void
XrlFinderClientV0p2Client::unmarshall_hello(
	const XrlError&	e,
	XrlArgs*	a,
	HelloCB		cb
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
XrlFinderClientV0p2Client::send_remove_xrl_from_cache(
	const char*	dst_xrl_target_name,
	const string&	xrl,
	const RemoveXrlFromCacheCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "finder_client/0.2/remove_xrl_from_cache");
        x->args().add(XrlAtom(xrl));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, xrl);

    return _sender->send(*x, callback(this, &XrlFinderClientV0p2Client::unmarshall_remove_xrl_from_cache, cb));
}


/* Unmarshall remove_xrl_from_cache */
void
XrlFinderClientV0p2Client::unmarshall_remove_xrl_from_cache(
	const XrlError&	e,
	XrlArgs*	a,
	RemoveXrlFromCacheCB		cb
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
XrlFinderClientV0p2Client::send_remove_xrls_for_target_from_cache(
	const char*	dst_xrl_target_name,
	const string&	target_name,
	const RemoveXrlsForTargetFromCacheCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "finder_client/0.2/remove_xrls_for_target_from_cache");
        x->args().add(XrlAtom(target_name));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, target_name);

    return _sender->send(*x, callback(this, &XrlFinderClientV0p2Client::unmarshall_remove_xrls_for_target_from_cache, cb));
}


/* Unmarshall remove_xrls_for_target_from_cache */
void
XrlFinderClientV0p2Client::unmarshall_remove_xrls_for_target_from_cache(
	const XrlError&	e,
	XrlArgs*	a,
	RemoveXrlsForTargetFromCacheCB		cb
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
XrlFinderClientV0p2Client::send_dispatch_tunneled_xrl(
	const char*	dst_xrl_target_name,
	const string&	xrl,
	const DispatchTunneledXrlCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "finder_client/0.2/dispatch_tunneled_xrl");
        x->args().add(XrlAtom(xrl));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, xrl);

    return _sender->send(*x, callback(this, &XrlFinderClientV0p2Client::unmarshall_dispatch_tunneled_xrl, cb));
}


/* Unmarshall dispatch_tunneled_xrl */
void
XrlFinderClientV0p2Client::unmarshall_dispatch_tunneled_xrl(
	const XrlError&	e,
	XrlArgs*	a,
	DispatchTunneledXrlCB		cb
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
    uint32_t xrl_error;
    string xrl_error_note;
    try {
	a->get("xrl_error", xrl_error);
	a->get("xrl_error_note", xrl_error_note);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &xrl_error, &xrl_error_note);
}
