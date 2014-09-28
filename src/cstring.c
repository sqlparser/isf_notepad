#include "cstring.h"

void substring(char *dest,char *src,int start,int end)  
{  
    int i=start;  
    if(start>(int)strlen(src))return;  
    if(end>(int)strlen(src))  
        end=(int)strlen(src);  
    while(i<end)  
    {     
        dest[i-start]=src[i];  
        i++;  
    }  
    dest[i-start]='\0';  
    return;  
} 

char charAt(char *src,int index)  
{  
    char *p=src;  
    int i=0;  
    if(index<0||index>(int)strlen(src))  
        return 0;  
    while(i<index)i++;  
    return p[i];  
} 

int indexOf(char *str1,char *str2)  
{  
    char *p=str1;  
    int i=0;  
    p=strstr(str1,str2);  
    if(p==NULL)  
        return -1;  
    else{  
        while(str1!=p)  
        {  
            str1++;  
            i++;  
        }  
    }  
    return i;  
}  

int lastIndexOf(char *str1,char *str2)  
{  
    char *p=str1;  
    int i=0,len=strlen(str2);  
    p=strstr(str1,str2);  
    if(p==NULL)return -1;  
    while(p!=NULL)  
    {  
        for(;str1!=p;str1++)i++;  
        p=p+len;  
        p=strstr(p,str2);  
    }  
    return i;  
}  

char* toUpperCase(char* str){
	char *c;
	for(c=str; c && *c; ++c) {
		*c = toupper(*c);
	}
	return str;
}

char* toLowerCase(char* str){
	char *c;
	for(c=str; c && *c; ++c) {
		*c = tolower(*c);
	}
	return str;
}

char* toInitCapCase(char* str){
	char *c;
	int i = 0;
	for(c=str; c && *c; ++c) {
		if(i==0){
			*c = toupper(*c);
		}
		else{
			*c = tolower(*c);
		}
		i++;
	}
	return str;
}

char* toInitCapCaseFromSecondChar(char* str){
	char *c;
	int i = 0;
	for(c=str; c && *c; ++c) {
		if(i==0){
			*c = tolower(*c);
		}
		else{
			*c = toupper(*c);
		}
		i++;
	}
	return str;
}

char* trimString(char * str)
{
	char *s=0, *e=0;
	char *c;
	for(c=str; c && *c; ++c) {
		if(isspace(*c)) {
			if(!e) {
				e = c;
			}
		} else {
			if(!s) {
				s = c;
			}
			e = 0;
		}
	}
	if(!s) s = str;
	if(e) *e = 0;
	return s;
}

BOOL replaceString(char *sSrc, char *sMatchStr, char *sReplaceStr)
{
	int  StringLen;
	char caNewString[STRING_REPLACE_LEN];

	char *FindPos = strstr(sSrc, sMatchStr);
	if( (!FindPos) || (!sMatchStr) )
		return FALSE;

	while( FindPos )
	{
		memset(caNewString, 0, sizeof(caNewString));
		StringLen = FindPos - sSrc;
		strncpy(caNewString, sSrc, StringLen);
		strcat(caNewString, sReplaceStr);
		strcat(caNewString, FindPos + strlen(sMatchStr));
		strcpy(sSrc, caNewString);

		FindPos = strstr(sSrc, sMatchStr);
	}

	return TRUE;
}

int compareToIgnoreCase(char *str1, char *str2) {
	char *p1, *p2;
	int i = 0, len = 0;
	if (str1 == NULL) {
		if (str2 != NULL)
			return -1;
		if (str2 == NULL)
			return 0;
	}
	p1 = str1;
	p2 = str2;
	len = (strlen(str1) < strlen(str2)) ? strlen(str1) : strlen(str2);
	for (i = 0; i < len; i++) {
		if (toupper(*p1) == toupper(*p2)) {
			p1++;
			p2++;
		} else
			return toupper(*p1) - toupper(*p2);
	}
	return strlen(str1) - strlen(str2);
}

int compareTo(char *str1, char *str2) {
	char *p1, *p2;
	int i = 0, len = 0;
	if (str1 == NULL) {
		if (str2 != NULL)
			return -1;
		if (str2 == NULL)
			return 0;
	}
	p1 = str1;
	p2 = str2;
	len = (strlen(str1) < strlen(str2)) ? strlen(str1) : strlen(str2);
	for (i = 0; i < len; i++) {
		if (*p1 == *p2) {
			p1++;
			p2++;
		} else
			return *p1 - *p2;
	}
	return strlen(str1) - strlen(str2);
}

BOOL startsWithIgnoreCase(char *str1, char *str2) {
	char *p1, *p2;
	int i = 0, len = 0;
	if (str1 == NULL) {
		if (str2 != NULL)
			return FALSE;
		if (str2 == NULL)
			return TRUE;
	}
	p1 = str1;
	p2 = str2;
	if((strlen(str1) < strlen(str2)))
		return FALSE;
	len = strlen(str2);
	for (i = 0; i < len; i++) {
		if (toupper(*p1) == toupper(*p2)) {
			p1++;
			p2++;
		} else
			return FALSE;
	}
	return TRUE;
}

