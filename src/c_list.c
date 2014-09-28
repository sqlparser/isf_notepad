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

#include "c_list.h"
#include "c_algo.h"

typedef struct _A_list_node  _A_list_node;

struct _A_list_node {
	_A_list_node * _A_next;
	_A_list_node * _A_prev;
	void * _A_node;
};

static _A_list_node * _A_list_node_next(_A_list_node * thiz)
{
	return (thiz ? thiz->_A_next : NULL);
}

static _A_list_node * _A_list_node_prev(_A_list_node * thiz)
{
	return (thiz ? thiz->_A_prev : NULL);
}

static c_iterator _c_list_iterator_assign(c_piterator thiz, const c_piterator val)
{
	if(thiz != val)
		thiz->_i = val->_i;
	return *thiz;
}

static value_type _c_list_iterator_ref(c_piterator thiz)
{
	return ((_A_list_node *)thiz->_i)->_A_node;
}

static value_type _c_list_iterator_ref_assign(c_piterator thiz, const value_type val)
{
	return ((_A_list_node *)thiz->_i)->_A_node = val;
}

static c_iterator _c_list_iterator_inc(c_piterator thiz)
{
	thiz->_i = _A_list_node_next((_A_list_node *)thiz->_i);
	return *thiz;
}

static c_iterator _c_list_iterator_dec(c_piterator thiz)
{
	thiz->_i = _A_list_node_prev((_A_list_node *)thiz->_i);
	return *thiz;
}

static c_bool _c_list_iterator_equal(c_piterator thiz, const c_piterator val)
{
	return (thiz->_i == val->_i &&
				thiz->_pft == val->_pft);
}

static c_iterator_ft _c_list_iter_ft = 
{
	_c_list_iterator_assign,
	_c_list_iterator_ref,
	_c_list_iterator_ref_assign,
	_c_list_iterator_inc,
	NULL,   /* _c_list_iterator_inc_n */
	_c_list_iterator_dec,
	NULL,   /* _c_list_iterator_dec_n */
	NULL,   /* _c_list_iterator_diff */
	NULL,   /* _c_list_iterator_at */
	NULL,   /* _c_list_iterator_positive_n */
	NULL,   /* _c_list_iterator_negative_n */
	_c_list_iterator_equal,
	NULL,   /* _c_list_iterator_less */
};


static c_reverse_iterator _c_list_reverse_iterator_assign(c_preverse_iterator thiz, const c_preverse_iterator val)
{
	if(thiz != val)
		thiz->_i = val->_i;
	return *thiz;
}

static value_type _c_list_reverse_iterator_ref(c_preverse_iterator thiz)
{
	return ((_A_list_node *)thiz->_i)->_A_prev->_A_node;    
}

value_type _c_list_reverse_iterator_ref_assign(c_preverse_iterator thiz, const value_type val)
{
	return ((_A_list_node *)thiz->_i)->_A_node = val;    
}
    
static c_reverse_iterator _c_list_reverse_iterator_inc(c_preverse_iterator thiz)
{
	thiz->_i = _A_list_node_prev((_A_list_node *)thiz->_i);
	return *thiz;
}

static c_reverse_iterator _c_list_reverse_iterator_dec(c_preverse_iterator thiz)
{
	thiz->_i = _A_list_node_next((_A_list_node *)thiz->_i);
	return *thiz;
}

static c_bool _c_list_reverse_iterator_equal(c_preverse_iterator thiz, const c_preverse_iterator val)
{
	return (thiz->_i == val->_i &&
				thiz->_pft == val->_pft);
}

static c_reverse_iterator_ft _c_list_rev_iter_ft = 
{
	_c_list_reverse_iterator_assign,
	_c_list_reverse_iterator_ref,
	_c_list_reverse_iterator_ref_assign,
	_c_list_reverse_iterator_inc,
	NULL,   /* _c_list_reverse_iterator_inc_n */
	_c_list_reverse_iterator_dec,
	NULL,   /* _c_list_reverse_iterator_dec_n */
	NULL,   /* _c_list_reverse_iterator_diff */
	NULL,   /* _c_list_reverse_iterator_at */
	NULL,   /* _c_list_reverse_iterator_positive_n */
	NULL,   /* _c_list_reverse_iterator_negative_n */
	_c_list_reverse_iterator_equal,
	NULL,   /* _c_list_reverse_iterator_less */      
};

