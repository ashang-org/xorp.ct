/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/fea_fti_xif.hh,v 1.2 2002/11/19 19:31:43 hodson Exp $
 */


#ifndef __XRL_INTERFACES_FEA_FTI_XIF_HH__
#define __XRL_INTERFACES_FEA_FTI_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFeaFti"
#include "libxorp/xlog.h"
#include "libxipc/xrlrouter.hh"

class XrlFtiV0p1Client {
public:
    XrlFtiV0p1Client(XrlRouter* r) : _router(r) {}
    virtual ~XrlFtiV0p1Client() {}

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr CB0;

    bool send_start_transaction(
	const char*	target_name, 
	const CB0&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB1;

    bool send_commit_transaction(
	const char*	target_name, 
	const uint32_t&	tid, 
	const CB1&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB2;

    bool send_abort_transaction(
	const char*	target_name, 
	const uint32_t&	tid, 
	const CB2&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB3;

    bool send_add_entry4(
	const char*	target_name, 
	const uint32_t&	tid, 
	const IPv4Net&	dst, 
	const IPv4&	gateway, 
	const string&	ifname, 
	const string&	vifname, 
	const CB3&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB4;

    bool send_delete_entry4(
	const char*	target_name, 
	const uint32_t&	tid, 
	const IPv4Net&	dst, 
	const CB4&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB5;

    bool send_add_entry6(
	const char*	target_name, 
	const uint32_t&	tid, 
	const IPv6Net&	dst, 
	const IPv6&	gateway, 
	const string&	ifname, 
	const string&	vifname, 
	const CB5&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB6;

    bool send_delete_entry6(
	const char*	target_name, 
	const uint32_t&	tid, 
	const IPv6Net&	dst, 
	const CB6&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB7;

    bool send_delete_all_entries(
	const char*	target_name, 
	const uint32_t&	tid, 
	const CB7&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB8;

    bool send_delete_all_entries4(
	const char*	target_name, 
	const uint32_t&	tid, 
	const CB8&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB9;

    bool send_delete_all_entries6(
	const char*	target_name, 
	const uint32_t&	tid, 
	const CB9&	cb
    );

    typedef XorpCallback5<void, const XrlError&, const IPv4Net*, const IPv4*, const string*, const string*>::RefPtr CB10;

    bool send_lookup_route4(
	const char*	target_name, 
	const IPv4&	dst, 
	const CB10&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const IPv4*, const string*, const string*>::RefPtr CB11;

    bool send_lookup_entry4(
	const char*	target_name, 
	const IPv4Net&	dst, 
	const CB11&	cb
    );

    typedef XorpCallback5<void, const XrlError&, const IPv6Net*, const IPv6*, const string*, const string*>::RefPtr CB12;

    bool send_lookup_route6(
	const char*	target_name, 
	const IPv6&	dst, 
	const CB12&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const IPv6*, const string*, const string*>::RefPtr CB13;

    bool send_lookup_entry6(
	const char*	target_name, 
	const IPv6Net&	dst, 
	const CB13&	cb
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

    void unmarshall2(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB2		cb
    );

    void unmarshall3(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB3		cb
    );

    void unmarshall4(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB4		cb
    );

    void unmarshall5(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB5		cb
    );

    void unmarshall6(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB6		cb
    );

    void unmarshall7(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB7		cb
    );

    void unmarshall8(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB8		cb
    );

    void unmarshall9(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB9		cb
    );

    void unmarshall10(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB10		cb
    );

    void unmarshall11(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB11		cb
    );

    void unmarshall12(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB12		cb
    );

    void unmarshall13(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB13		cb
    );

};

#endif /* __XRL_INTERFACES_FEA_FTI_XIF_HH__ */
