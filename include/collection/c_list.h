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

#ifndef _C_LIST_H
#define _C_LIST_H

#include "c_def.h"
#include "c_iterator.h"
#include "c_memory.h"

#define c_list				_c_list
#define c_list_create			__c_list
#define c_list_destroy			__c_tsil
#define c_plist				_c_plist
#define c_list_begin			_c_list_begin 
#define c_list_end			_c_list_end
#define c_list_rbegin			_c_list_rbegin
#define c_list_rend			_c_list_rend
#define c_list_size			_c_list_size
#define c_list_empty			_c_list_empty
#define c_list_assign			_c_list_assign
#define c_list_front			_c_list_front
#define c_list_back			_c_list_back
#define c_list_push_front		_c_list_push_front		
#define c_list_push_back		_c_list_push_back
#define c_list_pop_front		_c_list_pop_front
#define c_list_pop_back			_c_list_pop_back
#define c_list_swap			_c_list_swap
#define c_list_insert			_c_list_insert
#define c_list_insert2			_c_list_insert2
#define c_list_erase			_c_list_erase
#define c_list_erase2			_c_list_erase2
#define c_list_clear			_c_list_clear
#define c_list_splice			_c_list_splice
#define c_list_splice1			_c_list_splice1
#define c_list_splice2			_c_list_splice2
#define c_list_remove			_c_list_remove
#define c_list_unique			_c_list_unique
#define c_list_merge			_c_list_merge
#define c_list_sort			_c_list_sort
#define c_list_equal			_c_list_equal
#define c_list_less			_c_list_less


typedef struct c_list
{
    COMPARER _cmp;   
    void * _l;
} c_list, * c_plist;


void __c_list(c_plist thiz, COMPARER pcmp);
void __c_tsil(c_plist thiz);
c_iterator c_list_begin(c_plist thiz);
c_iterator c_list_end(c_plist thiz);
c_reverse_iterator c_list_rbegin(c_plist thiz);
c_reverse_iterator c_list_rend(c_plist thiz);
size_t c_list_size(c_plist thiz);
c_bool c_list_empty(c_plist thiz);
c_plist c_list_assign(c_plist thiz, const c_plist L);
value_type c_list_front(c_plist thiz);
value_type c_list_back(c_plist thiz);
void c_list_push_front(c_plist thiz, const value_type val);
void c_list_push_back(c_plist thiz, const value_type val);
void c_list_pop_front(c_plist thiz);
void c_list_pop_back(c_plist thiz);
void c_list_swap(c_plist thiz, c_plist L);
c_iterator c_list_insert(c_plist thiz, c_iterator pos, const value_type val);
void c_list_insert2(c_plist thiz, c_iterator pos, c_iterator first, c_iterator last);
c_iterator c_list_erase(c_plist thiz, c_iterator pos);
c_iterator c_list_erase2(c_plist thiz, c_iterator first, c_iterator last);
void c_list_clear(c_plist thiz);
void c_list_splice(c_plist thiz, c_iterator pos, c_plist L);
void c_list_splice1(c_plist thiz, c_iterator pos, c_plist L, c_iterator i);
void c_list_splice2(c_plist thiz, c_iterator pos, c_plist L, c_iterator first, c_iterator last);
void c_list_remove(c_plist thiz, value_type val);
void c_list_unique(c_plist thiz);
void c_list_merge(c_plist thiz, c_plist L);
void c_list_sort(c_plist thiz);
c_bool c_list_equal(c_plist thiz, const c_plist L);
c_bool c_list_less(c_plist thiz, const c_plist L);



#endif /* _C_LIST_H */
