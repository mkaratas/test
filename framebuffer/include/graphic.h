#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

struct pos_t {
	unsigned int x;
	unsigned int y;
};

void graphic_setcolor(unsigned int color);

void graphic_setpixel(struct pos_t pos);

void graphic_line(struct pos_t spos, struct pos_t epos, unsigned int linewidth);


#endif /*__GRAPHIC_H__*/
