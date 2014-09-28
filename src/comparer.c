#include "comparer.h"
#include "cstring.h"

int string_comparer(void * x, void * y)
{
	return strcmp((char *)(x), (char *)(y));
}

int string_comparer_ignoreCase(void * x, void * y)
{
	return compareToIgnoreCase((char *)(x), (char *)(y));
}

int int_comparer(void * x, void * y)
{
	return *(int *)(x) - *(int *)(y);
}

int long_comparer(void * x, void * y)
{
	return *(long *)(x) - *(long *)(y);
}

int default_comparer(void * x, void * y)
{
	return ((long)x) -((long)y);
}