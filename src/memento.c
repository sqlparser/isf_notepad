#include "memento.h"

static Entry* __insertEntry(Memento *memento, void *key, void *value);
static void __clearMemento(Memento *memento);
static void __disposeMemento(Memento *memento);

Memento* createMemento()
{
	Memento *memento = (Memento *)malloc(sizeof(Memento));
	memento->insert = __insertEntry;
	memento->dispose = __disposeMemento;
	memento->clear = __clearMemento;
	memento->next = NULL;
	memento->end = NULL;
	return memento;
}

static Entry* __insertEntry(Memento *memento, void *key, void *value){
	if(memento->next == NULL){
		MementoFragment *fragment=(MementoFragment*)malloc(sizeof(MementoFragment));
		int count = 10;
		Entry *entry = (Entry*)malloc(sizeof(Entry)*count);
		fragment->count = count;
		fragment->index = 0;
		fragment->head = entry;
		fragment->next = NULL;
		entry->first = key;
		entry->second = value;
		memento->next = fragment;
		memento->end = fragment;
		return fragment->head;
	}
	else{
		MementoFragment *fragment = memento->end;
		if(fragment->index >= fragment->count-1){
			MementoFragment *newFragment=(MementoFragment*)malloc(sizeof(MementoFragment));
			int count = fragment->count*2;
			Entry *entry = (Entry*)malloc(sizeof(Entry)*count);
			newFragment->count = count;
			newFragment->index = 0;
			newFragment->head = entry;
			newFragment->next = NULL;
			entry->first = key;
			entry->second = value;
			memento->end->next = newFragment;
			memento->end = newFragment;
			return newFragment->head;
		}
		else{
			fragment->index++;
			fragment->head[fragment->index].first = key;
			fragment->head[fragment->index].second = value;
			return &fragment->head[fragment->index];
		}

	}
}

static void __clearMemento(Memento *memento){
	while(memento->next!=NULL){
		MementoFragment *head = memento->next;
		memento->next = head->next;
		free(head->head);
		free(head);
	}
}

static void __disposeMemento(Memento *memento){
	__clearMemento(memento);
	free(memento);
}
