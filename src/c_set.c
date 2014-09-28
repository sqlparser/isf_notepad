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

#include "c_set.h"


void __c_set(c_pset thiz, COMPARER pcmp)
{
	c_prb_tree ptree = (c_prb_tree)__c_malloc(sizeof(c_rb_tree));
	__c_rb_tree(ptree, pcmp);
	ptree->_A_keyofvalue = c_identity();
	thiz->_l = ptree;	
}

void __c_tes(c_pset thiz)
{
	__c_eert_br((c_prb_tree)thiz->_l);
	__c_free(thiz->_l);
}

c_pset c_set_assign(c_pset thiz, const c_pset S)
{
	c_rb_tree_assign((c_prb_tree)thiz->_l, (c_prb_tree)S->_l);
	return thiz;
}

c_iterator c_set_begin(c_pset thiz)
{
	return c_rb_tree_begin((c_prb_tree)thiz->_l);
}

c_iterator c_set_end(c_pset thiz)
{
	return c_rb_tree_end((c_prb_tree)thiz->_l);
}

c_reverse_iterator c_set_rbegin(c_pset thiz)
{
	return c_rb_tree_rbegin((c_prb_tree)thiz->_l);
}

c_reverse_iterator c_set_rend(c_pset thiz)
{
	return c_rb_tree_rend((c_prb_tree)thiz->_l);
}

c_bool c_set_empty(c_pset thiz)
{
	return c_rb_tree_empty((c_prb_tree)thiz->_l);
}

size_type c_set_size(c_pset thiz)
{
	return c_rb_tree_size((c_prb_tree)thiz->_l);
}

size_type c_set_max_size(c_pset thiz)
{
	return c_rb_tree_max_size((c_prb_tree)thiz->_l);
}

void c_set_swap(c_pset thiz, c_pset S)
{
	c_rb_tree_swap((c_prb_tree)thiz->_l, (c_prb_tree)S->_l);
}

c_iter_bool_pair c_set_insert(c_pset thiz, const value_type val)
{
	return c_rb_tree_insert_unique((c_prb_tree)thiz->_l, val);
}

c_iterator c_set_insert1(c_pset thiz, c_iterator position, const value_type val)
{
	return c_rb_tree_insert_unique1((c_prb_tree)thiz->_l, position, val);
}

void c_set_insert2(c_pset thiz, c_iterator first, c_iterator last)
{
	c_rb_tree_insert_unique2((c_prb_tree)thiz->_l, first, last);
}

void c_set_erase(c_pset thiz, c_iterator position)
{
	c_rb_tree_erase((c_prb_tree)thiz->_l, position);
}

size_type c_set_erase1(c_pset thiz, key_type key)
{
	return c_rb_tree_erase1((c_prb_tree)thiz->_l, key);
}

void c_set_erase2(c_pset thiz, c_iterator first, c_iterator last)
{
	c_rb_tree_erase2((c_prb_tree)thiz->_l, first, last);
}

void c_set_clear(c_pset thiz)
{
	c_rb_tree_clear((c_prb_tree)thiz->_l);
}

c_iterator c_set_find(c_pset thiz, key_type key)
{
	return c_rb_tree_find((c_prb_tree)thiz->_l, key);
}

size_type c_set_count(c_pset thiz, key_type key)
{
	c_iterator key_iter = c_rb_tree_find((c_prb_tree)thiz->_l, key);
	c_iterator end = c_rb_tree_end((c_prb_tree)thiz->_l);
	return ITER_EQUAL(key_iter, end) ? 0 : 1;
}

c_iterator c_set_lower_bound(c_pset thiz, key_type key)
{
	return c_rb_tree_lower_bound((c_prb_tree)thiz->_l, key);
}

c_iterator c_set_upper_bound(c_pset thiz, key_type key)
{
	return c_rb_tree_upper_bound((c_prb_tree)thiz->_l, key);
}

c_iter_iter_pair c_set_equal_range(c_pset thiz, key_type key)
{
	return c_rb_tree_equal_range((c_prb_tree)thiz->_l, key);
}

c_bool c_set_less(c_pset thiz, const c_pset S)
{
	return c_rb_tree_less((c_prb_tree)thiz->_l, 
				(c_prb_tree)S->_l,
		       		((c_prb_tree)S->_l)->_A_key_compare);
}

c_bool c_set_equal(c_pset thiz, const c_pset S)
{
	return c_rb_tree_equal((c_prb_tree)thiz->_l, 
				(c_prb_tree)S->_l,
		       		((c_prb_tree)S->_l)->_A_key_compare);
}

