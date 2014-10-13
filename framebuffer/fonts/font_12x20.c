/*
 * Copyright (C) 2012 Sony Mobile Communications AB.
 * All rights, including trade secret rights, reserved.
 */

#include <fonts/font.h>

static unsigned char data_12x20[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0x30, 0x33, 0x03, 0x30, 0x33, 0x03, 0x30, 0x33,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x30, 0x33,
	0x0f, 0xfc, 0xff, 0xc3, 0x30, 0x33, 0x03, 0x30, 0x33, 0x0f,
	0xfc, 0xff, 0xc3, 0x30, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0c, 0x03, 0xfc, 0x3f,
	0xcc, 0xc0, 0xcc, 0x03, 0xf0, 0x3f, 0x00, 0xcc, 0x0c, 0xcf,
	0xf0, 0xff, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x30,
	0x3c, 0xcc, 0xcc, 0xc3, 0x30, 0x33, 0x00, 0xcc, 0x0c, 0xc3,
	0x33, 0x33, 0x3c, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x3c, 0x0c, 0x30, 0xc3,
	0x0c, 0x30, 0xc3, 0x03, 0xc0, 0x3c, 0x0c, 0x33, 0xc3, 0x3c,
	0x0c, 0xc0, 0xc3, 0xf3, 0x3f, 0x30, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x30, 0x03, 0x00, 0xc0, 0x0c, 0x03, 0x00, 0x30,
	0x03, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03,
	0x00, 0x30, 0x00, 0xc0, 0x0c, 0x00, 0x30, 0x03, 0x00, 0x00,
	0x00, 0x03, 0x00, 0x30, 0x00, 0xc0, 0x0c, 0x00, 0x30, 0x03,
	0x00, 0x30, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03, 0x00,
	0x30, 0x03, 0x00, 0xc0, 0x0c, 0x03, 0x00, 0x30, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0c,
	0x0c, 0xcc, 0xcc, 0xc3, 0xf0, 0x3f, 0x0c, 0xcc, 0xcc, 0xc0,
	0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x0f, 0xfc, 0xff, 0xc0, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0x0c, 0x03, 0x00, 0x30, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0f, 0xfc, 0xff, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x30, 0x03,
	0x00, 0x30, 0x03, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x03,
	0x00, 0x30, 0x03, 0x00, 0x30, 0x0c, 0x00, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xcc, 0xcc, 0xcc, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0c, 0x03, 0xc0, 0x3c,
	0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x03, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xc0, 0x0c, 0x00, 0xc0, 0xf0, 0x0f, 0x03, 0x00, 0x30, 0x0c,
	0x00, 0xc0, 0x0f, 0xfc, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xc0, 0x0c, 0x00, 0xc0, 0xf0, 0x0f, 0x00, 0x0c, 0x00, 0xcc,
	0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x03, 0x00, 0xf0, 0x0f,
	0x03, 0x30, 0x33, 0x0c, 0x30, 0xc3, 0x0f, 0xfc, 0xff, 0xc0,
	0x30, 0x03, 0x00, 0x30, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0xff, 0xcc, 0x00, 0xc0,
	0x0c, 0x00, 0xc0, 0x0f, 0xf0, 0xff, 0x00, 0x0c, 0x00, 0xcc,
	0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x03, 0x00, 0x30,
	0x0c, 0x00, 0xc0, 0x0f, 0xf0, 0xff, 0x0c, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0xff, 0xc0, 0x0c, 0x00,
	0xc0, 0x30, 0x03, 0x00, 0x30, 0x03, 0x00, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x03, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xc3, 0xfc, 0x3f, 0xc0, 0x0c, 0x00, 0xc0,
	0x30, 0x03, 0x03, 0xc0, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xc0, 0x0c, 0x03, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00,
	0xc0, 0xf0, 0x0f, 0x0f, 0x00, 0xf0, 0x00, 0xf0, 0x0f, 0x00,
	0x0c, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0f, 0xfc, 0xff, 0xc0, 0x00, 0x00, 0x0f, 0xfc, 0xff, 0xc0,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0xc0,
	0x03, 0xc0, 0x3c, 0x00, 0x3c, 0x03, 0xc3, 0xc0, 0x3c, 0x0c,
	0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xc0, 0x0c, 0x00, 0xc0, 0x30, 0x03, 0x00, 0xc0, 0x0c, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x3f, 0xcc, 0x03, 0xc0,
	0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xff, 0xcf, 0xfc,
	0x00, 0xc0, 0x03, 0xff, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x03, 0x30, 0x33, 0x03, 0x30, 0x33, 0x03, 0xf0, 0x3f, 0x0c,
	0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0xff, 0x0c, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xcf, 0xf0, 0xff, 0x0c, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xcf, 0xf0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xcc, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0xfc, 0x0c, 0x30, 0xc3,
	0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x30, 0xc3, 0x0f, 0xc0, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0xff, 0xcc, 0x00, 0xc0,
	0x0c, 0x00, 0xc0, 0x0f, 0xf0, 0xff, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0f, 0xfc, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0xff, 0xcc, 0x00, 0xc0,
	0x0c, 0x00, 0xc0, 0x0f, 0xf0, 0xff, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xcc, 0x00, 0xc0, 0x0c, 0x3c, 0xc3, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xfc, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xcf, 0xfc, 0xff, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x03, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x0f, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0,
	0x0c, 0x00, 0xcf, 0xf0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0xc0, 0xcc, 0x30, 0xc3,
	0x0c, 0xc0, 0xcc, 0x0f, 0x00, 0xf0, 0x0c, 0xc0, 0xcc, 0x0c,
	0x30, 0xc3, 0x0c, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0,
	0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0f, 0xfc, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0,
	0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0x0c, 0xf0, 0xcf, 0x0c, 0xf0,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0x3c, 0xc3, 0xcc, 0x3c, 0xc3, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0xff, 0x0c, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xcf, 0xf0, 0xff, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x3c, 0xc3, 0xc3, 0xfc, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0xff, 0x0c, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xcf, 0xf0, 0xff, 0x0c, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0,
	0xcc, 0x00, 0xc0, 0x03, 0xf0, 0x3f, 0x00, 0x0c, 0x00, 0xcc,
	0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0xff, 0xc0, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xc3, 0x30, 0x33, 0x03, 0x30, 0x33, 0x00,
	0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0xc0, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xc3, 0x30, 0x33, 0x03,
	0x30, 0x33, 0x03, 0x30, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0,
	0xc3, 0x30, 0x33, 0x00, 0xc0, 0x0c, 0x03, 0x30, 0x33, 0x0c,
	0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0,
	0xcc, 0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0xff, 0xc0, 0x0c, 0x00,
	0xc0, 0x30, 0x03, 0x00, 0xc0, 0x0c, 0x03, 0x00, 0x30, 0x0c,
	0x00, 0xc0, 0x0f, 0xfc, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0xf0, 0x3f, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30,
	0x03, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03,
	0x00, 0x30, 0x03, 0x00, 0x30, 0x03, 0xf0, 0x3f, 0x00, 0x00,
	0x00, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x03, 0x00, 0x30,
	0x03, 0x00, 0x30, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00,
	0x30, 0x03, 0x00, 0x30, 0x03, 0x00, 0x0c, 0x00, 0xc0, 0x00,
	0x00, 0x03, 0xf0, 0x3f, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03,
	0x00, 0x30, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03, 0x00,
	0x30, 0x03, 0x00, 0x30, 0x03, 0x03, 0xf0, 0x3f, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0c, 0x03, 0x30, 0x33,
	0x0c, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0c, 0x00, 0x30, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0xf0, 0x3f, 0x00, 0x0c, 0x00, 0xc3, 0xfc, 0x3f, 0xcc,
	0x0c, 0xc0, 0xc3, 0xfc, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0,
	0x0f, 0xf0, 0xff, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xcf, 0xf0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0xfc, 0x3f, 0xcc, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x03, 0xfc, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00,
	0xc3, 0xfc, 0x3f, 0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xfc, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0, 0xcf, 0xfc, 0xff, 0xcc,
	0x00, 0xc0, 0x03, 0xfc, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xfc, 0x0f, 0xc3, 0x00, 0x30, 0x03, 0x00, 0x30,
	0x0f, 0xf0, 0xff, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03,
	0x00, 0x30, 0x03, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xfc, 0x3f, 0xc0, 0x0c, 0x00, 0xc3, 0xf0,
	0x00, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0,
	0x0f, 0xf0, 0xff, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00,
	0x03, 0xc0, 0x3c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x03, 0x00, 0x00, 0x00,
	0x00, 0xf0, 0x0f, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03, 0x00,
	0x30, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03, 0x0f, 0xc0,
	0x00, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30,
	0x03, 0x0c, 0x30, 0xc3, 0x30, 0x33, 0x03, 0xc0, 0x3c, 0x03,
	0x30, 0x33, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0xc0, 0x3c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0f, 0x30, 0xf3, 0x0c, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0f, 0xf0, 0xff, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0xf0, 0x3f, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0f, 0xf0, 0xff, 0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xcf, 0xf0, 0xff, 0x0c, 0x00, 0xc0, 0x0c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0xfc, 0x3f, 0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xfc, 0x3f, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0xf0, 0xcf, 0x0f, 0x0c, 0xf0, 0xcc, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0xfc, 0x3f, 0xcc, 0x00, 0xc0, 0x03, 0xf0, 0x3f, 0x00,
	0x0c, 0x00, 0xcf, 0xf0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30,
	0x03, 0xf0, 0x3f, 0x03, 0x00, 0x30, 0x03, 0x00, 0x30, 0x03,
	0x00, 0x30, 0x00, 0xfc, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xfc, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xc3, 0x30, 0x33, 0x03,
	0x30, 0x33, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0x0c, 0xc0, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xc3,
	0x30, 0x33, 0x03, 0x30, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0x0c, 0xc0, 0xc3, 0x30, 0x33, 0x00, 0xc0, 0x0c, 0x03,
	0x30, 0x33, 0x0c, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc, 0x0c, 0xc0, 0xcc,
	0x0c, 0xc0, 0xc3, 0xfc, 0x3f, 0xc0, 0x0c, 0x00, 0xc3, 0xf0,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0f, 0xfc, 0xff, 0xc0, 0x30, 0x03, 0x00, 0xc0, 0x0c, 0x03,
	0x00, 0x30, 0x0f, 0xfc, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x30, 0x03, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x03, 0x00, 0x30, 0x00, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0x30, 0x03, 0x00, 0x00,
	0x00, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x00, 0x00,
	0x00, 0x03, 0x00, 0x30, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x0c,
	0x00, 0xc0, 0x0c, 0x00, 0x30, 0x03, 0x00, 0xc0, 0x0c, 0x00,
	0xc0, 0x0c, 0x00, 0xc0, 0x0c, 0x03, 0x00, 0x30, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x03, 0xc3, 0x3c, 0x3c, 0x3c, 0xc3, 0xc0,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
};

struct fontinfo font_12x20 = {
	.name = "12x20",
	.width = 12,
	.width_spacing = 0,
	.height = 20,
	.height_spacing = 0,
	.size_per_char = 30,
	.data = data_12x20,
};
