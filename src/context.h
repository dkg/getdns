/**
 *
 * /brief getdns contect management functions
 *
 * This is the meat of the API
 * Originally taken from the getdns API description pseudo implementation.
 *
 */
/* The MIT License (MIT)
 * Copyright (c) 2013 Verisign, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef _GETDNS_CONTEXT_H_
#define _GETDNS_CONTEXT_H_

#include <getdns/getdns.h>

/** function pointer typedefs */
typedef void (*getdns_update_callback)(getdns_context_t context, uint16_t changed_item);
typedef void* (*getdns_memory_allocator)(size_t size);
typedef void (*getdns_memory_deallocator)(void*);
typedef void* (*getdns_memory_reallocator)(void* ptr, size_t size);

struct getdns_context_t {

    /* Context values */
    uint16_t resolution_type;
    uint16_t *namespaces;
    uint16_t dns_transport;
    uint16_t limit_outstanding_queries;
    uint16_t timeout;
    uint16_t follow_redirects;
    struct getdns_list *dns_root_servers;
    uint16_t append_name;
    struct getdns_list *suffix;
    struct getdns_list *dnssec_trust_anchors;
    uint16_t dnssec_allow_skew;
    struct getdns_list *upstream_list;
    uint16_t edns_maximum_udp_payload_size;
    uint8_t edns_extended_rcode;
    uint8_t edns_version;
    uint8_t edns_do_bit;
    
    getdns_update_callback update_callback;
    getdns_memory_allocator memory_allocator;
    getdns_memory_deallocator memory_deallocator;
    getdns_memory_reallocator memory_reallocator;

    /* Event loop */
    struct event_base* event_base;
    
    /* outbound request dict (transaction -> req struct) */
    getdns_dict *outbound_reqs;

    /* socket */
    evutil_socket_t resolver_socket;
} ;

#endif
