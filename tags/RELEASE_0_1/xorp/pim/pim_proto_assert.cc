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

#ident "$XORP: xorp/pim/pim_proto_assert.cc,v 1.23 2002/12/09 18:29:28 hodson Exp $"


//
// PIM PIM_ASSERT messages processing.
//


#include "pim_module.h"
#include "pim_private.hh"
#include "pim_mre.hh"
#include "pim_mrt.hh"
#include "pim_proto_assert.hh"
#include "pim_vif.hh"


//
// Exported variables
//

//
// Local constants definitions
//

//
// Local structures/classes, typedefs and macros
//

//
// Local variables
//

//
// Local functions prototypes
//


/**
 * PimVif::pim_assert_recv:
 * @pim_nbr: The PIM neighbor message originator (or NULL if not a neighbor).
 * @src: The message source address.
 * @dst: The message destination address.
 * @buffer: The buffer with the message.
 * 
 * Receive PIM_ASSERT message.
 * 
 * Return value: %XORP_OK on success, otherwise %XORP_ERROR.
 **/
int
PimVif::pim_assert_recv(PimNbr *pim_nbr,
			const IPvX& src,
			const IPvX& dst,
			buffer_t *buffer)
{
    int			rcvd_family;
    uint32_t		group_masklen;
    uint8_t		group_addr_reserved_flags;
    IPvX		assert_source_addr(family());
    IPvX		assert_group_addr(family());
    uint32_t		metric_preference, metric;
    AssertMetric	assert_metric(src);
    bool		rpt_bit;
    
    //
    // Parse the message
    //
    GET_ENCODED_GROUP_ADDR(rcvd_family, assert_group_addr, group_masklen,
			   group_addr_reserved_flags, buffer);
    GET_ENCODED_UNICAST_ADDR(rcvd_family, assert_source_addr, buffer);
    BUFFER_GET_HOST_32(metric_preference, buffer);
    BUFFER_GET_HOST_32(metric, buffer);
    // The RPT bit
    if (metric_preference & PIM_ASSERT_RPT_BIT)
	rpt_bit = true;
    else
	rpt_bit = false;
    metric_preference &= ~PIM_ASSERT_RPT_BIT;
    
    // The assert metrics
    assert_metric.set_rpt_bit_flag(rpt_bit);
    assert_metric.set_metric_preference(metric_preference);
    assert_metric.set_route_metric(metric);
    assert_metric.set_addr(src);
    
    //
    // Process the assert data
    //
    pim_assert_process(pim_nbr, src, dst,
		       assert_source_addr, assert_group_addr,
		       group_masklen, &assert_metric);
    
    // UNUSED(dst);
    return (XORP_OK);
    
    // Various error processing
 rcvlen_error:
    XLOG_WARNING("RX %s from %s to %s: "
		 "invalid message length",
		 PIMTYPE2ASCII(PIM_ASSERT),
		 cstring(src), cstring(dst));
    return (XORP_ERROR);
    
 rcvd_masklen_error:
    XLOG_WARNING("RX %s from %s to %s: "
		 "invalid masklen = %d",
		 PIMTYPE2ASCII(PIM_ASSERT),
		 cstring(src), cstring(dst), group_masklen);
    return (XORP_ERROR);
    
 rcvd_family_error:
    XLOG_WARNING("RX %s from %s to %s: "
		 "invalid address family inside = %d",
		 PIMTYPE2ASCII(PIM_ASSERT),
		 cstring(src), cstring(dst), rcvd_family);
    return (XORP_ERROR);
}

int
PimVif::pim_assert_process(PimNbr *pim_nbr,
			   const IPvX& src, const IPvX& dst,
			   const IPvX& assert_source_addr,
			   const IPvX& assert_group_addr,
			   uint32_t group_masklen, AssertMetric *assert_metric)
{
    uint32_t	lookup_flags, create_flags;
    PimMre	*pim_mre;
    
    if (assert_metric->rpt_bit_flag())
	lookup_flags = PIM_MRE_WC;
    else
	lookup_flags = PIM_MRE_SG;
    // TODO: XXX: PAVPAVPAV: should create_flags = 0 instead, and
    // silently ignore Assert messages if we don't have any state
    // about the particular (S,G) or (*,G)?
    // However, make sure that an (S,G) is created if it is
    // an (S,G) assert and there is (S,G,rpt) PimMre entry
    create_flags = lookup_flags;
    
    if (group_masklen != IPvX::addr_bitlen(family())) {
	XLOG_WARNING("RX %s from %s to %s: "
		     "invalid group mask length = %d "
		     "instead of %d",
		     PIMTYPE2ASCII(PIM_ASSERT),
		     cstring(src), cstring(dst),
		     group_masklen, IPvX::addr_bitlen(family()));
	return (XORP_ERROR);
    }
    
    pim_mre = pim_mrt().pim_mre_find(assert_source_addr, assert_group_addr,
				     lookup_flags, create_flags);
    if (pim_mre == NULL) {
	XLOG_ERROR("Internal error lookup/creating PIM multicast routing "
		   "entry for source = %s group = %s",
		   cstring(assert_source_addr), cstring(assert_group_addr));
	return (XORP_ERROR);
    }
    
    return (pim_mre->assert_process(this, assert_source_addr, assert_metric));
    
    UNUSED(pim_nbr);
}

