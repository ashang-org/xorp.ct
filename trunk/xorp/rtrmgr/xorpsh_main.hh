// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2004 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

// $XORP: xorp/rtrmgr/xorpsh_main.hh,v 1.15 2004/12/06 00:31:05 mjh Exp $

#ifndef __RTRMGR_XORPSH_MAIN_HH__
#define __RTRMGR_XORPSH_MAIN_HH__


#include "libxorp/eventloop.hh"

#include "libxipc/xrl_std_router.hh"

#include "cli/cli_node.hh"

#include "xrl/interfaces/rtrmgr_xif.hh"

#include "rtrmgr_error.hh"
#include "xorp_client.hh"
#include "xrl_xorpsh_interface.hh"
#include "generic_module_manager.hh"


class OpCommandList;
class RouterCLI;
class SlaveConfigTree;
class TemplateTree;

class XorpShell {
    typedef XorpCallback2<void, bool, string>::RefPtr CallBack;

public:
    XorpShell(const string& IPCname, 
	      const string& xorp_root_dir,
	      const string& config_template_dir, 
	      const string& xrl_targets_dir,
	      bool verbose) throw (InitError);
    ~XorpShell();

    void run();
    enum Mode {
	MODE_AUTHENTICATING, 
	MODE_INITIALIZING, 
	MODE_IDLE, 
	MODE_COMMITTING, 
	MODE_LOADING,
	MODE_SHUTDOWN
    };

    void set_mode(Mode mode) { _mode = mode; }
    
    void register_done(const XrlError& e, const string* token,
		       const uint32_t* pid);
    void generic_done(const XrlError& e);
    void request_config();
    void receive_config(const XrlError& e, const bool* ready,
			const string* config);

    typedef XorpCallback1<void, const XrlError&>::RefPtr GENERIC_CALLBACK;
    void enter_config_mode(bool exclusive, GENERIC_CALLBACK cb);

    void leave_config_mode(GENERIC_CALLBACK cb);

    typedef XorpCallback3<void, const XrlError&, 
			  const bool*,
			  const uint32_t*>::RefPtr LOCK_CALLBACK;
    void lock_config(LOCK_CALLBACK cb);

    void commit_changes(const string& deltas, const string& deletions,
			GENERIC_CALLBACK cb,
			CallBack final_cb);
    void commit_done(bool success, const string& errmsg);

    void unlock_config(GENERIC_CALLBACK cb);

    typedef XorpCallback2<void, const XrlError&,
			  const XrlAtomList*>::RefPtr GET_USERS_CALLBACK;
    void get_config_users(GET_USERS_CALLBACK cb);

    void new_config_user(uid_t user_id);

    void save_to_file(const string& filename, GENERIC_CALLBACK cb);

    void load_from_file(const string& filename, GENERIC_CALLBACK cb,
			CallBack final_cb);

    void config_changed(uid_t user_id, const string& deltas, 
			const string& deletions);

    void module_status_change(const string& modname, 
			      GenericModule::ModuleStatus status);

    typedef XorpCallback2<void, const XrlError&, 
			  const uint32_t*>::RefPtr PID_CALLBACK;
    void get_rtrmgr_pid(PID_CALLBACK cb);

    EventLoop& eventloop()		{ return _eventloop; }
    SlaveConfigTree* config_tree()	{ return _ct; }
    TemplateTree* template_tree()	{ return _tt; }
    OpCommandList* op_cmd_list()	{ return _ocl; }
    XorpClient& xorp_client()		{ return _xclient; }
    const string& xorp_root_dir() const	{ return _xorp_root_dir; }
    bool verbose() const		{ return _verbose; }
    uint32_t rtrmgr_pid() const		{ return _rtrmgr_pid; }

private:
    EventLoop		_eventloop; 
    XrlStdRouter	_xrlrouter;
    XorpClient		_xclient;
    XrlRtrmgrV0p1Client	_rtrmgr_client;
    XrlXorpshInterface	_xorpsh_interface;

    TemplateTree*	_tt;
    SlaveConfigTree*	_ct;
    OpCommandList*	_ocl;
    CliNode		_cli_node;
    RouterCLI*		_router_cli;
    string		_xorp_root_dir;	// The root of the XORP tree
    bool		_verbose;	// Set to true if output is verbose
    string		_ipc_name;
    string		_authfile;
    string		_authtoken;
    bool		_got_config;
    bool		_got_modules;
    string		_configuration;

    bool		_done;	// Used to move through the startup process
    Mode		_mode;

    // Used to store the callback during a commit until we get called
    // with the response
    CallBack		_commit_callback;
    string		_commit_status;	// Used for transient storage of error
					// messages from commit

    uint32_t		_rtrmgr_pid;

    XorpTimer           _repeat_request_timer;
};

#endif // __RTRMGR_XORPSH_MAIN_HH__
