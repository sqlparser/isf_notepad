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

#include "c_queue.h"
#include "c_list.h"


void __c_queue(c_pqueue thiz, COMPARER pcmp)
{
	thiz->_l = __c_malloc(sizeof(c_list));
	__c_list((c_plist)thiz->_l, pcmp);
}

void __c_eueuq(c_pqueue thiz)
{
	__c_tsil((c_plist)thiz->_l);
	__c_free(thiz->_l);
}

c_pqueue c_queue_assign(c_pqueue thiz, const c_pqueue Q)
{	
	c_list_assign((c_plist)thiz->_l, (c_plist)Q->_l);
	return thiz;
}

c_bool c_queue_empty(c_pqueue thiz)
{
	return c_list_empty((c_plist)thiz->_l);
}

size_type c_queue_size(c_pqueue thiz)
{
	return c_list_size((c_plist)thiz->_l);
}

value_type c_queue_front(c_pqueue thiz)
{
	return c_list_front((c_plist)thiz->_l);
}

value_type c_queue_back(c_pqueue thiz)
{
	return c_list_back((c_plist)thiz->_l);
}

void c_queue_push(c_pqueue thiz, const value_type val)
{
	c_list_push_back((c_plist)thiz->_l, val);
}

void c_queue_pop(c_pqueue thiz)
{
	c_list_pop_front((c_plist)thiz->_l);
}

c_bool c_queue_equal(c_pqueue thiz, const c_pqueue Q)
{
	return c_list_equal((c_plist)thiz->_l, (c_plist)Q->_l);
}

c_bool c_queue_less(c_pqueue thiz, const c_pqueue Q)
{
	return c_list_less((c_plist)thiz->_l, (c_plist)Q->_l);
}
