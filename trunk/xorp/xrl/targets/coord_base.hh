/*
 * Copyright (c) 2001-2006 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/coord_base.hh,v 1.17 2005/03/25 02:55:01 pavlin Exp $
 */


#ifndef __XRL_INTERFACES_COORD_BASE_HH__
#define __XRL_INTERFACES_COORD_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlCoordTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlCoordTargetBase {
protected:
    XrlCmdMap* _cmds;

public:
    /**
     * Constructor.
     *
     * @param cmds an XrlCmdMap that the commands associated with the target
     *		   should be added to.  This is typically the XrlRouter
     *		   associated with the target.
     */
    XrlCoordTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlCoordTargetBase();

    /**
     * Set command map.
     *
     * @param cmds pointer to command map to associate commands with.  This
     * argument is typically a pointer to the XrlRouter associated with the
     * target.
     *
     * @return true on success, false if cmds is null or a command map has
     * already been supplied.
     */
    bool set_command_map(XrlCmdMap* cmds);

    /**
     * Get Xrl instance name associated with command map.
     */
    inline const string& name() const { return _cmds->name(); }

    /**
     * Get version string of instance.
     */
    inline const char* version() const { return "coord/0.0"; }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get name of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_target_name(
	// Output values,
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get version string from Xrl Target
     */
    virtual XrlCmdError common_0_1_get_version(
	// Output values,
	string&	version) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get status of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_status(
	// Output values,
	uint32_t&	status,
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Request clean shutdown of Xrl Target
     */
    virtual XrlCmdError common_0_1_shutdown() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Command to be executed by the coordinating process.
     *
     *  @param command to be sent to the coordinator.
     */
    virtual XrlCmdError coord_0_1_command(
	// Input values,
	const string&	command) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Status, show the state of this peer.
     */
    virtual XrlCmdError coord_0_1_status(
	// Input values,
	const string&	peer,
	// Output values,
	string&	status) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  If there are still any outstanding commands pending will return true.
     *  Can be used to poll the coordinating process to verify that the
     *  previous command has completed.
     */
    virtual XrlCmdError coord_0_1_pending(
	// Output values,
	bool&	pending) = 0;

    virtual XrlCmdError datain_0_1_receive(
	// Input values,
	const string&	peer,
	const uint32_t&	genid,
	const bool&	status,
	const uint32_t&	secs,
	const uint32_t&	micro,
	const vector<uint8_t>&	data) = 0;

    virtual XrlCmdError datain_0_1_error(
	// Input values,
	const string&	peer,
	const uint32_t&	genid,
	const string&	reason) = 0;

    virtual XrlCmdError datain_0_1_closed(
	// Input values,
	const string&	peer,
	const uint32_t&	genid) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_coord_0_1_command(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_coord_0_1_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_coord_0_1_pending(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_datain_0_1_receive(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_datain_0_1_error(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_datain_0_1_closed(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif /* __XRL_INTERFACES_COORD_BASE_HH__ */
