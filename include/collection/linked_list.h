#ifndef   LINKED_LIST_H
#define   LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "c_list.h"
#include "collection.h"

typedef struct List
{
	PRIVATE c_list values;
	void (*dispose)(struct List*);
	void (*add)(struct List*, void *);
	void (*remove)(struct List*, void *);
	Iterator (*getIterator)(struct List*);
	BOOL (*hasNext)(struct List*, struct c_iterator*);
	void* (*next)(struct c_iterator*);
	int (*indexOf)(struct List*, void *);
	BOOL (*contains)(struct List*, void *);
	void* (*get)(struct List*, int index);
	int (*size)(struct List*);
	BOOL (*isEmpty)(struct List*);
	void (*clear)(struct List*);
	void (*sort)(struct List*);
}List;

List* createList();
List* createStringList(BOOL ingoreCase);

#ifdef __cplusplus
}
#endif

#endif /* LINKED_LIST_H */
