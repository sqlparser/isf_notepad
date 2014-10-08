#ifndef   COMPARER_H
#define   COMPARER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "collection.h"

int string_comparer(void * x, void * y);
int string_comparer_ignoreCase(void * x, void * y);
int int_comparer(void * x, void * y);
int long_comparer(void * x, void * y);
int default_comparer(void * x, void * y);


#ifdef __cplusplus
}
#endif

#endif /* COMPARER_H */