//
// XXX: @assert_source_addr is the source address inside the assert message
// XXX: applies only for (S,G) and (*,G)
//
int
PimVif::pim_assert_mre_send(PimMre *pim_mre, const IPvX& assert_source_addr)
{
    IPvX	assert_group_addr(family());
    uint32_t	group_masklen;
    uint32_t	route_metric, metric_preference;
    int		ret_value;
    
    if (! (pim_mre->is_sg() || pim_mre->is_wc()))
	return (XORP_ERROR);
    
    // Prepare the Assert data
    assert_group_addr  = pim_mre->group_addr();
    group_masklen = IPvX::addr_bitlen(family());
    
    if (pim_mre->is_spt()) {
	route_metric = pim_mre->route_metric_s();
	metric_preference = pim_mre->metric_preference_s();
	metric_preference &= ~PIM_ASSERT_RPT_BIT;
    } else {
	route_metric = pim_mre->route_metric_rp();
	metric_preference = pim_mre->metric_preference_rp();
	metric_preference |= PIM_ASSERT_RPT_BIT;
    }
    
    ret_value = pim_assert_send(assert_source_addr, assert_group_addr,
				group_masklen, route_metric,
				metric_preference);
    return (ret_value);
}

// XXX: applies only for (S,G) and (*,G)
int
PimVif::pim_assert_cancel_send(PimMre *pim_mre)
{
    IPvX	assert_source_addr(family());
    IPvX	assert_group_addr(family());
    const IPvX	*rp_addr_ptr;
    uint32_t	group_masklen;
    uint32_t	route_metric, metric_preference;
    int		ret_value;
    
    if (! (pim_mre->is_sg() || pim_mre->is_wc()))
	return (XORP_ERROR);
    
    // Prepare the Assert data
    if (pim_mre->is_sg() && pim_mre->is_spt()) {
	assert_source_addr = pim_mre->source_addr();
    } else {
	rp_addr_ptr = pim_mre->rp_addr_ptr();
	if (rp_addr_ptr != NULL)
	    assert_source_addr = *rp_addr_ptr;
    }
    assert_group_addr  = pim_mre->group_addr();
    group_masklen = IPvX::addr_bitlen(family());
    route_metric = PIM_ASSERT_MAX_METRIC;
    metric_preference = PIM_ASSERT_MAX_METRIC_PREFERENCE;
    if (pim_mre->is_sg() && pim_mre->is_spt())
	metric_preference &= ~PIM_ASSERT_RPT_BIT;
    else
	metric_preference |= PIM_ASSERT_RPT_BIT;
    
    ret_value = pim_assert_send(assert_source_addr, assert_group_addr,
				group_masklen, route_metric,
				metric_preference);
    return (ret_value);
}

int
PimVif::pim_assert_send(const IPvX& assert_source_addr,
			const IPvX& assert_group_addr,
			uint32_t group_masklen,
			uint32_t route_metric,
			uint32_t metric_preference)
{
    buffer_t *buffer = buffer_send_prepare();
    uint8_t group_addr_reserved_flags = 0;
    
    // Write all data to the buffer
    PUT_ENCODED_GROUP_ADDR(family(), assert_group_addr, group_masklen,
			   group_addr_reserved_flags, buffer);
    PUT_ENCODED_UNICAST_ADDR(family(), assert_source_addr, buffer);
    BUFFER_PUT_HOST_32(metric_preference, buffer);
    BUFFER_PUT_HOST_32(route_metric, buffer);
    
    return (pim_send(IPvX::PIM_ROUTERS(family()), PIM_ASSERT, buffer));
    
 invalid_addr_family_error:
    XLOG_ASSERT(false);
    XLOG_ERROR("TX %s from %s to %s: "
	       "invalid address family error = %d",
	       PIMTYPE2ASCII(PIM_ASSERT),
	       cstring(addr()),
	       cstring(IPvX::PIM_ROUTERS(family())),
	       family());
    return (XORP_ERROR);
    
 buflen_error:
    XLOG_ASSERT(false);
    XLOG_ERROR("TX %s from %s to %s: "
	       "packet cannot fit into sending buffer",
	       PIMTYPE2ASCII(PIM_ASSERT),
	       cstring(addr()),
	       cstring(IPvX::PIM_ROUTERS(family())));
    return (XORP_ERROR);
}

// Return true if I am better metric
bool
AssertMetric::is_better(AssertMetric *a)
{
    // The RPT flag: smaller is better
    if ( (! rpt_bit_flag()) && a->rpt_bit_flag())
	return (true);
    if (rpt_bit_flag() && (! a->rpt_bit_flag()))
	return (false);
    
    // The metric preference: smaller is better
    if (metric_preference() < a->metric_preference())
	return (true);
    if (metric_preference() > a->metric_preference())
	return (false);
    
    // The route metric: smaller is better
    if (route_metric() < a->route_metric())
	return (true);
    if (route_metric() > a->route_metric())
	return (false);
    
    // The IP address: bigger is better
    if (addr() > a->addr())
	return (true);
    
    return (false);
}

// TODO: XXX: PAVPAVPAV: cleanup/implement the timeout stuff below
#if 0 // TODO
static void
pim_mre_oifs_assert_rate_limit_timeout(void *data_pointer)
{
    PimMre *pim_mre;
    
    pim_mre = (PimMre *)data_pointer;

#if 0    // TODO
    pim_mre->oifs_assert_rate_limit()->reset();
#endif
}
#endif //0 TODO

#if 0 // TODO
static void
pim_upstream_nbr_asserted_timeout(void *data_pointer)
{
    PimMre *pim_mre;
    
    pim_mre = (PimMre *)data_pointer;
    
#if 0    
    family = IPADDR2FAMILY(MRE_GROUP_ADDRESS(pim_mre->mre));
#endif // 0
    
#if 0 // TODO
    pim_mre->set_upstream_nbr_asserted(NULL);
#endif
    
    // TODO: XXX: PAVPAV: reset the routing to the default upstream router
    // E.g. send a Join/Prune?
}
#endif // 0 TODO
