/*
* fm_rcs.h : FM Remote Control Server
* Author   : Fred Cui
* Date     : May 23th, 2014
*/

#ifndef __FM_RCS_H__
#define __FM_RCS_H__

typedef int (*fm_rcs_setup)();
typedef int (*fm_rcs_start)();
typedef int (*fm_rcs_stop)();

typedef struct __fm_rcs_ops {
	fm_rcs_setup	setup;
	fm_rcs_start	start;
	fm_rcs_stop		stop;
} fm_rcs_ops;

typedef struct __fm_rcs {
	fm_rcs_ops ops;
} fm_rcs;

fm_rcs *get_rcs_instance(void);

#endif /*__FM_RCS_H__*/
