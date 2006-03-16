/*
 * Copyright (c) 2001-2006 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/static_routes_xif.cc,v 1.7 2005/03/25 02:54:56 pavlin Exp $"

#include "static_routes_xif.hh"

bool
XrlStaticRoutesV0p1Client::send_enable_static_routes(
	const char*	the_tgt,
	const bool&	enable,
	const EnableStaticRoutesCB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/enable_static_routes");
    x.args().add("enable", enable);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_enable_static_routes, cb));
}


/* Unmarshall enable_static_routes */
void
XrlStaticRoutesV0p1Client::unmarshall_enable_static_routes(
	const XrlError&	e,
	XrlArgs*	a,
	EnableStaticRoutesCB		cb
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
XrlStaticRoutesV0p1Client::send_start_static_routes(
	const char*	the_tgt,
	const StartStaticRoutesCB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/start_static_routes");
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_start_static_routes, cb));
}


/* Unmarshall start_static_routes */
void
XrlStaticRoutesV0p1Client::unmarshall_start_static_routes(
	const XrlError&	e,
	XrlArgs*	a,
	StartStaticRoutesCB		cb
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
XrlStaticRoutesV0p1Client::send_stop_static_routes(
	const char*	the_tgt,
	const StopStaticRoutesCB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/stop_static_routes");
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_stop_static_routes, cb));
}


/* Unmarshall stop_static_routes */
void
XrlStaticRoutesV0p1Client::unmarshall_stop_static_routes(
	const XrlError&	e,
	XrlArgs*	a,
	StopStaticRoutesCB		cb
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
XrlStaticRoutesV0p1Client::send_add_route4(
	const char*	the_tgt,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	metric,
	const AddRoute4CB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/add_route4");
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_add_route4, cb));
}


/* Unmarshall add_route4 */
void
XrlStaticRoutesV0p1Client::unmarshall_add_route4(
	const XrlError&	e,
	XrlArgs*	a,
	AddRoute4CB		cb
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
XrlStaticRoutesV0p1Client::send_add_route6(
	const char*	the_tgt,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	metric,
	const AddRoute6CB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/add_route6");
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_add_route6, cb));
}


/* Unmarshall add_route6 */
void
XrlStaticRoutesV0p1Client::unmarshall_add_route6(
	const XrlError&	e,
	XrlArgs*	a,
	AddRoute6CB		cb
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
XrlStaticRoutesV0p1Client::send_replace_route4(
	const char*	the_tgt,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	metric,
	const ReplaceRoute4CB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/replace_route4");
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_replace_route4, cb));
}


/* Unmarshall replace_route4 */
void
XrlStaticRoutesV0p1Client::unmarshall_replace_route4(
	const XrlError&	e,
	XrlArgs*	a,
	ReplaceRoute4CB		cb
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
XrlStaticRoutesV0p1Client::send_replace_route6(
	const char*	the_tgt,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	metric,
	const ReplaceRoute6CB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/replace_route6");
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_replace_route6, cb));
}


/* Unmarshall replace_route6 */
void
XrlStaticRoutesV0p1Client::unmarshall_replace_route6(
	const XrlError&	e,
	XrlArgs*	a,
	ReplaceRoute6CB		cb
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
XrlStaticRoutesV0p1Client::send_delete_route4(
	const char*	the_tgt,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const DeleteRoute4CB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/delete_route4");
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_delete_route4, cb));
}


/* Unmarshall delete_route4 */
void
XrlStaticRoutesV0p1Client::unmarshall_delete_route4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRoute4CB		cb
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
XrlStaticRoutesV0p1Client::send_delete_route6(
	const char*	the_tgt,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const DeleteRoute6CB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/delete_route6");
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_delete_route6, cb));
}


/* Unmarshall delete_route6 */
void
XrlStaticRoutesV0p1Client::unmarshall_delete_route6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRoute6CB		cb
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
XrlStaticRoutesV0p1Client::send_add_interface_route4(
	const char*	the_tgt,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const AddInterfaceRoute4CB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/add_interface_route4");
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_add_interface_route4, cb));
}


/* Unmarshall add_interface_route4 */
void
XrlStaticRoutesV0p1Client::unmarshall_add_interface_route4(
	const XrlError&	e,
	XrlArgs*	a,
	AddInterfaceRoute4CB		cb
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
XrlStaticRoutesV0p1Client::send_add_interface_route6(
	const char*	the_tgt,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const AddInterfaceRoute6CB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/add_interface_route6");
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_add_interface_route6, cb));
}


/* Unmarshall add_interface_route6 */
void
XrlStaticRoutesV0p1Client::unmarshall_add_interface_route6(
	const XrlError&	e,
	XrlArgs*	a,
	AddInterfaceRoute6CB		cb
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
XrlStaticRoutesV0p1Client::send_replace_interface_route4(
	const char*	the_tgt,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const ReplaceInterfaceRoute4CB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/replace_interface_route4");
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_replace_interface_route4, cb));
}


/* Unmarshall replace_interface_route4 */
void
XrlStaticRoutesV0p1Client::unmarshall_replace_interface_route4(
	const XrlError&	e,
	XrlArgs*	a,
	ReplaceInterfaceRoute4CB		cb
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
XrlStaticRoutesV0p1Client::send_replace_interface_route6(
	const char*	the_tgt,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const ReplaceInterfaceRoute6CB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/replace_interface_route6");
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_replace_interface_route6, cb));
}


/* Unmarshall replace_interface_route6 */
void
XrlStaticRoutesV0p1Client::unmarshall_replace_interface_route6(
	const XrlError&	e,
	XrlArgs*	a,
	ReplaceInterfaceRoute6CB		cb
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
XrlStaticRoutesV0p1Client::send_enable_log_trace_all(
	const char*	the_tgt,
	const bool&	enable,
	const EnableLogTraceAllCB&	cb
)
{
    Xrl x(the_tgt, "static_routes/0.1/enable_log_trace_all");
    x.args().add("enable", enable);
    return _sender->send(x, callback(this, &XrlStaticRoutesV0p1Client::unmarshall_enable_log_trace_all, cb));
}


/* Unmarshall enable_log_trace_all */
void
XrlStaticRoutesV0p1Client::unmarshall_enable_log_trace_all(
	const XrlError&	e,
	XrlArgs*	a,
	EnableLogTraceAllCB		cb
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
