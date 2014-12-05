/* marco.h -- head file
 *
 * Written by Jianzhong Cui, 2014 (cjzswust@gmail.com)
 * 
 * Brief:
 *    This file is a set of stardand marco extanded in Gnu C 
 */

#ifndef __MARCO_HEAD_H__

#ifdef __GNUC__

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


#endif

#endif
