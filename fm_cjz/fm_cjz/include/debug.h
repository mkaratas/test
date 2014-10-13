/**
 * Author: Fred Cui
 * Email : cjzswust@gmail.com
 */
#ifndef __DEBUG_H_
#define __DEBUG_H_

#include <errno.h>
#include "util.h"

#define PRINT_END "\033[0m"

#define PRINT_BLACK	"\033[30m"
#define PRINT_RED		"\033[31m"
#define PRINT_GREEN	"\033[32m"
#define PRINT_YELLOW	"\033[33m"
#define PRINT_BLUE	"\033[34m"
#define PRINT_PURPLE	"\033[35m"
#define PRINT_AZURE	"\033[36m"
#define PRINT_WHITE	"\033[37m"

#define DEBUG_INFO

#ifdef DEBUG_INFO
#define LOGV(fmt, ...) \
	{printf("["PRINT_BLACK"%s"PRINT_END"]: "PRINT_BLACK fmt PRINT_END, "VERBOSE", ##__VA_ARGS__);}
#define LOGE(fmt, ...) \
	{printf("["PRINT_RED"%s"PRINT_END"]: %s in %s line: %d"PRINT_RED fmt PRINT_END, "ERROR", __func__, __FILE__, __LINE__, ##__VA_ARGS__);}
#define LOGW(fmt, ...) \
	{printf("["PRINT_YELLOW"%s"PRINT_END"]: %s (%s) "PRINT_YELLOW fmt PRINT_END, "WARNING", __func__, __FILE__, ##__VA_ARGS__);}
#define LOGD(fmt, ...) \
	{printf("["PRINT_BLUE"%s"PRINT_END"]: "PRINT_BLUE fmt PRINT_END, "DEBUG", ##__VA_ARGS__);}
#define LOGI(fmt, ...) \
	{printf("["PRINT_GREEN"%s"PRINT_END"]: "PRINT_GREEN fmt PRINT_END, "INFO", ##__VA_ARGS__);}
#else
#define LOGV(fmt, args...) 
#define LOGE(fmt, args...) 
#define LOGW(fmt, args...) 
#define LOGD(fmt, args...) 
#define LOGI(fmt, args...) 
#endif

#endif /*__DEBUG_H_*/
