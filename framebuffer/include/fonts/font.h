#ifndef __FONTS_H__
#define __FONTS_H__

struct fontinfo {
	const char name[32];
	unsigned int width;
	unsigned int width_spacing;
	unsigned int height;
	unsigned int height_spacing;
	unsigned int size_per_char;
	const unsigned char *data;
};

extern struct fontinfo font_8x12;
extern struct fontinfo font_12x20;
extern struct fontinfo font_24x38;

#endif /*__FONTS_H__*/