BOOL startsWith(char *str1, char *str2) {
	char *p1, *p2;
	int i = 0, len = 0;
	if (str1 == NULL) {
		if (str2 != NULL)
			return FALSE;
		if (str2 == NULL)
			return TRUE;
	}
	p1 = str1;
	p2 = str2;
	if((strlen(str1) < strlen(str2)))
		return FALSE;
	len = strlen(str2);
	for (i = 0; i < len; i++) {
		if (*p1 == *p2) {
			p1++;
			p2++;
		} else
			return FALSE;
	}
	return TRUE;
}

BOOL endsWithIgnoreCase(char* str, char* substr)
{
	int res = FALSE;
	int length_sub = strlen(substr);
	int length_str = strlen(str);
	int str_pos = length_str - length_sub;
	int i = 0;

	if(str_pos < 0)
	{
		return res;
	}
	for(i = 0;i < length_sub;i++)
	{
		if(toupper(str[i+str_pos]) != toupper(substr[i]))
			break;
	}
	if(i == length_sub)
		res = TRUE;
	return res ;
}

BOOL endsWith(char* str,char* substr)
{
	int res = FALSE;
	int length_sub = strlen(substr);
	int length_str = strlen(str);
	int str_pos = length_str - length_sub;
	int i = 0;

	if(str_pos < 0)
	{
		return res;
	}
	for(i = 0;i < length_sub;i++)
	{
		if(str[i+str_pos] != substr[i])
			break;
	}
	if(i == length_sub)
		res = TRUE;
	return res ;
}

/*-------------------------------------------------------------------------*
 * CStr
 *-------------------------------------------------------------------------*/

char* CStrAlloc(int size)
{
	char* newStr = (char*) malloc( sizeof(char) * (size) );
	return newStr;
}

char* CStrCopy(const char* old)
{
	int len = strlen(old);
	char* newStr = CStrAlloc(len + 1);
	strcpy(newStr, old);
	return newStr;
}

/*-------------------------------------------------------------------------*
 * CString
 *-------------------------------------------------------------------------*/

void CStringInit(CString* str)
{
	str->length = 0;
	str->size = STRING_MAX;
	str->buffer = (char*) malloc(sizeof(char) * str->size);
	str->buffer[0] = '\0';
}

CString* CStringNew(void)
{
	CString* str = (CString*) malloc(sizeof(CString));
	str->length = 0;
	str->size = STRING_MAX;
	str->buffer = (char*) malloc(sizeof(char) * str->size);
	str->buffer[0] = '\0';
	return str;
}

void CStringDelete(CString *str)
{
        if (!str) return;
        free(str->buffer);
        free(str);
}

void CStringDeleteWithoutBuffer(CString *str)
{
	if (!str) return;
	free(str);
}

void CStringResize(CString* str, int newSize)
{
	str->buffer = (char*) realloc(str->buffer, sizeof(char) * newSize);
	str->size = newSize;
}

void CStringAppend(CString* str, const char* text)
{
	int length;

	if (text == NULL) {
		text = "NULL";
	}

	length = strlen(text);
	if (str->length + length + 1 >= str->size)
		CStringResize(str, str->length + length + 1 + STRING_INC);
	str->length += length;
	strcat(str->buffer, text);
}

void CStringNAppend(CString* str, const char* text, int number)
{
	int length;
	BOOL useN = FALSE;
	if (text == NULL) {
		text = "NULL";
	}

	length = strlen(text);
	if(length>number){
		length = number;
		useN = TRUE;
	}

	if (str->length + length + 1 >= str->size)
		CStringResize(str, str->length + length + 1 + STRING_INC);
	str->length += length;

	if(useN){
		strncat(str->buffer, text, length);
	}
	else{
		strcat(str->buffer, text);
	}
}

void CStringAppendChar(CString* str, char ch)
{
	char text[2];
	text[0] = ch;
	text[1] = '\0';
	CStringAppend(str, text);
}

void CStringAppendFormat(CString* str, const char* format, ...)
{
	va_list argp;
	char buf[HUGE_STRING_LEN];
	va_start(argp, format);
	vsprintf(buf, format, argp);
	va_end(argp);
	CStringAppend(str, buf);
}

void CStringInsert(CString* str, const char* text, int pos)
{
	int length = strlen(text);
	if (pos > str->length)
		pos = str->length;
	if (str->length + length + 1 >= str->size)
		CStringResize(str, str->length + length + 1 + STRING_INC);
	memmove(str->buffer + pos + length, str->buffer + pos, (str->length - pos) + 1);
	str->length += length;
	memcpy(str->buffer + pos, text, length);
}
