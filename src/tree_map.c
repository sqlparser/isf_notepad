#include "tree_map.h"
#include "comparer.h"

static void __map_dispose(Map *map);
static void __map_remove(Map *map, void *key);
static Iterator __map_getIterator(Map *map);
static BOOL __map_hasNext(Map *map, Iterator *iter);
static void* __map_next(Iterator *iter);
static BOOL __map_containsKey(Map *map, void *key);
static void* __map_get(Map *map, void *key);
static int __map_size(Map *map);
static BOOL __map_isEmpty(Map *map);
static void __map_clear(Map *map);
static void __map_put(Map *map, void *key, void *value);

Map* createMap(KeyType keyType){
	Map *treeMap = (Map *)malloc(sizeof(Map));
	COMPARER comparer;
	switch(keyType){
	case Map_KeyType_INT:
			comparer = int_comparer;
			break;
		case Map_KeyType_LONG:
			comparer = long_comparer;
			break;
		case Map_KeyType_STRING:
			comparer = string_comparer;
			break;
		default:
			comparer = default_comparer;
			break;
	};
	c_map_create(&treeMap->values, comparer);
	treeMap->entries = createMemento();
	treeMap->getIterator = __map_getIterator;
	treeMap->put = __map_put;
	treeMap->remove = __map_remove;
	treeMap->dispose=__map_dispose;
	treeMap->hasNext = __map_hasNext;
	treeMap->next = __map_next;
	treeMap->containsKey = __map_containsKey;
	treeMap->get = __map_get;
	treeMap->size = __map_size;
	treeMap->isEmpty = __map_isEmpty;
	treeMap->clear = __map_clear;
	return treeMap;
}

Map* createObjectMap(){
	return createMap(Map_KeyType_DEFAULT);
}

static void __map_dispose(Map *map){
	c_map_destroy(&map->values);
	map->entries->dispose(map->entries);
	free(map);
}

static void __map_put(Map *map, void *key, void *value){
	Entry *entry = map->entries->insert(map->entries, key, value);
	c_map_insert(&map->values, entry);
}

static void __map_remove(Map *map, void *key){
	Iterator target, map_end;
	target = c_map_find(&map->values, key);
	map_end = c_map_end(&map->values);
	if(!ITER_EQUAL(map_end, target))
	{
		c_map_erase(&map->values, target);
	}
}

static Iterator __map_getIterator(Map *map){
	c_iterator iter = c_map_begin(&map->values);
	return iter;
}

static BOOL __map_hasNext(Map *map, Iterator *iter){
	c_iterator last = c_map_end(&map->values);
	return !ITER_EQUAL(*iter, last);
}

static BOOL __map_containsKey(Map *map, void *key){
	Iterator target, map_end;
	target = c_map_find(&map->values, key);
	map_end = c_map_end(&map->values);
	if( !ITER_EQUAL(map_end ,target ))
		return TRUE;
	else return FALSE;
}

static int __map_size(Map *map){
	return c_map_size(&map->values);
}

static BOOL __map_isEmpty(Map *map){
	return c_map_empty(&map->values);
}

static void __map_clear(Map *map){
	c_map_clear(&map->values);
	map->entries->clear(map->entries);
}

static void* __map_get(Map *map, void* key){
	if(!__map_containsKey(map, key))
		return NULL;
	return c_map_at(&map->values, key);
}

static void* __map_next(Iterator *iter){
	c_ppair result = (c_ppair)ITER_REF(*iter);
	ITER_INC(*iter);
	return result->first;
}



