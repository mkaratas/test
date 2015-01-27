/* marco.h -- head file
 *
 * Written by Jianzhong Cui, 2014 (cjzswust@gmail.com)
 * Copyright (C) 2014 Jianzhong Cui
 * 
 * Brief:
 *    This file is a set of stardand marco extanded in Gnu C 
 */

#ifndef __MARCO_HEAD_H__

/********************************** COPYRIGHT BEGIN **********************************/
#define COMPILE_DATE __DATE__
#define COMPILE_TIME __TIME__

/* FIXED STRINGS, Don't touch */
const char banner[] = 
"=========================================================\n\
NAME    : %s\n\
Author  : Fred Cui \n\
Email   : cjzswust@gmail.com \n\
Date    : %s \n\
Time    : %s \n\
==========================================================\n";

#define PRINT_BANNER(NAME) printf(banner, #NAME,  COMPILE_DATE, COMPILE_TIME)
#define BANNER(NAME) banner, #NAME, COMPILE_DATE, COMPILE_TIME

/********************************** COPYRIGHT END **********************************/

/*
 * These extensions are officially claimed in GCC Manual. 
 * More details you can visit gcc onlinedocs
 * Website: https://gcc.gnu.org/onlinedocs/
 */
/********************************* GNUC EXTENSIONS **********************************/
#ifdef __GNUC__
/* caculate maximum and minimum of two parameter 
 * maxint(a, b)  return max value between a and b
 * minint(a, b)  return min value between a and b
 *
 * max(a, b)
 * min(a, b)
 * 
 * usually #define max(a, b) (a>b)?(a):(b) can lead to a incorrect result by caculate twice.
 * eg: max(n1++, n2--)
 */
#define maxint(a, b) \
	({ int _a = (a), _b = (b); _a > _b ? _a : _b; })

#define minint(a, b) \
	({ int _a = (a), _b = (b); _a < _b ? _a : _b; })

#define max(a, b) \
	({typeof(a) _a = (a); typeof(b) _b = (b); _a > _b ? _a : _b; })

#define min(a, b) \
	({typeof(a) _a = (a); typeof(b) _b = (b); _a < _b ? _a : _b; })


#define ACCESS_ONCE(x) ( *(volatile typeof(x)*)&(x))

/*
 * You can define another function in other files while you already defined a 
 * function modified with __weak. If the outside function compiled, the aplication
 * will use that one, otherwise it will use the one modified with __weak
 * A file
 * void hello() {
 *		printf("hello in a file\n");	 
 * }
 * int main(int argc, char **argv) {
 * 		hello();
 * }
 *
 * B file
 * void hello() {
 *		printf("hello in b file\n");
 * }
 */
#define __weak __attribute((weak))

/*
 * The __constructor attribute causes the function to be called automatically before
 * execution enters main(). Similarly, the __destructor attribute causes the function
 * to be called automatically after main() completes or exit() is called.
 */
#define __constructor __attribute__((constructor))
#define __destructor __attribute__((destructor))

/*
 * The __deprecated attribute results in a warning if the function is uesd anywhere
 * in the source file. This is useful when identifying functions that are expected 
 * to be removed in a future version of a program.
 */
#define __deprecated __attribute__((deprecated))


#define __packed __attribute__((packed))

#endif /* GNUC */

/*************************** GNUC EXTENSIONS END ********************************/

/****************************** DEBUG BEGIN *************************************/
/*
 * Debug print information format macro define
 * if defined COLOR_DEBUG, the debug message will be printed with different colors
 * if defined DEBUG      , the debug message will be printed in black
 * if neither COLOR_DEBUG nor DEBUG is defined , nothing will be printed, this is usually
 * used to beautify output and optimize performance.
 */

#define COLOR_BLACK "\033[30m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_PURPLE "\033[35m"
#define COLOR_SKY "\033[36m"
#define COLOR_WHITE "\033[37m"

#define COLOR_END "\033[0m"

#define __COLOR_FORMAT(format, color) \
	COLOR_##color format COLOR_END

#define COLOR_DEBUG

#ifdef COLOR_DEBUG
#define debug_info(format, ...) fprintf(stdout, __COLOR_FORMAT(format, BLACK), __VA_ARGS__)
#define debug_warning(format, ...) fprintf(stderr, __COLOR_FORMAT(format, YELLOW), __VA_ARGS__)
#define debug_error(format, ...) fprintf(stderr, __COLOR_FORMAT(format, RED), __VA_ARGS__)
#elif DEBUG
#define debug_info(format, ...) fprintf(stdout, format, __VA_ARGS__)
#define debug_warning(format, ...) fprintf(stdout, format, __VA_ARGS__)
#define debug_error(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
#define debug_info(format, ...)
#define debug_warning(format, ...)
#define debug_error(format, ...)
#endif /* COLOR_DEBUG and DEBUG */

/****************************** DEBUG END *************************************/

/****************************** CONVENIENT MACRO ******************************/
#define _STR(x) #x
#define STR(x) _STR(x)

#endif /* __MARCO_HEAD_H__ */
