#ifndef __UTIL_H_
#define __UTIL_H_

#include <stdlib.h>

#ifdef __GNUC__
#define THIS_FUNCTION_IS_DEPRECATED(func) func __attribute__ ((deprecated))
#else
#define THIS_FUNCTION_IS_DEPRECATED(func) func
#endif

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

char* trim(char *str);
char* split(char *str, char delimiter);
char* escape(const char *str, char escape);


#endif /*__UTIL_H_*/
