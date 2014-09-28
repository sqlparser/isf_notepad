#ifndef   MEMENTO_H
#define   MEMENTO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "collection.h"

typedef struct MementoFragment{
    Entry *head;
	int count;
	int index;
	struct MementoFragment *next;
}MementoFragment;

typedef struct Memento{
    PRIVATE struct MementoFragment *next;
	PRIVATE struct MementoFragment *end;
	Entry* (*insert)(struct Memento*, void *key, void *value);
	void (*dispose)(struct Memento*);
	void (*clear)(struct Memento*);
}Memento;


Memento* createMemento();

#ifdef __cplusplus
}
#endif

#endif /* MEMENTO_H */
