// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001,2002 International Computer Science Institute
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

// $XORP: xorp/bgp/plumbing_test.hh,v 1.12 2002/12/09 18:28:46 hodson Exp $

#ifndef __BGP_PLUMBING_TEST_HH__
#define __BGP_PLUMBING_TEST_HH__

#include "plumbing.hh"
#include "peer.hh"

class DummyPeer : public BGPPeer {
public:
    DummyPeer(LocalData *ld, BGPPeerData *pd, SocketClient *sock, 
	      BGPMain *m);
    PeerOutputState send_update_message(const UpdatePacket& p);
};

class DummyPeerHandler : public PeerHandler {
public:
    DummyPeerHandler(const string &peername, 
		     BGPPeer *peer, BGPPlumbing *plumbing);
    int add_route(const InternalMessage<IPv4> &rtmsg);
    int add_route(const InternalMessage<IPv6> &rtmsg);
};

class PlumbingTest : public BGPPlumbing {
public:
    PlumbingTest();
    bool run_tests();
    bool test1();
    bool test2();
};

#endif // __BGP_PLUMBING_TEST_HH__
