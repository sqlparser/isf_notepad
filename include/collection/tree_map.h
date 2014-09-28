#ifndef   TREE_MAP_H
#define   TREE_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "collection.h"
#include "memento.h"
#include "c_map.h"


typedef enum KeyType
{
	Map_KeyType_INT,
	Map_KeyType_LONG,
	Map_KeyType_STRING,
	Map_KeyType_DEFAULT
} KeyType;

typedef struct Map
{
	PRIVATE c_map values;
	PRIVATE Memento* entries;
	void (*dispose)(struct Map*);
	void (*put)(struct Map*, void *, void *);
	void (*remove)(struct Map*, void *);
	Iterator (*getIterator)(struct Map*);
	BOOL (*hasNext)(struct Map*, struct Iterator*);
	void* (*next)(struct Iterator*);
	BOOL (*containsKey)(struct Map*, void *);
	void* (*get)(struct Map*, void *);
	int (*size)(struct Map*);
	BOOL (*isEmpty)(struct Map*);
	void (*clear)(struct Map*);
}Map;

Map* createMap(KeyType keyType);
Map* createObjectMap();


#ifdef __cplusplus
}
#endif

#endif /* TREE_MAP_H */
