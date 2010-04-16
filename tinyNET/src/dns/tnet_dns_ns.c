/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/
/**@file tnet_dns_ns.c
 * @brief DNS Name Server record - RR - (RFC 1035).
 *
 * @author Mamadou Diop <diopmamadou(at)doubango.org>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tnet_dns_ns.h"

#include "tsk_string.h"
#include "tsk_memory.h"

//=================================================================================================
//	[[DNS NS]] object definition
//
static void* tnet_dns_ns_create(void * self, va_list * app)
{
	tnet_dns_ns_t *ns = self;
	if(ns)
	{
		const char* name = va_arg(*app, const char*);
		tnet_dns_qclass_t qclass = va_arg(*app, tnet_dns_qclass_t);
		uint32_t ttl = va_arg(*app, uint32_t);
#if defined(__GNUC__)
		uint16_t rdlength = (uint16_t)va_arg(*app, unsigned);
#else
		uint16_t rdlength = va_arg(*app, uint16_t);
#endif
		const void* data = va_arg(*app, const void*);
		size_t offset = va_arg(*app, size_t);

		/* init base */
		tnet_dns_rr_init(TNET_DNS_RR(ns), qtype_ns, qclass);
		TNET_DNS_RR(ns)->name = tsk_strdup(name);
		TNET_DNS_RR(ns)->rdlength = rdlength;
		TNET_DNS_RR(ns)->ttl = ttl;

		if(rdlength)
		{	// ==> DESERIALIZATION
			/* NSDNAME */
			tnet_dns_rr_qname_deserialize(data, &(ns->nsdname), &offset);
		}

	}
	return self;
}

static void* tnet_dns_ns_destroy(void * self) 
{ 
	tnet_dns_ns_t *ns = self;
	if(ns)
	{
		/* deinit base */
		tnet_dns_rr_deinit(TNET_DNS_RR(ns));

		TSK_FREE(ns->nsdname);
	}
	return self;
}

static const tsk_object_def_t tnet_dns_ns_def_s =
{
	sizeof(tnet_dns_ns_t),
	tnet_dns_ns_create,
	tnet_dns_ns_destroy,
	0,
};
const void *tnet_dns_ns_def_t = &tnet_dns_ns_def_s;