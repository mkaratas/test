#include <stdio.h>
#include <graphic.h>
#include <screen.h>
#include <fonts/font.h>

struct fontinfo *cur_font = &font_8x12;
//struct fontinfo *cur_font = &font_24x38;

void graphic_setcolor(unsigned int color)
{
	screen_setcolor(color);
}

void graphic_setpixel(struct pos_t pos)
{
	screen_setpixel(pos.x, pos.y);
}

void graphic_line(struct pos_t spos, struct pos_t epos, unsigned int linewidth)
{
	unsigned i;

	struct pos_t d;
	d.x = (epos.x > spos.x) ? epos.x - spos.x : spos.x - epos.x;
	d.y = (epos.y > spos.y) ? epos.y - spos.y : spos.y - epos.y;
	
	struct pos_t s;
	s.x = (epos.x > spos.x) ? 1 : -1;
	s.y = (epos.y > spos.y) ? 1 : -1;
	
	if (d.x > d.y) {
		for (i = 0; i < d.x; i++) {
			screen_setpixel(spos.x, spos.y);
			spos.x += s.x;
			spos.y += s.y;
		}
	} else {

	}
}

void graphic_putc(struct pos_t pos, const char c)
{
	unsigned int x = 0, y = 0;
	if ((unsigned char)c < 32 || (unsigned char)c > 127) {
		return;
	}
	const unsigned char *charpos = 
		cur_font->data + cur_font->size_per_char * (c-32);
	//printf("putc charpos = %p\n", charpos);
	int i, j;
	for (i = 0; i < (int)cur_font->size_per_char; i++) {
		for (j = 7; j>=0; j--) {
			if ((charpos[i]>>j) & 0x01) {
				screen_setpixel(pos.x+x, pos.y+y);
			}
			x++;
			if (x == cur_font->width) {
				x = 0;
				y++;
			}
		}
	}
}

void graphic_puts(struct pos_t pos, const char *s)
{
	int i = 0;
	while(s[i] != '\0') {
		graphic_putc(pos, s[i]);
		pos.x += cur_font->width + cur_font->width_spacing;
		i++;
	}
}
