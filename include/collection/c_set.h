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

#ifndef _C_SET_H
#define _C_SET_H

#ifdef __cplusplus
extern "C" {
#endif

#include "c_tree.h"

#define c_set				_c_set
#define c_pset				_c_pset
#define c_set_create			__c_set
#define c_set_destroy			__c_tes
#define c_set_assign			_c_set_assign
#define c_set_begin			_c_set_begin
#define c_set_end			_c_set_end
#define c_set_rbegin			_c_set_rbegin
#define c_set_rend			_c_set_rend
#define c_set_empty			_c_set_empty
#define c_set_size			_c_set_size
#define c_set_max_size			_c_set_max_size
#define c_set_swap			_c_set_swap
#define c_set_insert			_c_set_insert
#define c_set_insert1			_c_set_insert1
#define c_set_insert2			_c_set_insert2
#define c_set_erase			_c_set_erase
#define c_set_erase1			_c_set_erase1
#define c_set_erase2			_c_set_erase2
#define c_set_clear			_c_set_clear
#define c_set_find			_c_set_find
#define c_set_count			_c_set_count
#define c_set_lower_bound		_c_set_lower_bound
#define c_set_upper_bound		_c_set_upper_bound
#define c_set_equal_range		_c_set_equal_range
#define c_set_less			_c_set_less
#define c_set_equal			_c_set_equal


typedef struct c_set
{
	void * _l;
} c_set, * c_pset;


void __c_set(c_pset thiz, COMPARER pcmp);
void __c_tes(c_pset thiz);
c_pset c_set_assign(c_pset thiz, const c_pset S);
c_iterator c_set_begin(c_pset thiz);
c_iterator c_set_end(c_pset thiz);
c_reverse_iterator c_set_rbegin(c_pset thiz);
c_reverse_iterator c_set_rend(c_pset thiz);
c_bool c_set_empty(c_pset thiz);
size_type c_set_size(c_pset thiz);
size_type c_set_max_size(c_pset thiz);
void c_set_swap(c_pset thiz, c_pset S);
c_iter_bool_pair c_set_insert(c_pset thiz, const value_type val);
c_iterator c_set_insert1(c_pset thiz, c_iterator position, const value_type val);
void c_set_insert2(c_pset thiz, c_iterator first, c_iterator last);
void c_set_erase(c_pset thiz, c_iterator position);
size_type c_set_erase1(c_pset thiz, key_type key);
void c_set_erase2(c_pset thiz, c_iterator first, c_iterator last);
void c_set_clear(c_pset thiz);
c_iterator c_set_find(c_pset thiz, key_type key);
size_type c_set_count(c_pset thiz, key_type key);
c_iterator c_set_lower_bound(c_pset thiz, key_type key);
c_iterator c_set_upper_bound(c_pset thiz, key_type key);
c_iter_iter_pair c_set_equal_range(c_pset thiz, key_type key);
c_bool c_set_less(c_pset thiz, const c_pset S);
c_bool c_set_equal(c_pset thiz, const c_pset S);

#ifdef __cplusplus
}
#endif

#endif /* _C_SET_H */
