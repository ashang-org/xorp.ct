/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/tgt-gen'.
 */

#ident "$XORP: xorp/xrl/targets/finder_client_base.cc,v 1.1 2002/08/02 22:58:51 hodson Exp $"


#include "finder_client_base.hh"

const XrlCmdError
XrlFinderclientTargetBase::handle_common_0_1_get_target_name(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%d != 0) handling common/0.1/get_target_name", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string name; 
    try {
	XrlCmdError e = common_0_1_get_target_name(
	    name);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for common/0.1/get_target_name failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("name", name);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlFinderclientTargetBase::handle_common_0_1_get_version(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%d != 0) handling common/0.1/get_version", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string version; 
    try {
	XrlCmdError e = common_0_1_get_version(
	    version);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for common/0.1/get_version failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("version", version);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlFinderclientTargetBase::handle_finder_client_0_1_hello(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%d != 0) handling finder_client/0.1/hello", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_client_0_1_hello();
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for finder_client/0.1/hello failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlFinderclientTargetBase::handle_finder_client_0_1_remove_xrl_from_cache(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%d != 1) handling finder_client/0.1/remove_xrl_from_cache", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_client_0_1_remove_xrl_from_cache(
	    xrl.const_args().get_string("xrl"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for finder_client/0.1/remove_xrl_from_cache failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlFinderclientTargetBase::handle_finder_client_0_1_remove_xrls_for_target_from_cache(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%d != 1) handling finder_client/0.1/remove_xrls_for_target_from_cache", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = finder_client_0_1_remove_xrls_for_target_from_cache(
	    xrl.const_args().get_string("target_name"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for finder_client/0.1/remove_xrls_for_target_from_cache failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

