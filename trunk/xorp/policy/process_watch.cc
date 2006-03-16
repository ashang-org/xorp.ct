// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-
// vim:set sts=4 ts=8:

// Copyright (c) 2001-2006 International Computer Science Institute
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

#ident "$XORP: xorp/policy/process_watch.cc,v 1.4 2005/10/23 20:41:38 abittau Exp $"

// #define DEBUG_LOGGING
// #define DEBUG_PRINT_FUNCTION_NAME

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "policy_module.h"
#include "libxorp/debug.h"
#include "process_watch.hh"

ProcessWatch::ProcessWatch(XrlStdRouter& rtr, ProtocolMap& pmap) :
		_pmap(pmap),
		_finder(&rtr), 
		_instance_name(rtr.instance_name()),
		_notifier(NULL),
		_finder_name("finder") // FIXME: hardcoded value
{
}

void 
ProcessWatch::register_cb(const XrlError& err)
{
    if (err != XrlError::OKAY()) {
	throw PWException(err.str());
    }
}

void 
ProcessWatch::add_interest(const string& proc) 
{
    // check if we already added interested, if so do nothing
    if (_watching.find(proc) != _watching.end())
	return;

    _watching.insert(proc);

    debug_msg("[POLICY] ProcessWatch Add interest in process: %s\n",
	      proc.c_str());

    // add interested in process
    _finder.send_register_class_event_interest(_finder_name.c_str(),
		_instance_name, _pmap.xrl_target(proc),
		callback(this,&ProcessWatch::register_cb));
}

void 
ProcessWatch::birth(const string& proto) 
{
    const string& p = _pmap.protocol(proto);
    _alive.insert(p);

    // inform any hooked notifier
    if (_notifier)
	_notifier->birth(p);

}

void 
ProcessWatch::death(const string& proto) 
{
    const string& p = _pmap.protocol(proto);
    _alive.erase(p);

    if (_notifier)
	_notifier->death(p);
}

bool 
ProcessWatch::alive(const string& proto) 
{
    if (_watching.find(proto) == _watching.end())
	throw PWException("Not watching protocol: " + proto);

    return _alive.find(proto) != _alive.end();
}

void
ProcessWatch::set_notifier(PWNotifier& notifier) 
{
    // old notifier is lost... it is a feature, not a bug.
    _notifier = &notifier;
}
