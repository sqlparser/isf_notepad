#ifndef   LIFO_STACK_H
#define   LIFO_STACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "collection.h"
#include "c_stack.h"

typedef struct Stack
{
	PRIVATE c_stack values;
	void (*dispose)(struct Stack*);
	void * (*push)(struct Stack*, void *);
	void * (*pop)(struct Stack*);
	void * (*peek)(struct Stack*);
	int (*size)(struct Stack*);
	BOOL (*isEmpty)(struct Stack*);
	void (*clear)(struct Stack*);
}Stack;

Stack* createStack();

#ifdef __cplusplus
}
#endif

#endif /* LIFO_STACK_H */
