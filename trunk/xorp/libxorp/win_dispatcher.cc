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

// $XORP: xorp/libxorp/win_dispatcher.cc,v 1.6 2005/12/21 09:42:58 bms Exp $

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HOST_OS_WINDOWS	    // This entire file is for Windows only.

#include "libxorp/xorp.h"

#include "libxorp/libxorp_module.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"
#include "libxorp/win_io.h"

#include "libxorp/xorpfd.hh"
#include "libxorp/timeval.hh"
#include "libxorp/clock.hh"
#include "libxorp/callback.hh"
#include "libxorp/ioevents.hh"
#include "libxorp/eventloop.hh"
#include "libxorp/win_dispatcher.hh"

static inline int
_wsa2ioe(const long wsaevent)
{
    switch (wsaevent) {
    case FD_READ:
	return IOT_READ;
    case FD_WRITE:
	return IOT_WRITE;
    case FD_OOB:
	return IOT_EXCEPTION;
    case FD_ACCEPT:
	return IOT_ACCEPT;
    case FD_CONNECT:
	return IOT_CONNECT;
    case FD_CLOSE:
	return IOT_DISCONNECT;
    }
    return -1;
}

static inline long
_ioe2wsa(const IoEventType ioevent)
{
    switch (ioevent) {
    case IOT_READ:
	return FD_READ;
    case IOT_WRITE:
	return FD_WRITE;
    case IOT_EXCEPTION:
	return FD_OOB;
    case IOT_ACCEPT:
	return FD_ACCEPT;
    case IOT_CONNECT:
	return FD_CONNECT;
    case IOT_DISCONNECT:
	return FD_CLOSE;
    case IOT_ANY:
	return 0;
    }
    return 0;
}

WinDispatcher::WinDispatcher(ClockBase* clock)
  : _clock(clock)
{
    // Avoid introducing a circular dependency upon libcomm by calling
    // WSAStartup() and WSACleanup() ourselves. It's safe for the same
    // thread within the same process to call it more than once.
    WSADATA wsadata;
    WORD version = MAKEWORD(2, 2);
    int retval = WSAStartup(version, &wsadata);
    if (retval != 0) {
	XLOG_FATAL("WSAStartup() error: %s", win_strerror(GetLastError()));
    }

    _handles.reserve(MAXIMUM_WAIT_OBJECTS);
}

WinDispatcher::~WinDispatcher()
{
    // Purge all pending socket event notifications from Winsock.
    for (SocketEventMap::iterator ii = _socket_event_map.begin();
	 ii != _socket_event_map.end(); ++ii) {
	WSAEventSelect(ii->first, NULL, 0);
    }
    WSACleanup();
}

bool
WinDispatcher::add_socket_cb(XorpFd& fd, IoEventType type, const IoEventCb& cb)
{
    // XXX: Currently we only support 1 callback per socket/event tuple.
    // Check that the socket does not already have a callback
    // registered for it.
    IoEventMap::iterator ii = _callback_map.find(IoEventTuple(fd, type));
    if (ii != _callback_map.end()) {
	debug_msg("callback already registered.\n");
	return false;
    }

    long oldmask;
    long newmask = _ioe2wsa(type);

    if (newmask == 0 || (newmask & ~WSAEVENT_SUPPORTED) != 0) {
	debug_msg("IoEventType does not map to a valid Winsock async "
		  "event mask.\n");
	return false;
    }

    HANDLE hevent = WSA_INVALID_EVENT;

    // Check if there are notifications already requested for
    // this socket. Listening sockets must only have IOT_ACCEPT pending.
    SocketEventMap::iterator jj = _socket_event_map.find(fd);
    if (jj != _socket_event_map.end()) {
	hevent = jj->second.first;
	oldmask = jj->second.second;
	if (((oldmask & ~FD_ACCEPT) && (newmask &  FD_ACCEPT)) ||
	    ((oldmask &  FD_ACCEPT) && (newmask & ~FD_ACCEPT))) {
	    debug_msg("attempt to register a socket for other events "
		     "in addition to IOT_ACCEPT.\n");
	    return false;
	}
    } else {
	//
	// This is a new map entry. Create an event object and
	// wire it up to the main dispatch.
	//
	hevent = WSACreateEvent();
	oldmask = 0;

#if 1
	// Paranoid check to see if new event handle is already
	// in the vector we pass off to WFMO.
	vector<HANDLE>::iterator qq;
	for (qq = _handles.begin(); qq != _handles.end(); qq++) {
	    if (*qq == hevent) {
		XLOG_FATAL("New event handle already exists in _handles");
	    }
	}
#endif

	// Insert the new entry into the socket event map.
	pair<SocketEventMap::iterator, bool> p =
	    _socket_event_map.insert(std::make_pair(fd,
					std::make_pair(hevent, oldmask)));
	XLOG_ASSERT(p.second == true);
	jj = p.first;

	// Insert the new event object into the WFMO handle vector,
	// and the event->socket map used for WFMO dispatch.
	_handles.push_back(hevent);
	XLOG_ASSERT(_handles.size() < MAXIMUM_WAIT_OBJECTS);

	pair <EventSocketMap::iterator, bool> q =
	    _event_socket_map.insert(std::make_pair(hevent, fd));
	XLOG_ASSERT(q.second == true);
    }

    XLOG_ASSERT(hevent != WSA_INVALID_EVENT);
    XLOG_ASSERT(jj != _socket_event_map.end());

    // An existing map entry merely needs to have its WSA event mask
    // updated, and a call to WSAEventSelect() to update the mask.
    newmask |= oldmask;
    int retval = WSAEventSelect(fd, hevent, newmask);
    if (retval != 0) {
	// XXX: Need more paranoid error checking here.
	debug_msg("WSAEventSelect() error: %s",
		  win_strerror(WSAGetLastError()));
    }
    jj->second.second = newmask;

    // Wire up the XORP I/O callback.
    _callback_map.insert(std::make_pair(IoEventTuple(fd, type), cb));

    return true;
}

