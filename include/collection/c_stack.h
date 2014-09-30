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

#ifndef _C_STACK_H
#define _C_STACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "c_def.h"
#include "c_iterator.h"


#define c_stack				_c_stack
#define c_pstack			_c_pstack
#define c_stack_create			__c_stack
#define c_stack_destroy			__c_kcats
#define c_stack_assign			_c_stack_assign
#define c_stack_empty			_c_stack_empty
#define c_stack_size			_c_stack_size
#define c_stack_top			_c_stack_top
#define c_stack_push			_c_stack_push
#define c_stack_pop			_c_stack_pop
#define c_stack_equal			_c_stack_equal
#define c_stack_less			_c_stack_less


typedef struct c_stack
{
	void * _l;
} c_stack, * c_pstack;

void __c_stack(c_pstack thiz, COMPARER pcmp);
void __c_kcats(c_pstack thiz);
c_pstack c_stack_assign(c_pstack thiz, const c_pstack S);
c_bool c_stack_empty(c_pstack thiz);
size_type c_stack_size(c_pstack thiz);
value_type c_stack_top(c_pstack thiz);
void c_stack_push(c_pstack thiz, const value_type val);
void c_stack_pop(c_pstack thiz);
c_bool c_stack_equal(c_pstack thiz, const c_pstack S);
c_bool c_stack_less(c_pstack thiz, const c_pstack S);

#ifdef __cplusplus
}
#endif

#endif /* _C_STACK_H */

