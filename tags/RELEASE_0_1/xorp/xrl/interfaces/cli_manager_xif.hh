/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/cli_manager_xif.hh,v 1.8 2002/11/19 19:31:42 hodson Exp $
 */


#ifndef __XRL_INTERFACES_CLI_MANAGER_XIF_HH__
#define __XRL_INTERFACES_CLI_MANAGER_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifCliManager"
#include "libxorp/xlog.h"
#include "libxipc/xrlrouter.hh"

class XrlCliManagerV0p1Client {
public:
    XrlCliManagerV0p1Client(XrlRouter* r) : _router(r) {}
    virtual ~XrlCliManagerV0p1Client() {}

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB0;
    /**
     *  Send Xrl intended to:
     *  
     *  Add a CLI command to the CLI manager
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param processor_name the name of the module that will process that
     *  command.
     *  
     *  @param command_name the name of the command to add.
     *  
     *  @param command_help the help for the command to add.
     *  
     *  @param is_command_cd is true, the string that will replace the CLI
     *  prompt after we "cd" to that level of the CLI command-tree.
     *  
     *  @param command_cd_prompt if
     *  
     *  @param is_command_processor if true, this is a processing command that
     *  would be performed by
     *  
     *  @processor_name.
     */
    bool send_add_cli_command(
	const char*	target_name, 
	const string&	processor_name, 
	const string&	command_name, 
	const string&	command_help, 
	const bool&	is_command_cd, 
	const string&	command_cd_prompt, 
	const bool&	is_command_processor, 
	const CB0&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB1;
    /**
     *  Send Xrl intended to:
     *  
     *  Delete a CLI command from the CLI manager
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param processor_name the name of the module that sends the request.
     *  
     *  @param command_name the name of the command to delete.
     */
    bool send_delete_cli_command(
	const char*	target_name, 
	const string&	processor_name, 
	const string&	command_name, 
	const CB1&	cb
    );

protected:
    XrlRouter* _router;

private:
    void unmarshall0(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB0		cb
    );

    void unmarshall1(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB1		cb
    );

};

#endif /* __XRL_INTERFACES_CLI_MANAGER_XIF_HH__ */