bool
WinDispatcher::add_handle_cb(XorpFd& fd, IoEventType type, const IoEventCb& cb)
{
    // You cannot currently register for anything other
    // than an IOT_EXCEPTION event on a Windows object handle because
    // there is no way of telling why an object was signalled --
    // they are 'special'.
    if (fd.is_pipe() || fd.is_console())
	XLOG_ASSERT(type == IOT_READ);
    else
	XLOG_ASSERT(type == IOT_EXCEPTION);

    // Check that we haven't exceeded the handle limit.
    if (_handles.size() == MAXIMUM_WAIT_OBJECTS) {
	XLOG_WARNING("exceeded Windows object handle count\n");
	return false;
    }

    // XXX: Currently we only support 1 callback per Windows object/event.
    // Check that the object does not already have a callback
    // registered for it.
    IoEventMap::iterator ii = _callback_map.find(IoEventTuple(fd, type));
    if (ii != _callback_map.end()) {
	XLOG_WARNING("callback already registered for object\n");
	return false;
    }

    // Register the callback. Add fd to the object handle array.
    _callback_map.insert(std::make_pair(IoEventTuple(fd, type), cb));

    if (fd.is_pipe()) {
	_polled_pipes.push_back(fd);
    } else {
	_handles.push_back(fd);
    }

    return true;
}

bool
WinDispatcher::add_ioevent_cb(XorpFd fd, IoEventType type, const IoEventCb& cb)
{
debug_msg("Adding event %d to object %s\n", type, fd.str().c_str());

    switch (fd.type()) {
    case XorpFd::FDTYPE_SOCKET:
	return add_socket_cb(fd, type, cb);
	break;
    case XorpFd::FDTYPE_PIPE:
    case XorpFd::FDTYPE_CONSOLE:
    case XorpFd::FDTYPE_PROCESS:
	return add_handle_cb(fd, type, cb);
	break;
    default:
	break;
    }

    return false;
}