typedef struct _c_list_impl
{
	_A_list_node * _end_node;
} _c_list_impl;

static c_iterator _A_get_iterator(_A_list_node * val)
{
	c_iterator iter;
	iter._pft = &_c_list_iter_ft;
	iter._i = val;
	return iter;
}

static c_reverse_iterator _A_get_reverse_iterator(_A_list_node * val)
{
	c_reverse_iterator iter;
	iter._pft = &_c_list_rev_iter_ft;
	iter._i = val;
	return iter;    
}

static _A_list_node * _A_get_list_node(c_plist thiz)
{
	return __c_malloc(sizeof(_A_list_node));
}

static void _A_put_list_node(c_plist thiz, _A_list_node * p)
{
	__c_free(p);
}

static void _A_transfer(c_plist thiz, c_iterator pos, c_iterator first, c_iterator last)
{
	if(!ITER_EQUAL(first, last))
	{
		_A_list_node * tmp;
		((_A_list_node *)last._i)->_A_prev->_A_next = pos._i;
		((_A_list_node *)first._i)->_A_prev->_A_next = last._i;
		((_A_list_node *)pos._i)->_A_prev->_A_next = first._i;
        
		tmp = ((_A_list_node *)pos._i)->_A_prev;
		((_A_list_node *)pos._i)->_A_prev = ((_A_list_node *)last._i)->_A_prev;
		((_A_list_node *)last._i)->_A_prev = ((_A_list_node *)first._i)->_A_prev;
		((_A_list_node *)first._i)->_A_prev = tmp;
	}
}

void __c_list(c_plist thiz, COMPARER pcmp)
{
	_A_list_node * node;
	thiz->_cmp = pcmp;
	node = _A_get_list_node(thiz);
	node->_A_node = NULL;
	node->_A_next = node;
	node->_A_prev = node;
	thiz->_l = __c_malloc(sizeof(_c_list_impl));
	((_c_list_impl *)thiz->_l)->_end_node = node;
}

void __c_tsil(c_plist thiz)
{
	c_list_clear(thiz);
	_A_put_list_node(thiz, ((_c_list_impl *)thiz->_l)->_end_node);
	__c_free(thiz->_l);
}

c_iterator c_list_begin(c_plist thiz)
{
	return _A_get_iterator(((_c_list_impl *)thiz->_l)->_end_node->_A_next);
}

c_iterator c_list_end(c_plist thiz)
{
	return _A_get_iterator(((_c_list_impl *)thiz->_l)->_end_node);    
}

c_reverse_iterator c_list_rbegin(c_plist thiz)
{
	c_reverse_iterator riter = _A_get_reverse_iterator(NULL);
	c_iterator iter = c_list_end(thiz); 
	riter._i = iter._i;
	return riter;
}

c_reverse_iterator c_list_rend(c_plist thiz)
{
	c_reverse_iterator riter = _A_get_reverse_iterator(NULL);
	c_iterator iter = c_list_begin(thiz);
	riter._i = iter._i; 
	return riter;
}

size_t c_list_size(c_plist thiz)
{
	return c_distance(c_list_begin(thiz), c_list_end(thiz));
}
    
c_bool c_list_empty(c_plist thiz)
{
	_A_list_node * end_node = ((_c_list_impl *)thiz->_l)->_end_node;     
	return end_node == end_node->_A_next;
}

c_plist c_list_assign(c_plist thiz, const c_plist L)
{
	if(!c_list_equal(thiz, L))
	{
		c_iterator first1 = c_list_begin(thiz);
		c_iterator last1 = c_list_end(thiz);
		c_iterator first2 = c_list_begin(L);
		c_iterator last2 = c_list_end(L);
		while(!ITER_EQUAL(first1, last1) && 
				!ITER_EQUAL(first2, last2))
		{
			ITER_REF_ASSIGN(first1, ITER_REF(first2));
			ITER_INC(first1);
			ITER_INC(first2);
		}
		if(ITER_EQUAL(first2, last2))
			c_list_erase2(thiz, first1, last1); 
		else
			c_list_insert2(thiz, last1, first2, last2);            
	}
	return thiz;
}

