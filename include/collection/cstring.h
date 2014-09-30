#ifndef   C_STRING_H
#define   C_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "collection.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

/* CString */

char* CStrAlloc(int size);
char* CStrCopy(const char* old);

#define C_ALLOC(TYPE)		((TYPE*) malloc(sizeof(TYPE)))

#define HUGE_STRING_LEN	8192
#define STRING_MAX		256
#define STRING_INC		256
#define STRING_REPLACE_LEN	1024

typedef struct
{
	int length;
	int size;
	char* buffer;
} CString;

void CStringInit(CString* str);
CString* CStringNew(void);
void CStringRead(CString* str, const char* path);
void CStringAppend(CString* str, const char* text);
void CStringNAppend(CString* str, const char* text, int number);
void CStringAppendChar(CString* str, char ch);
void CStringAppendFormat(CString* str, const char* format, ...);
void CStringInsert(CString* str, const char* text, int pos);
void CStringResize(CString* str, int newSize);
void CStringDelete(CString* str);
void CStringDeleteWithoutBuffer(CString *str);

void substring(char *dest,char *src,int start,int end);
char charAt(char *src,int index);
int indexOf(char *str1,char *str2);
int lastIndexOf(char *str1,char *str2);
char* trimString(char * str);
char* toUpperCase(char* str);
char* toLowerCase(char* str);
char* toInitCapCase(char* str);
char* toInitCapCaseFromSecondChar(char* str);
BOOL replaceString(char *sSrc, char *sMatchStr, char *sReplaceStr);
int compareToIgnoreCase(char *str1, char *str2);
int compareTo(char *str1, char *str2);
BOOL startsWithIgnoreCase(char *str1, char *str2);
BOOL startsWith(char *str1, char *str2);
BOOL endsWithIgnoreCase(char* str, char* substr);
BOOL endsWith(char* str, char* substr);

#ifdef __cplusplus
}
#endif

#endif /* C_STRING_H */