bool
WinDispatcher::remove_socket_cb(XorpFd& fd, IoEventType type)
{
    bool unregistered = false;
    int retval;

    SocketEventMap::iterator ii = _socket_event_map.find(fd);
    if (ii == _socket_event_map.end()) {
	debug_msg("Attempt to remove unmapped callback of type %d "
		  "from socket %s.\n", type, fd.str().c_str());
	return false;
    }

    // Compute the new event mask. Set it to zero if we were asked to
    // deregister this socket completely. 
    long delmask = _ioe2wsa(type);
    XLOG_ASSERT(delmask != -1);
    long newmask = ii->second.second & ~delmask;
    HANDLE hevent = ii->second.first;

    if (newmask != 0) {
	// WSA event mask is non-zero; just update mask.
	retval = WSAEventSelect(fd, hevent, newmask);
	if (retval != 0) {
	    debug_msg("WSAEventSelect() error: %s",
		      win_strerror(WSAGetLastError()));
	}
	ii->second.second = newmask;
    } else {
	// WSA event mask is now zero; purge completely.
	retval = WSAEventSelect(fd, NULL, 0);
	if (retval != 0) {
	    debug_msg("WSAEventSelect() error: %s",
		      win_strerror(WSAGetLastError()));
	}
	bool found = false;
	vector<HANDLE>::iterator qq;
	for (qq = _handles.begin(); qq != _handles.end(); qq++) {
	    if (*qq == hevent) {
		found = true;
		qq = _handles.erase(qq);
		break;
	    }
	}
	XLOG_ASSERT(found == true);
	WSACloseEvent(hevent);
	EventSocketMap::iterator jj = _event_socket_map.find(hevent);
	XLOG_ASSERT(jj != _event_socket_map.end());
	_socket_event_map.erase(ii);
	_event_socket_map.erase(jj);
    }

    IoEventMap::iterator jj = _callback_map.find(IoEventTuple(fd, type));
    if (jj != _callback_map.end()) {
	_callback_map.erase(jj);
	unregistered = true;
    } else {
	debug_msg("Attempt to remove a nonexistent callback of "
		  "type %d from socket %s.\n", type, fd.str().c_str());
    }

    return unregistered;
}

bool
WinDispatcher::remove_handle_cb(XorpFd& fd, IoEventType type)
{
    if (fd.is_pipe()) {
	XLOG_ASSERT(type == IOT_READ);
	for (vector<HANDLE>::iterator ii = _polled_pipes.begin();
	    ii != _polled_pipes.end(); ++ii) {
	    if (*ii == fd) {
		ii = _polled_pipes.erase(ii);
		_callback_map.erase(IoEventTuple(fd, type));
		return true;
	    }
	}
    } else {
	if (fd.is_console()) {
	    XLOG_ASSERT(type == IOT_READ);
	} else {
	    XLOG_ASSERT(type == IOT_EXCEPTION);
	}
	for (vector<HANDLE>::iterator ii = _handles.begin();
	    ii != _handles.end(); ++ii) {
	    if (*ii == fd) {
		ii = _handles.erase(ii);
		_callback_map.erase(IoEventTuple(fd, type));
		return true;
	    }
	}
    }

    return false;
}

bool
WinDispatcher::remove_ioevent_cb(XorpFd fd, IoEventType type)
{
    debug_msg("Removing event %d from object %s\n", type, fd.str().c_str());

    switch (fd.type()) {
    case XorpFd::FDTYPE_SOCKET:
	return remove_socket_cb(fd, type);
    case XorpFd::FDTYPE_PIPE:
    case XorpFd::FDTYPE_CONSOLE:
    case XorpFd::FDTYPE_PROCESS:
	return remove_handle_cb(fd, type);
	break;
    default:
	break;
    }
    return false;
}

