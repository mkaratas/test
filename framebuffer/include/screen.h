#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include <fbcon.h>

unsigned short color16;
unsigned int color32;
static struct fb_control *fbcon;
void *color;

/*convert 24->16bits RGB565*/
#define MOD_565_RGB16BIT(r, g, b) \
	(((int)(b/8)) + (((int)(g/4)) << 5) + (((int)(r/8))<<11))

/* convert 24->16bits RGB555 */
#define MOD_555_RGB16BIT(r, g, b) \
	(((int)(b/8)) + (((int)(g/8))<<5) + (((int)(r/8))<<10))

int screen_init(void);
int screen_close(void);
unsigned int screen_width(void);
unsigned int scree_height(void);
void screen_setcolor(unsigned int argb);
void screen_setpixel(unsigned int x, unsigned int y);

#endif /*__GRAPHIC_H__*/
