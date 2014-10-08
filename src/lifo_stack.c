#include "lifo_stack.h"

static void __stack_dispose(Stack *stack);
static int __stack_size(Stack *stack);
static BOOL __stack_isEmpty(Stack *stack);
static void __stack_clear(Stack *stack);
static void* __stack_push(Stack *stack, void *element);
static void* __stack_pop(Stack *stack);
static void* __stack_peek(Stack *stack);

Stack* createStack(){
	Stack *lifoStack = malloc(sizeof(Stack));
	__c_stack(&lifoStack->values, 0);
	lifoStack->peek = __stack_peek;
	lifoStack->pop = __stack_pop;
	lifoStack->push = __stack_push;
	lifoStack->size = __stack_size;
	lifoStack->isEmpty = __stack_isEmpty;
	lifoStack->clear = __stack_clear;
	lifoStack->dispose = __stack_dispose;
	return lifoStack;
}


static void __stack_dispose(Stack *stack){
	 __c_kcats(&stack->values);
	 free(stack);
}

static void* __stack_push(Stack *stack, void *element){
	_c_stack_push(&stack->values, element);
	return element;
}

static void* __stack_pop(Stack *stack){
	void *element = _c_stack_top(&stack->values);
	_c_stack_pop(&stack->values);
	return element;
}

static void* __stack_peek(Stack *stack){
	return _c_stack_top(&stack->values);
}


static int __stack_size(Stack *stack){
	return _c_stack_size(&stack->values);
}

static BOOL __stack_isEmpty(Stack *stack){
	return _c_stack_empty(&stack->values);
}

static void __stack_clear(Stack *stack){
	while(!_c_stack_empty(&stack->values))
	{
		_c_stack_pop(&stack->values);
	}
}
