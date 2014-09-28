#include "linked_list.h"
#include "comparer.h"

static void __list_dispose(List *list);
static void __list_add(List *list, void *node);
static void __list_remove(List *list, void *node);
static Iterator __list_getIterator(List *list);
static BOOL __list_hasNext(List *list, Iterator *iter);
static void* __list_next(Iterator *iter);
static BOOL __list_contains(List *list, void *node);
static int __list_indexOf(List *list, void *node);
static void* __list_get(List *list, int index);
static int __list_size(List *list);
static BOOL __list_isEmpty(List *list);
static void __list_clear(List *list);
static void __list_sort(List *list);

List* createStringList(BOOL ingoreCase){
	List *linkedList = malloc(sizeof(List));
	if(!ingoreCase)
		__c_list(&linkedList->values, string_comparer);
	else
		__c_list(&linkedList->values, string_comparer_ignoreCase);
	linkedList->getIterator = __list_getIterator;
	linkedList->add = __list_add;
	linkedList->remove = __list_remove;
	linkedList->dispose=__list_dispose;
	linkedList->hasNext = __list_hasNext;
	linkedList->next = __list_next;
	linkedList->indexOf = __list_indexOf;
	linkedList->contains = __list_contains;
	linkedList->get = __list_get;
	linkedList->size = __list_size;
	linkedList->isEmpty = __list_isEmpty;
	linkedList->clear = __list_clear;
	linkedList->sort = __list_sort;
	return linkedList;
}

List* createList(){
	List *linkedList = malloc(sizeof(List));
	__c_list(&linkedList->values, 0);
	linkedList->getIterator = __list_getIterator;
	linkedList->add = __list_add;
	linkedList->remove = __list_remove;
	linkedList->dispose=__list_dispose;
	linkedList->hasNext = __list_hasNext;
	linkedList->next = __list_next;
	linkedList->indexOf = __list_indexOf;
	linkedList->contains = __list_contains;
	linkedList->get = __list_get;
	linkedList->size = __list_size;
	linkedList->isEmpty = __list_isEmpty;
	linkedList->clear = __list_clear;
	linkedList->sort = __list_sort;
	return linkedList;
}

static void __list_dispose(List *list){
	__c_tsil(&list->values);
	free(list);
}

static void __list_sort(List *list){
	c_list_sort(&list->values);
}

static void __list_add(List *list, void *node){
	c_list_insert(&list->values, c_list_end(&list->values), node);
}

static void __list_remove(List *list, void *node){
	c_list_remove(&list->values, node);
}

static Iterator __list_getIterator(List *list){
	c_iterator iter = c_list_begin(&list->values);
	return iter;
}

static BOOL __list_hasNext(List *list, Iterator *iter){
	c_iterator last = c_list_end(&list->values);
	return !ITER_EQUAL(*iter, last);
}

static BOOL __list_contains(List *list, void *node){
	return __list_indexOf(list, node)!=-1;
}

static int __list_indexOf(List *list, void *node){
	int index = 0;
	Iterator iter = list->getIterator(list);
	while(__list_hasNext(list, &iter)){
		void *temp = __list_next(&iter);
		if(temp == node || (list->values._cmp!=0 && list->values._cmp(temp, node) == 0))
			return index;
		else index++;
	}
	return -1;
}

static int __list_size(List *list){
	return c_list_size(&list->values);
}

static BOOL __list_isEmpty(List *list){
	return c_list_empty(&list->values);
}

static void __list_clear(List *list){
	c_list_clear(&list->values);
}

static void* __list_get(List *list, int index){
	Iterator iter;
	if(index<0 || index>=__list_size(list))
		return NULL;
	iter = list->getIterator(list);
	while(index>=0){
		void* temp = __list_next(&iter);
		if(index == 0)
			return temp;
		index--;
	}
	return NULL;
}

static void* __list_next(Iterator *iter){
	void* result = ITER_REF(*iter);
	ITER_INC(*iter);
	return result;
}



