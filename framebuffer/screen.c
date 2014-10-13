#include <stdio.h>
#include <stdlib.h>
#include <fbcon.h>
#include <string.h>
#include <errno.h>

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

int screen_init(void)
{
	fbcon = fb_init();
	if (!fbcon) {
		printf("fb_init() error\n");
		return -ENODEV;
	}
	return 0;
}

int screen_close(void)
{
	if (!fbcon) {
		return -ENODEV;
	}
	return fb_close(fbcon);
}

void screen_setcolor(unsigned int argb)
{
	switch (fbcon->rgb_format) {
		case FRAMEBUFFER_FORMAT_RGB555:
		{
			unsigned char r = (argb & 0x00ff0000) >> 16;
			unsigned char g = (argb & 0x0000ff00) >> 8;
			unsigned char b = (argb & 0x000000ff);

			color16 = MOD_555_RGB16BIT(r, g, b);
			color = &color16;
			break;
		}
		case FRAMEBUFFER_FORMAT_RGB565:
		{
			unsigned char r = (argb & 0x00ff0000) >> 16;
			unsigned char g = (argb & 0x0000ff00) >> 8;
			unsigned char b = (argb & 0x000000ff);

			color16 = MOD_565_RGB16BIT(r, g, b);
			color = &color16;
			break;
		}
		case FRAMEBUFFER_FORMAT_RGB888:
		{
			color32 = argb & 0x00ffffff;
			color = &color32;
			break;
		}
		case FRAMEBUFFER_FORMAT_ARGB:
		{
			color32 = argb;
			color = &color32;
			break;
		}
		default:
			printf("RGB FORMAT (%d) IS NOT SUPPORT\n", fbcon->rgb_format);
			break;
	}
	
}

void set_pixel(unsigned int x, unsigned int y)
{
	if (x >= fbcon->fb_width || y >= fbcon->fb_height) {
		printf("x = %d y = %d\n", x, y);
		return;
	}
	memcpy(fbcon->fb_base + (x + y*fbcon->fb_width)*fbcon->bytes_per_pixel, 
		(void*)&color16, fbcon->bytes_per_pixel);
}

void screen_set_pixels(unsigned int x, unsigned int y, unsigned int xlength)
{

}

int main(int argc, char **argv)
{
	int i, j;
	screen_init();
	screen_setcolor(0x00888888);
	for (i = 0; i < 100; i++) {
		for (j = 0; j<100; j++) {
			set_pixel(i, j);
		}
	}
	
	return 0;
}