value_type c_list_front(c_plist thiz)
{
	c_iterator iter = c_list_begin(thiz);
	return ITER_REF(iter); 
}

value_type c_list_back(c_plist thiz)
{
	c_iterator iter = c_list_end(thiz);
	ITER_DEC(iter); 
	return ITER_REF(iter); 
}

void c_list_push_front(c_plist thiz, const value_type val)
{
	c_list_insert(thiz, c_list_begin(thiz), val);
}

void c_list_push_back(c_plist thiz, const value_type val)
{
	c_list_insert(thiz, c_list_end(thiz), val);
}

void c_list_pop_front(c_plist thiz)
{
	c_list_erase(thiz, c_list_begin(thiz));
}

void c_list_pop_back(c_plist thiz)
{
	c_iterator iter = c_list_end(thiz);
	ITER_DEC(iter); 
	c_list_erase(thiz, iter);
}

void c_list_swap(c_plist thiz, c_plist L)
{
	c_list tmp = *thiz;
	*thiz = *L;
	*L = tmp;   
}

c_iterator c_list_insert(c_plist thiz, c_iterator pos, const value_type val)
{
	_A_list_node * node = _A_get_list_node(thiz);
	node->_A_node = val; 
	node->_A_next = (_A_list_node *)pos._i;
	node->_A_prev = ((_A_list_node *)pos._i)->_A_prev;
	((_A_list_node *)pos._i)->_A_prev->_A_next = node;
	((_A_list_node *)pos._i)->_A_prev = node;
	return _A_get_iterator(node);
}

void c_list_insert2(c_plist thiz, c_iterator pos, c_iterator first, c_iterator last)
{
	for(; !ITER_EQUAL(first, last); ITER_INC(first))
		c_list_insert(thiz, pos, ITER_REF(first)); 
}

c_iterator c_list_erase(c_plist thiz, c_iterator pos)
{
	c_iterator end = c_list_end(thiz); 
	if(!ITER_EQUAL(end, pos))
	{
		_A_list_node * next = ((_A_list_node *)pos._i)->_A_next;
		_A_list_node * prev = ((_A_list_node *)pos._i)->_A_prev;
		_A_list_node * nd = (_A_list_node *)pos._i;
		prev->_A_next = next;
		next->_A_prev = prev;
		_A_put_list_node(thiz, nd);
		return _A_get_iterator(next);   
	}
	return end;   
}

c_iterator c_list_erase2(c_plist thiz, c_iterator first, c_iterator last)
{
	while(!ITER_EQUAL(first, last))
		first = c_list_erase(thiz, first);
	return last;
}

void c_list_clear(c_plist thiz)
{
	_A_list_node * end_node = ((_c_list_impl *)thiz->_l)->_end_node;
	_A_list_node * iter = end_node->_A_next;
	while(iter != end_node)
	{
		_A_list_node * tmp = iter;
		iter = iter->_A_next;
		_A_put_list_node(thiz, tmp);
	}
	end_node->_A_next = end_node;
	end_node->_A_prev = end_node;
}

void c_list_splice(c_plist thiz, c_iterator pos, c_plist L)
{
	if(!c_list_empty(L))
		_A_transfer(thiz, pos, c_list_begin(L), c_list_end(L));
}

void c_list_splice1(c_plist thiz, c_iterator pos, c_plist L, c_iterator i)
{
	c_iterator j = i;
	ITER_INC(j);
	if(ITER_EQUAL(pos, i) || ITER_EQUAL(pos, j))
		return;
	_A_transfer(thiz, pos, i, j);
}

void c_list_splice2(c_plist thiz, c_iterator pos, c_plist L, c_iterator first, c_iterator last)
{
	if(!ITER_EQUAL(first, last))
		_A_transfer(thiz, pos, first, last);
}

