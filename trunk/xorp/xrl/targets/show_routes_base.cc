/*
 * Copyright (c) 2001-2006 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 */

#ident "$XORP: xorp/xrl/targets/show_routes_base.cc,v 1.7 2005/10/27 05:05:42 pavlin Exp $"


#include "show_routes_base.hh"


XrlShowRoutesTargetBase::XrlShowRoutesTargetBase(XrlCmdMap* cmds)
    : _cmds(cmds)
{
    if (_cmds)
	add_handlers();
}

XrlShowRoutesTargetBase::~XrlShowRoutesTargetBase()
{
    if (_cmds)
	remove_handlers();
}

bool
XrlShowRoutesTargetBase::set_command_map(XrlCmdMap* cmds)
{
    if (_cmds == 0 && cmds) {
        _cmds = cmds;
        add_handlers();
        return true;
    }
    if (_cmds && cmds == 0) {
	remove_handlers();
        _cmds = cmds;
        return true;
    }
    return false;
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_common_0_1_get_target_name(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/get_target_name");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string name;
    try {
	XrlCmdError e = common_0_1_get_target_name(
	    name);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/get_target_name", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("name", name);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_common_0_1_get_version(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/get_version");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string version;
    try {
	XrlCmdError e = common_0_1_get_version(
	    version);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/get_version", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("version", version);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_common_0_1_get_status(const XrlArgs& xa_inputs, XrlArgs* pxa_outputs)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/get_status");
	return XrlCmdError::BAD_ARGS();
    }

    if (pxa_outputs == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t status;
    string reason;
    try {
	XrlCmdError e = common_0_1_get_status(
	    status,
	    reason);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/get_status", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	pxa_outputs->add("status", status);
	pxa_outputs->add("reason", reason);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_common_0_1_shutdown(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(0), XORP_UINT_CAST(xa_inputs.size()), "common/0.1/shutdown");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = common_0_1_shutdown();
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "common/0.1/shutdown", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_finder_event_observer_0_1_xrl_target_birth(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "finder_event_observer/0.1/xrl_target_birth");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_event_observer_0_1_xrl_target_birth(
	    xa_inputs.get_string("target_class"),
	    xa_inputs.get_string("target_instance"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "finder_event_observer/0.1/xrl_target_birth", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_finder_event_observer_0_1_xrl_target_death(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(2), XORP_UINT_CAST(xa_inputs.size()), "finder_event_observer/0.1/xrl_target_death");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_event_observer_0_1_xrl_target_death(
	    xa_inputs.get_string("target_class"),
	    xa_inputs.get_string("target_instance"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "finder_event_observer/0.1/xrl_target_death", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist4_0_1_add_route(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 8) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(8), XORP_UINT_CAST(xa_inputs.size()), "redist4/0.1/add_route");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist4_0_1_add_route(
	    xa_inputs.get_ipv4net("dst"),
	    xa_inputs.get_ipv4("nexthop"),
	    xa_inputs.get_string("ifname"),
	    xa_inputs.get_string("vifname"),
	    xa_inputs.get_uint32("metric"),
	    xa_inputs.get_uint32("admin_distance"),
	    xa_inputs.get_string("cookie"),
	    xa_inputs.get_string("protocol_origin"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist4/0.1/add_route", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist4_0_1_delete_route(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 3) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(3), XORP_UINT_CAST(xa_inputs.size()), "redist4/0.1/delete_route");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist4_0_1_delete_route(
	    xa_inputs.get_ipv4net("network"),
	    xa_inputs.get_string("cookie"),
	    xa_inputs.get_string("protocol_origin"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist4/0.1/delete_route", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist4_0_1_starting_route_dump(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "redist4/0.1/starting_route_dump");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist4_0_1_starting_route_dump(
	    xa_inputs.get_string("cookie"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist4/0.1/starting_route_dump", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist4_0_1_finishing_route_dump(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "redist4/0.1/finishing_route_dump");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist4_0_1_finishing_route_dump(
	    xa_inputs.get_string("cookie"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist4/0.1/finishing_route_dump", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist6_0_1_add_route(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 8) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(8), XORP_UINT_CAST(xa_inputs.size()), "redist6/0.1/add_route");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist6_0_1_add_route(
	    xa_inputs.get_ipv6net("dst"),
	    xa_inputs.get_ipv6("nexthop"),
	    xa_inputs.get_string("ifname"),
	    xa_inputs.get_string("vifname"),
	    xa_inputs.get_uint32("metric"),
	    xa_inputs.get_uint32("admin_distance"),
	    xa_inputs.get_string("cookie"),
	    xa_inputs.get_string("protocol_origin"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist6/0.1/add_route", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist6_0_1_delete_route(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 3) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(3), XORP_UINT_CAST(xa_inputs.size()), "redist6/0.1/delete_route");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist6_0_1_delete_route(
	    xa_inputs.get_ipv6net("network"),
	    xa_inputs.get_string("cookie"),
	    xa_inputs.get_string("protocol_origin"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist6/0.1/delete_route", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist6_0_1_starting_route_dump(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "redist6/0.1/starting_route_dump");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist6_0_1_starting_route_dump(
	    xa_inputs.get_string("cookie"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist6/0.1/starting_route_dump", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlShowRoutesTargetBase::handle_redist6_0_1_finishing_route_dump(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            XORP_UINT_CAST(1), XORP_UINT_CAST(xa_inputs.size()), "redist6/0.1/finishing_route_dump");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = redist6_0_1_finishing_route_dump(
	    xa_inputs.get_string("cookie"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "redist6/0.1/finishing_route_dump", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

void
XrlShowRoutesTargetBase::add_handlers()
{
	if (_cmds->add_handler("common/0.1/get_target_name",
	    callback(this, &XrlShowRoutesTargetBase::handle_common_0_1_get_target_name)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "common/0.1/get_target_name");
	}
	if (_cmds->add_handler("common/0.1/get_version",
	    callback(this, &XrlShowRoutesTargetBase::handle_common_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "common/0.1/get_version");
	}
	if (_cmds->add_handler("common/0.1/get_status",
	    callback(this, &XrlShowRoutesTargetBase::handle_common_0_1_get_status)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "common/0.1/get_status");
	}
	if (_cmds->add_handler("common/0.1/shutdown",
	    callback(this, &XrlShowRoutesTargetBase::handle_common_0_1_shutdown)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "common/0.1/shutdown");
	}
	if (_cmds->add_handler("finder_event_observer/0.1/xrl_target_birth",
	    callback(this, &XrlShowRoutesTargetBase::handle_finder_event_observer_0_1_xrl_target_birth)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "finder_event_observer/0.1/xrl_target_birth");
	}
	if (_cmds->add_handler("finder_event_observer/0.1/xrl_target_death",
	    callback(this, &XrlShowRoutesTargetBase::handle_finder_event_observer_0_1_xrl_target_death)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "finder_event_observer/0.1/xrl_target_death");
	}
	if (_cmds->add_handler("redist4/0.1/add_route",
	    callback(this, &XrlShowRoutesTargetBase::handle_redist4_0_1_add_route)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "redist4/0.1/add_route");
	}
	if (_cmds->add_handler("redist4/0.1/delete_route",
	    callback(this, &XrlShowRoutesTargetBase::handle_redist4_0_1_delete_route)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "redist4/0.1/delete_route");
	}
	if (_cmds->add_handler("redist4/0.1/starting_route_dump",
	    callback(this, &XrlShowRoutesTargetBase::handle_redist4_0_1_starting_route_dump)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "redist4/0.1/starting_route_dump");
	}
	if (_cmds->add_handler("redist4/0.1/finishing_route_dump",
	    callback(this, &XrlShowRoutesTargetBase::handle_redist4_0_1_finishing_route_dump)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "redist4/0.1/finishing_route_dump");
	}
	if (_cmds->add_handler("redist6/0.1/add_route",
	    callback(this, &XrlShowRoutesTargetBase::handle_redist6_0_1_add_route)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "redist6/0.1/add_route");
	}
	if (_cmds->add_handler("redist6/0.1/delete_route",
	    callback(this, &XrlShowRoutesTargetBase::handle_redist6_0_1_delete_route)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "redist6/0.1/delete_route");
	}
	if (_cmds->add_handler("redist6/0.1/starting_route_dump",
	    callback(this, &XrlShowRoutesTargetBase::handle_redist6_0_1_starting_route_dump)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "redist6/0.1/starting_route_dump");
	}
	if (_cmds->add_handler("redist6/0.1/finishing_route_dump",
	    callback(this, &XrlShowRoutesTargetBase::handle_redist6_0_1_finishing_route_dump)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "show_routes", "redist6/0.1/finishing_route_dump");
	}
	_cmds->finalize();
}

void
XrlShowRoutesTargetBase::remove_handlers()
{
	_cmds->remove_handler("common/0.1/get_target_name");
	_cmds->remove_handler("common/0.1/get_version");
	_cmds->remove_handler("common/0.1/get_status");
	_cmds->remove_handler("common/0.1/shutdown");
	_cmds->remove_handler("finder_event_observer/0.1/xrl_target_birth");
	_cmds->remove_handler("finder_event_observer/0.1/xrl_target_death");
	_cmds->remove_handler("redist4/0.1/add_route");
	_cmds->remove_handler("redist4/0.1/delete_route");
	_cmds->remove_handler("redist4/0.1/starting_route_dump");
	_cmds->remove_handler("redist4/0.1/finishing_route_dump");
	_cmds->remove_handler("redist6/0.1/add_route");
	_cmds->remove_handler("redist6/0.1/delete_route");
	_cmds->remove_handler("redist6/0.1/starting_route_dump");
	_cmds->remove_handler("redist6/0.1/finishing_route_dump");
}
