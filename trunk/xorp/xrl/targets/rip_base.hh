/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/rip_base.hh,v 1.2 2004/02/27 22:14:14 hodson Exp $
 */


#ifndef __XRL_INTERFACES_RIP_BASE_HH__
#define __XRL_INTERFACES_RIP_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlRipTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlRipTargetBase {
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
    XrlRipTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlRipTargetBase();

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
    inline const char* version() const { return "rip/0.0"; }

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
     *  Announce target birth.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_birth(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Announce target death.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_death(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add an address to run RIP process on. The addition of address is not
     *  instantaneous, RIP has to instantiate state in the FEA to send and
     *  receive packets. Once instantiated the address must be explicitly
     *  enabled with set_rip_address_enabled.
     *
     *  @param ifname the interface that owns vif that has address.
     *
     *  @param vifname virtual interface owning address.
     *
     *  @param addr the address to be added.
     */
    virtual XrlCmdError rip_0_1_add_rip_address(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Remove an address RIP process is running on.
     *
     *  @param ifname the interface that owns vif that has address.
     *
     *  @param vifname virtual interface owning address.
     *
     *  @param addr the address to be removed.
     */
    virtual XrlCmdError rip_0_1_remove_rip_address(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr) = 0;

    virtual XrlCmdError rip_0_1_set_rip_address_enabled(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const bool&	enabled) = 0;

    virtual XrlCmdError rip_0_1_rip_address_enabled(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	bool&	enabled) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set cost metric associated with address.
     */
    virtual XrlCmdError rip_0_1_set_cost(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	cost) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get cost metric associated with address.
     */
    virtual XrlCmdError rip_0_1_cost(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	uint32_t&	cost) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set horizon type applied to routes advertised from address.
     *
     *  @param horizon name of horizon type. Permitted values: "none",
     *  "poison-reverse" "split-horizon-poison-reverse"
     */
    virtual XrlCmdError rip_0_1_set_horizon(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const string&	horizon) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get horizon type applied to routes advertised from address.
     */
    virtual XrlCmdError rip_0_1_horizon(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	string&	horizon) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Make RIP passive (receive only) on interface/vif/address.
     */
    virtual XrlCmdError rip_0_1_set_passive(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const bool&	passive) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get value indicating whether RIP is passive (receive only) on
     *  interface/vif/address.
     */
    virtual XrlCmdError rip_0_1_passive(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	bool&	passive) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Accept and respond to non-RIP requests.
     */
    virtual XrlCmdError rip_0_1_set_accept_non_rip_requests(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const bool&	accept) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get value indicating whether non-RIP requests are accepted and
     *  responded to on interface/vif/address.
     */
    virtual XrlCmdError rip_0_1_accept_non_rip_requests(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	bool&	accept) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Accept default route from peers.
     */
    virtual XrlCmdError rip_0_1_set_accept_default_route(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const bool&	accept) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Accessor for whether default route is accepted from peers.
     */
    virtual XrlCmdError rip_0_1_accept_default_route(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	bool&	accept) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Advertise default route (if present).
     */
    virtual XrlCmdError rip_0_1_set_advertise_default_route(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const bool&	advertise) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Accessor for whether default route is advertised.
     */
    virtual XrlCmdError rip_0_1_advertise_default_route(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	bool&	advertise) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set period that routes associated with reception address will expire in
     *  the absence of updates.
     */
    virtual XrlCmdError rip_0_1_set_route_expiry_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get period that routes associated with reception address will expire in
     *  the absence of updates.
     */
    virtual XrlCmdError rip_0_1_route_expiry_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set period that routes associated with reception address will be
     *  deleted after they've expired.
     */
    virtual XrlCmdError rip_0_1_set_route_deletion_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get period that routes associated with reception address will be
     *  deleted after they've expired.
     */
    virtual XrlCmdError rip_0_1_route_deletion_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set period that route table requests should be sent from address when
     *  no peers are associated with it.
     */
    virtual XrlCmdError rip_0_1_set_table_request_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set period that route table requests should be sent from address when
     *  no peers are associated with it.
     */
    virtual XrlCmdError rip_0_1_table_request_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set minimum period between the unsolicited sending of the routing table
     *  from address.
     */
    virtual XrlCmdError rip_0_1_set_unsolicited_response_min_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get minimum period between the unsolicited sending of the routing table
     *  from address.
     */
    virtual XrlCmdError rip_0_1_unsolicited_response_min_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set maximum period between the unsolicited sending of the routing table
     *  from address.
     */
    virtual XrlCmdError rip_0_1_set_unsolicited_response_max_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get maximum period between the unsolicited sending of the routing table
     *  from address.
     */
    virtual XrlCmdError rip_0_1_unsolicited_response_max_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set minimum period between sending triggered updates from address.
     */
    virtual XrlCmdError rip_0_1_set_triggered_update_min_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get minimum period between sending triggered updates from address.
     */
    virtual XrlCmdError rip_0_1_triggered_update_min_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set maximum period between sending triggered updates from address.
     */
    virtual XrlCmdError rip_0_1_set_triggered_update_max_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get maximum period between sending triggered updates from address.
     */
    virtual XrlCmdError rip_0_1_triggered_update_max_seconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	uint32_t&	t_secs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the inter-packet delay between the output of packets from address.
     */
    virtual XrlCmdError rip_0_1_set_interpacket_delay_milliseconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	t_msecs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the inter-packet delay between the output of packets from address.
     */
    virtual XrlCmdError rip_0_1_interpacket_delay_milliseconds(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	uint32_t&	t_msecs) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set authentication scheme.
     */
    virtual XrlCmdError rip_0_1_set_authentication(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const string&	type,
	const string&	password) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get authentication scheme.
     */
    virtual XrlCmdError rip_0_1_authentication(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	string&	type,
	string&	password) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get a textual description of the status of address RIP is running upon.
     *
     *  @param ifname the interface that owns vif that has the address.
     *
     *  @param vifname virtual interface owns the address.
     *
     *  @param addr the address to query.
     */
    virtual XrlCmdError rip_0_1_rip_address_status(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	// Output values,
	string&	status) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add a static route.
     *
     *  @param network route target.
     *
     *  @param nexthop path to direct packets for
     *
     *  @param cost RIP cost [0--15].
     *
     *  @ref network to.
     */
    virtual XrlCmdError rip_0_1_add_static_route(
	// Input values,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	cost) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Remove static route.
     *
     *  @param network route target. This method will fail if network was not
     *  previously added with add_static_route.
     */
    virtual XrlCmdError rip_0_1_delete_static_route(
	// Input values,
	const IPv4Net&	network) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Method invoked by target implementing socket4/0.1 when a packet arrives
     *  from an IPv4 source.
     *
     *  @param sockid the identifier associated with socket where error
     *  occurred.
     *
     *  @param src_host the originating host.
     *
     *  @param src_port the originating IP port.
     *
     *  @param data the data received.
     */
    virtual XrlCmdError socket4_user_0_1_recv_event(
	// Input values,
	const string&	sockid,
	const IPv4&	src_host,
	const uint32_t&	src_port,
	const vector<uint8_t>&	data) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Method invoked by target implementing socket4/0.1 when a connection
     *  request is received from an IPv4 source.
     */
    virtual XrlCmdError socket4_user_0_1_connect_event(
	// Input values,
	const string&	sockid,
	const IPv4&	src_host,
	const uint32_t&	src_port,
	const string&	new_sockid,
	// Output values,
	bool&	accept) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Method invoked by target implementing socket4/0.1 when an error occurs.
     *
     *  @param sockid the identifier associated with socket where error
     *  occurred.
     *
     *  @param error a textual description of the error.
     *
     *  @param fatal indication of whether socket is shutdown because of error.
     */
    virtual XrlCmdError socket4_user_0_1_error_event(
	// Input values,
	const string&	sockid,
	const string&	error,
	const bool&	fatal) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Method invoked by target implementing socket4/0.1 when a socket is
     *  forcibly closed. This would typically happen when the address the
     *  socket is bound to is removed from an interface. This method is not
     *  called if the socket is closed through socket/0.1/close.
     */
    virtual XrlCmdError socket4_user_0_1_close_event(
	// Input values,
	const string&	sockid,
	const string&	reason) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_birth(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_death(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_add_rip_address(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_remove_rip_address(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_rip_address_enabled(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_rip_address_enabled(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_cost(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_cost(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_horizon(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_horizon(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_passive(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_passive(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_accept_non_rip_requests(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_accept_non_rip_requests(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_accept_default_route(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_accept_default_route(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_advertise_default_route(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_advertise_default_route(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_route_expiry_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_route_expiry_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_route_deletion_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_route_deletion_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_table_request_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_table_request_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_unsolicited_response_min_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_unsolicited_response_min_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_unsolicited_response_max_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_unsolicited_response_max_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_triggered_update_min_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_triggered_update_min_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_triggered_update_max_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_triggered_update_max_seconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_interpacket_delay_milliseconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_interpacket_delay_milliseconds(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_set_authentication(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_authentication(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_rip_address_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_add_static_route(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rip_0_1_delete_static_route(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_socket4_user_0_1_recv_event(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_socket4_user_0_1_connect_event(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_socket4_user_0_1_error_event(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_socket4_user_0_1_close_event(const XrlArgs& in, XrlArgs* out);

    void add_handlers()
    {
	if (_cmds->add_handler("common/0.1/get_target_name",
	    callback(this, &XrlRipTargetBase::handle_common_0_1_get_target_name)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/common/0.1/get_target_name");
	}
	if (_cmds->add_handler("common/0.1/get_version",
	    callback(this, &XrlRipTargetBase::handle_common_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/common/0.1/get_version");
	}
	if (_cmds->add_handler("common/0.1/get_status",
	    callback(this, &XrlRipTargetBase::handle_common_0_1_get_status)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/common/0.1/get_status");
	}
	if (_cmds->add_handler("common/0.1/shutdown",
	    callback(this, &XrlRipTargetBase::handle_common_0_1_shutdown)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/common/0.1/shutdown");
	}
	if (_cmds->add_handler("finder_event_observer/0.1/xrl_target_birth",
	    callback(this, &XrlRipTargetBase::handle_finder_event_observer_0_1_xrl_target_birth)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/finder_event_observer/0.1/xrl_target_birth");
	}
	if (_cmds->add_handler("finder_event_observer/0.1/xrl_target_death",
	    callback(this, &XrlRipTargetBase::handle_finder_event_observer_0_1_xrl_target_death)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/finder_event_observer/0.1/xrl_target_death");
	}
	if (_cmds->add_handler("rip/0.1/add_rip_address",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_add_rip_address)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/add_rip_address");
	}
	if (_cmds->add_handler("rip/0.1/remove_rip_address",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_remove_rip_address)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/remove_rip_address");
	}
	if (_cmds->add_handler("rip/0.1/set_rip_address_enabled",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_rip_address_enabled)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_rip_address_enabled");
	}
	if (_cmds->add_handler("rip/0.1/rip_address_enabled",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_rip_address_enabled)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/rip_address_enabled");
	}
	if (_cmds->add_handler("rip/0.1/set_cost",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_cost)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_cost");
	}
	if (_cmds->add_handler("rip/0.1/cost",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_cost)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/cost");
	}
	if (_cmds->add_handler("rip/0.1/set_horizon",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_horizon)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_horizon");
	}
	if (_cmds->add_handler("rip/0.1/horizon",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_horizon)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/horizon");
	}
	if (_cmds->add_handler("rip/0.1/set_passive",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_passive)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_passive");
	}
	if (_cmds->add_handler("rip/0.1/passive",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_passive)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/passive");
	}
	if (_cmds->add_handler("rip/0.1/set_accept_non_rip_requests",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_accept_non_rip_requests)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_accept_non_rip_requests");
	}
	if (_cmds->add_handler("rip/0.1/accept_non_rip_requests",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_accept_non_rip_requests)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/accept_non_rip_requests");
	}
	if (_cmds->add_handler("rip/0.1/set_accept_default_route",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_accept_default_route)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_accept_default_route");
	}
	if (_cmds->add_handler("rip/0.1/accept_default_route",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_accept_default_route)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/accept_default_route");
	}
	if (_cmds->add_handler("rip/0.1/set_advertise_default_route",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_advertise_default_route)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_advertise_default_route");
	}
	if (_cmds->add_handler("rip/0.1/advertise_default_route",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_advertise_default_route)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/advertise_default_route");
	}
	if (_cmds->add_handler("rip/0.1/set_route_expiry_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_route_expiry_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_route_expiry_seconds");
	}
	if (_cmds->add_handler("rip/0.1/route_expiry_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_route_expiry_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/route_expiry_seconds");
	}
	if (_cmds->add_handler("rip/0.1/set_route_deletion_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_route_deletion_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_route_deletion_seconds");
	}
	if (_cmds->add_handler("rip/0.1/route_deletion_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_route_deletion_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/route_deletion_seconds");
	}
	if (_cmds->add_handler("rip/0.1/set_table_request_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_table_request_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_table_request_seconds");
	}
	if (_cmds->add_handler("rip/0.1/table_request_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_table_request_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/table_request_seconds");
	}
	if (_cmds->add_handler("rip/0.1/set_unsolicited_response_min_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_unsolicited_response_min_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_unsolicited_response_min_seconds");
	}
	if (_cmds->add_handler("rip/0.1/unsolicited_response_min_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_unsolicited_response_min_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/unsolicited_response_min_seconds");
	}
	if (_cmds->add_handler("rip/0.1/set_unsolicited_response_max_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_unsolicited_response_max_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_unsolicited_response_max_seconds");
	}
	if (_cmds->add_handler("rip/0.1/unsolicited_response_max_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_unsolicited_response_max_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/unsolicited_response_max_seconds");
	}
	if (_cmds->add_handler("rip/0.1/set_triggered_update_min_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_triggered_update_min_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_triggered_update_min_seconds");
	}
	if (_cmds->add_handler("rip/0.1/triggered_update_min_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_triggered_update_min_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/triggered_update_min_seconds");
	}
	if (_cmds->add_handler("rip/0.1/set_triggered_update_max_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_triggered_update_max_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_triggered_update_max_seconds");
	}
	if (_cmds->add_handler("rip/0.1/triggered_update_max_seconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_triggered_update_max_seconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/triggered_update_max_seconds");
	}
	if (_cmds->add_handler("rip/0.1/set_interpacket_delay_milliseconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_interpacket_delay_milliseconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_interpacket_delay_milliseconds");
	}
	if (_cmds->add_handler("rip/0.1/interpacket_delay_milliseconds",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_interpacket_delay_milliseconds)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/interpacket_delay_milliseconds");
	}
	if (_cmds->add_handler("rip/0.1/set_authentication",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_set_authentication)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/set_authentication");
	}
	if (_cmds->add_handler("rip/0.1/authentication",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_authentication)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/authentication");
	}
	if (_cmds->add_handler("rip/0.1/rip_address_status",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_rip_address_status)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/rip_address_status");
	}
	if (_cmds->add_handler("rip/0.1/add_static_route",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_add_static_route)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/add_static_route");
	}
	if (_cmds->add_handler("rip/0.1/delete_static_route",
	    callback(this, &XrlRipTargetBase::handle_rip_0_1_delete_static_route)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/rip/0.1/delete_static_route");
	}
	if (_cmds->add_handler("socket4_user/0.1/recv_event",
	    callback(this, &XrlRipTargetBase::handle_socket4_user_0_1_recv_event)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/socket4_user/0.1/recv_event");
	}
	if (_cmds->add_handler("socket4_user/0.1/connect_event",
	    callback(this, &XrlRipTargetBase::handle_socket4_user_0_1_connect_event)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/socket4_user/0.1/connect_event");
	}
	if (_cmds->add_handler("socket4_user/0.1/error_event",
	    callback(this, &XrlRipTargetBase::handle_socket4_user_0_1_error_event)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/socket4_user/0.1/error_event");
	}
	if (_cmds->add_handler("socket4_user/0.1/close_event",
	    callback(this, &XrlRipTargetBase::handle_socket4_user_0_1_close_event)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://rip/socket4_user/0.1/close_event");
	}
	_cmds->finalize();
    }

    void remove_handlers()
    {
	_cmds->remove_handler("common/0.1/get_target_name");
	_cmds->remove_handler("common/0.1/get_version");
	_cmds->remove_handler("common/0.1/get_status");
	_cmds->remove_handler("common/0.1/shutdown");
	_cmds->remove_handler("finder_event_observer/0.1/xrl_target_birth");
	_cmds->remove_handler("finder_event_observer/0.1/xrl_target_death");
	_cmds->remove_handler("rip/0.1/add_rip_address");
	_cmds->remove_handler("rip/0.1/remove_rip_address");
	_cmds->remove_handler("rip/0.1/set_rip_address_enabled");
	_cmds->remove_handler("rip/0.1/rip_address_enabled");
	_cmds->remove_handler("rip/0.1/set_cost");
	_cmds->remove_handler("rip/0.1/cost");
	_cmds->remove_handler("rip/0.1/set_horizon");
	_cmds->remove_handler("rip/0.1/horizon");
	_cmds->remove_handler("rip/0.1/set_passive");
	_cmds->remove_handler("rip/0.1/passive");
	_cmds->remove_handler("rip/0.1/set_accept_non_rip_requests");
	_cmds->remove_handler("rip/0.1/accept_non_rip_requests");
	_cmds->remove_handler("rip/0.1/set_accept_default_route");
	_cmds->remove_handler("rip/0.1/accept_default_route");
	_cmds->remove_handler("rip/0.1/set_advertise_default_route");
	_cmds->remove_handler("rip/0.1/advertise_default_route");
	_cmds->remove_handler("rip/0.1/set_route_expiry_seconds");
	_cmds->remove_handler("rip/0.1/route_expiry_seconds");
	_cmds->remove_handler("rip/0.1/set_route_deletion_seconds");
	_cmds->remove_handler("rip/0.1/route_deletion_seconds");
	_cmds->remove_handler("rip/0.1/set_table_request_seconds");
	_cmds->remove_handler("rip/0.1/table_request_seconds");
	_cmds->remove_handler("rip/0.1/set_unsolicited_response_min_seconds");
	_cmds->remove_handler("rip/0.1/unsolicited_response_min_seconds");
	_cmds->remove_handler("rip/0.1/set_unsolicited_response_max_seconds");
	_cmds->remove_handler("rip/0.1/unsolicited_response_max_seconds");
	_cmds->remove_handler("rip/0.1/set_triggered_update_min_seconds");
	_cmds->remove_handler("rip/0.1/triggered_update_min_seconds");
	_cmds->remove_handler("rip/0.1/set_triggered_update_max_seconds");
	_cmds->remove_handler("rip/0.1/triggered_update_max_seconds");
	_cmds->remove_handler("rip/0.1/set_interpacket_delay_milliseconds");
	_cmds->remove_handler("rip/0.1/interpacket_delay_milliseconds");
	_cmds->remove_handler("rip/0.1/set_authentication");
	_cmds->remove_handler("rip/0.1/authentication");
	_cmds->remove_handler("rip/0.1/rip_address_status");
	_cmds->remove_handler("rip/0.1/add_static_route");
	_cmds->remove_handler("rip/0.1/delete_static_route");
	_cmds->remove_handler("socket4_user/0.1/recv_event");
	_cmds->remove_handler("socket4_user/0.1/connect_event");
	_cmds->remove_handler("socket4_user/0.1/error_event");
	_cmds->remove_handler("socket4_user/0.1/close_event");
    }
};

#endif /* __XRL_INTERFACES_RIP_BASE_HH__ */
