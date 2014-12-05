/* marco.h -- head file
 *
 * Written by Jianzhong Cui, 2014 (cjzswust@gmail.com)
 * 
 * Brief:
 *    This file is a set of stardand marco extanded in Gnu C 
 */

#ifndef __MARCO_HEAD_H__


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


#ifdef __GNUC__
/* caculate maximum and minimum of two parameter 
 * maxint(a, b)  return max value between a and b
 * minint(a, b)  return min value between a and b
 *
 * max(a, b)
 * min(a, b)
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
 * functions with __constructor or __destructor can be used as constructor or 
 * destructor of main function
 */
#define __constructor __attribute((constructor))
#define __destructor __attribute((destructor))

#endif

#endif