void
WinDispatcher::wait_and_dispatch(int ms)
{
    DWORD retval;

    //
    // Wait or sleep. Do not enter a state where APCs may be called;
    // they are not compatible with the XORP event loop.
    // If we need to fix the sleep quantum to deal with polled objects, do so.
    //
    if ((!_polled_pipes.empty()) && (ms > POLLED_INTERVAL_MS || ms < 0))
	ms = POLLED_INTERVAL_MS;
    if (_handles.empty()) {
	// We probably don't want to sleep forever with no pending waits,
	// as Win32 doesn't have the same concept of signals as UNIX does.
	XLOG_ASSERT(ms != -1);
	Sleep(ms);
	retval = WAIT_TIMEOUT;
    } else { 
	retval = WaitForMultipleObjects(_handles.size(), &_handles[0],
					FALSE, ms);
    }
    _clock->advance_time();

    // Reads need to be handled first because they may come from
    // dying processes picked up by the handle poll.
    if (!_polled_pipes.empty())
	dispatch_pipe_reads();

    // The order of the if clauses here is important.
    if (retval == WAIT_FAILED) {
	DWORD lasterr = GetLastError();
	if (lasterr == ERROR_INVALID_HANDLE && !_handles.empty()) {
	    // There's a bad handle in the handles vector.
#if 1
	    // Treat this as a fatal error for now -- it's definitely
	    // a programming error.
	    XLOG_FATAL("bad handle in handles array");
#else
	    // Find it and remove it. Note, however, that we don't
	    // garbage-collect it from any of the event maps.
	    DWORD dwFlags;
	    for (vector<HANDLE>::iterator kk = _handles.begin();
	         kk != _handles.end();
		 ++kk) {
		if (GetHandleInformation(*kk, &dwFlags) == 0) {
		    XLOG_ERROR("handle %p is bad, removing it.", *kk);
		    kk = _handles.erase(kk);
		}
	    }
#endif
	} else {
	    // Programming error.
	    XLOG_FATAL("WaitForMultipleObjects(%d,%p,%d,%d) failed "
		       "with the error code %lu (%s)."
		       "Please report this error to the XORP core team.",
			_handles.empty() ? 0 : _handles.size(),
			_handles.empty() ? NULL : &_handles[0],
			FALSE, ms,
			lasterr, win_strerror(lasterr));
	}
    } else if (retval == WAIT_TIMEOUT) {
	// The timeout period elapsed. This is normal. Fall through.
    } else if (retval <= (WAIT_OBJECT_0 + _handles.size() - 1)) {
	//
	// An object in _handles was signalled. Dispatch its callback.
	// Check if it's an event associated with a socket first.
	//
	HANDLE eh = _handles[retval - WAIT_OBJECT_0];

	EventSocketMap::iterator qq = _event_socket_map.find(eh);
	if (qq != _event_socket_map.end()) {
	    dispatch_sockevent(qq->first, qq->second);
	} else {
	    // It's not an Event, so it must be something else.
	    // Figure out what it is, and deal with it.
	    XorpFd efd(eh);
	    XLOG_ASSERT(efd.type() != XorpFd::FDTYPE_SOCKET);
	    XLOG_ASSERT(efd.type() != XorpFd::FDTYPE_PIPE);
	    IoEventType evtype = (efd.type() == XorpFd::FDTYPE_CONSOLE) ?
				 IOT_READ : IOT_EXCEPTION;
	    IoEventMap::iterator jj =
		_callback_map.find(IoEventTuple(efd, evtype));
	    if (jj != _callback_map.end()) {
		jj->second->dispatch(efd, evtype);
	    } else {
		XLOG_ERROR("no callback for object %s", efd.str().c_str());
	    }
	}
    } else {
	// Programming error.
	XLOG_FATAL("WaitForMultipleObjects(%d,%p,%d,%d) returned an "
		   "unhandled return value %lu. This should never happen.",
		   _handles.empty() ? 0 : _handles.size(),
		   _handles.empty() ? NULL : &_handles[0],
		   FALSE, ms, retval);
    }
}

void
WinDispatcher::dispatch_pipe_reads()
{
    ssize_t result;

    for (vector<HANDLE>::iterator ii = _polled_pipes.begin();
	ii != _polled_pipes.end(); ii++) {
	result = win_pipe_read(*ii, NULL, 0);
	if (result == WINIO_ERROR_HASINPUT) {
	    IoEventMap::iterator jj =
_callback_map.find(IoEventTuple(*ii, IOT_READ));
	    XLOG_ASSERT(jj != _callback_map.end());
	    jj->second->dispatch(*ii, IOT_READ);
	}
    }
}

void
WinDispatcher::dispatch_sockevent(HANDLE hevent, XorpFd fd)
{
    int err;
    WSANETWORKEVENTS netevents;

    memset(&netevents, 0, sizeof(netevents));
    err = WSAEnumNetworkEvents(fd, hevent, &netevents);
    if (err != 0) {
	if (WSAGetLastError() == WSAENOTSOCK) {
	    // The socket might have been closed or EOF'd by the time
	    // we get the event.
	    XLOG_WARNING("WSAEnumNetworkEvents() returned WSAENOTSOCK for "
			 "socket %s", fd.str().c_str());
	}
	return;
    }

    // Short circuit mask check if no events occured.
    if (netevents.lNetworkEvents == 0) {
	debug_msg("event %p signalled but event mask is zero\n", hevent);
	return;
    }

    for (int evbit = 0; evbit < FD_MAX_EVENTS ; evbit++) {
	int evflag = 1 << evbit;

	if ((evflag & netevents.lNetworkEvents) == evflag) {
	    debug_msg("processing event %d\n", evflag);

	    int itype = _wsa2ioe(evflag);
	    if (itype == -1) {
		debug_msg("Can't map WSA event %d to an IoEventType", evflag);
		continue;
	    }

	    IoEventType type = static_cast<IoEventType>(itype);
	    IoEventMap::iterator jj =
		_callback_map.find(IoEventTuple(fd, type));
	    if (jj == _callback_map.end()) {
		debug_msg("IoEventType %d on socket %s does not map to a "
			  "callback.\n", itype, fd.str().c_str());
		continue;
	    }
	    jj->second->dispatch(fd, type);
	}
    }
}

#endif // HOST_OS_WINDOWS