void c_list_remove(c_plist thiz, value_type val)
{
	c_iterator iter = c_list_begin(thiz);
	c_iterator end = c_list_end(thiz);
	while(!ITER_EQUAL(iter, end))
	{
		c_iterator tmp = iter;
		ITER_INC(iter);
		if((ITER_REF(tmp) == val) ||
				(*thiz->_cmp!=NULL && !(*thiz->_cmp)(val, ((_A_list_node *)tmp._i)->_A_node)))
			c_list_erase(thiz, tmp);
	}
}

void c_list_unique(c_plist thiz)
{
	c_iterator first = c_list_begin(thiz); 
	c_iterator last = c_list_end(thiz);
	c_iterator next; 
	if(ITER_EQUAL(first, last))
		return;
	next = first;
	ITER_INC(next);
	while(!ITER_EQUAL(last, next))
	{
		if((*thiz->_cmp!=NULL &&!(*thiz->_cmp)(ITER_REF(first), ITER_REF(next))))
			c_list_erase(thiz, next); 
		else
			ITER_ASSIGN(first, next);
		ITER_ASSIGN(next, first);
		ITER_INC(next);
	}
}

void c_list_merge(c_plist thiz, c_plist L)
{
	c_iterator first1 = c_list_begin(thiz);
	c_iterator last1 = c_list_end(thiz);
	c_iterator first2 = c_list_begin(L);
	c_iterator last2 = c_list_end(L);
    
	while(!ITER_EQUAL(first1, last1) &&
			!ITER_EQUAL(first2, last2))
		if((*thiz->_cmp!=NULL &&(*thiz->_cmp)(ITER_REF(first2),
					ITER_REF(first1)) < 0))
		{
			c_iterator next = first2;
			_A_transfer(thiz, first1, first2, ITER_INC(next));
			ITER_ASSIGN(first2, next);
		}
		else
			ITER_INC(first1);
	if(!ITER_EQUAL(first2, last2))
		_A_transfer(thiz, last1, first2, last2);
}

void c_list_sort(c_plist thiz)
{
	_A_list_node * node = ((_c_list_impl *)thiz->_l)->_end_node;
    
	if(node->_A_next != node && node->_A_next->_A_next != node)
	{
		c_list cry;
		c_list cnt[64];
		int fill = 0, i = 0;
		__c_list(&cry, thiz->_cmp);
		for(fill = 0; fill < 64; ++ fill)
			__c_list(&cnt[fill], thiz->_cmp);
        	
		fill = 0;
		while(!c_list_empty(thiz))
		{
			c_list_splice1(&cry, c_list_begin(&cry), thiz, c_list_begin(thiz));
			i = 0;
			while(i < fill && !c_list_empty(&cnt[i]))
			{
				c_list_merge(&cnt[i], &cry);
				c_list_swap(&cry, &cnt[i ++]);
			}
			c_list_swap(&cry, &cnt[i]);
			if(i == fill)
				++ fill;
		}
		for(i = 1; i < fill; ++ i)
			c_list_merge(&cnt[i], &cnt[i - 1]);
		c_list_swap(thiz, &cnt[fill - 1]);
        
		__c_tsil(&cry);
		for(fill = 0; fill < 64; ++ fill)
			__c_tsil(&cnt[fill]);
	}
}

c_bool c_list_equal(c_plist thiz, const c_plist L)
{
	c_iterator end1 = c_list_end(thiz);
	c_iterator end2 = c_list_end(L);
	c_iterator i1 = c_list_begin(thiz);
	c_iterator i2 = c_list_begin(L);
    
	while(!ITER_EQUAL(i1, end1) &&
		!ITER_EQUAL(i2, end2) &&
		(*thiz->_cmp!=NULL &&!(*thiz->_cmp)(ITER_REF(i1), ITER_REF(i2))))
	{
		ITER_INC(i1);
		ITER_INC(i2);
	}
	return (ITER_EQUAL(i1, end1) && (ITER_EQUAL(i2, end2)));
}

c_bool c_list_less(c_plist thiz, const c_plist L)
{
	return c_lexicographical_compare(c_list_begin(thiz),
						c_list_end(thiz),
						c_list_begin(L),
						c_list_end(L), thiz->_cmp);
}

