// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
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

// $XORP: xorp/rtrmgr/master_conf_tree.hh,v 1.7 2003/05/02 09:00:01 mjh Exp $

#ifndef __RTRMGR_MASTER_CONF_TREE_HH__
#define __RTRMGR_MASTER_CONF_TREE_HH__

#include <map>
#include <list>
#include <set>
#include "config.h"
#include "libxorp/xorp.h"
#include "master_conf_tree_node.hh"
#include "task.hh"
#include "parse_error.hh"
#include "conf_tree.hh"

class RouterCLI;
class CommandTree;
class ConfTemplate;

class MasterConfigTree :public ConfigTree {
    typedef XorpCallback2<void, bool, string>::RefPtr CallBack;
public:
    MasterConfigTree(const string& conffile, TemplateTree *ct, 
		     TaskManager& task_manager);
    bool read_file(string& configuration, const string& conffile,
		   string& errmsg);
    bool parse(const string& configuration, const string& conffile);
    void execute();
    void config_done(bool success, string errmsg);
    list <string> find_changed_modules() const;

    void commit_changes_pass1(CallBack cb);
    void commit_pass1_done(bool success, string errmsg);
    void commit_changes_pass2();
    void commit_pass2_done(bool success, string errmsg);

    bool check_commit_status(string &response);
    string discard_changes();
    string mark_subtree_for_deletion(const list <string>& pathsegs, 
				     uid_t user_id);
    bool lock_node(const string& node, uid_t user_id, uint32_t timeout, 
		   uint32_t& holder);
    bool unlock_node(const string& node, uid_t user_id);

    bool save_to_file(const string& filename, uid_t user_id, string& errmsg);
    bool load_from_file(const string& filename, uid_t user_id,
			string& errmsg, string& deltas, string& deletions);

    /*adaptors so we don't need casts elsewhere*/
    MasterConfigTreeNode *root() { 
	return (MasterConfigTreeNode*)(&_root_node);
    }
    const MasterConfigTreeNode *const_root() const {
	return (const MasterConfigTreeNode*)(&_root_node);
    }

private:
    void diff_configs(const ConfigTree& new_tree, ConfigTree& delta_tree,
		      ConfigTree& deletion_tree);

    bool module_config_start(const string& module_name,
			     string& errmsg);
    bool module_config_done(const string& module_name,
			    string& errmsg);

    bool do_exec() const {return _task_manager.do_exec();}

    ModuleManager& module_manager() const 
    {
	return _task_manager.module_manager();
    }

    XorpClient& xorp_client() const {return _task_manager.xorp_client();}

    TaskManager& _task_manager;
    CallBack _commit_cb;
};

#endif // __RTRMGR_MASTER_CONF_TREE_HH__
