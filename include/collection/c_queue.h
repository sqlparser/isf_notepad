/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 *
 * Copyright (c) 1996
 * Silicon Graphics Computer Systems, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */

/*
Copyright (c) 2007 Lao wen bo

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.

	Lao wen bo 
	viewpl(at)gmail.com
 */

#ifndef _C_QUEUE_H
#define _C_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "c_def.h"
#include "c_iterator.h"


#define c_queue				_c_queue
#define c_pqueue			_c_pqueue
#define c_queue_create			__c_queue
#define c_queue_destroy			__c_eueuq
#define c_queue_assign			_c_queue_assign
#define c_queue_empty			_c_queue_empty
#define c_queue_size			_c_queue_size
#define c_queue_front			_c_queue_front
#define c_queue_back			_c_queue_back
#define c_queue_push			_c_queue_push
#define c_queue_pop			_c_queue_pop
#define c_queue_equal			_c_queue_equal
#define c_queue_less			_c_queue_less


typedef struct c_queue
{
	void * _l;
} c_queue, * c_pqueue;


void __c_queue(c_pqueue thiz, COMPARER pcmp);
void __c_eueuq(c_pqueue thiz);
c_pqueue c_queue_assign(c_pqueue thiz, const c_pqueue Q);
c_bool c_queue_empty(c_pqueue thiz);
size_type c_queue_size(c_pqueue thiz);
value_type c_queue_front(c_pqueue thiz);
value_type c_queue_back(c_pqueue thiz);
void c_queue_push(c_pqueue thiz, const value_type val);
void c_queue_pop(c_pqueue thiz);
c_bool c_queue_equal(c_pqueue thiz, const c_pqueue Q);
c_bool c_queue_less(c_pqueue thiz, const c_pqueue Q);

#ifdef __cplusplus
}
#endif

#endif /* _C_QUEUE_H */

