#ifndef __FBCON_H__
#define __FBCON_H__

#define FRAMEBUFFER_FORMAT_RGB555 0    
#define FRAMEBUFFER_FORMAT_RGB565 1
#define FRAMEBUFFER_FORMAT_RGB888 2               
#define FRAMEBUFFER_FORMAT_ARGB 3

struct fb_control {
	void *fb_base;
	unsigned int screen_width;
	unsigned int screen_height;
	unsigned int fb_width;
	unsigned int fb_height;
	unsigned int line_length;
	unsigned int bytes_per_pixel;
	unsigned int rgb_format;
	unsigned int fb_size;
	void (*flush)(void);
};

struct fb_control *fb_init();
int fb_close(struct fb_control *fbcon);

#endif /* __FBCON_H__ */
