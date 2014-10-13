#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <linux/kd.h>
#include <sys/mman.h>
#include <fbcon.h>

#define FB_DEV "/dev/fb0"

static int fb_fd;
static struct fb_var_screeninfo var_screeninfo;
static struct fb_fix_screeninfo fix_screeninfo;

static void print_screeninfo(void)
{
	printf("var screeninfo: \n"
			"\txres: %d\n"
			"\tyres: %d\n"
			"\txres_v: %d\n"
			"\tyres_v: %d\n"
			"\txoffs: %d\n"
			"\tyoffs: %d\n"
			"\tscrn_h: %d\n"
			"\tscrn_w: %d\n"
			"\tbit_per_pix: %d\n"
			"\tbitfields:\n"
			"\t\tred   : (of: %2u, len: %2u, msb_right: %u)\n" 
			"\t\tgreen : (of: %2u, len: %2u, msb_right: %u)\n" 
			"\t\tblue  : (of: %2u, len: %2u, msb_right: %u)\n" 
			"\t\ttransp: (of: %2u, len: %2u, msb_right: %u)\n" 
			"\t\tleft_margin %d right_margin: %d upper_margin: %d\n"
			"\t\tlower_margin: %d hsync_len: %d vsync_len: %d\n"
			"\t\tpixclock %d\n",
			var_screeninfo.xres,
			var_screeninfo.yres,
			var_screeninfo.xres_virtual,
			var_screeninfo.yres_virtual,
			var_screeninfo.xoffset,
			var_screeninfo.yoffset,
			var_screeninfo.height,
			var_screeninfo.width,
			var_screeninfo.bits_per_pixel,
			var_screeninfo.red.offset,
			var_screeninfo.red.length,
			var_screeninfo.red.msb_right,
			var_screeninfo.green.offset,
			var_screeninfo.green.length,
			var_screeninfo.green.msb_right,
			var_screeninfo.blue.offset,
			var_screeninfo.blue.length,
			var_screeninfo.blue.msb_right,
			var_screeninfo.transp.offset,
			var_screeninfo.transp.length,
			var_screeninfo.transp.msb_right, var_screeninfo.left_margin,
			var_screeninfo.right_margin, var_screeninfo.upper_margin,
			var_screeninfo.lower_margin, var_screeninfo.hsync_len,
			var_screeninfo.vsync_len, var_screeninfo.pixclock);

    printf("fix screenInfo:\n"
        "\tline_length: %d\n",
        fix_screeninfo.line_length);
}

struct fb_control *fb_init()
{
	printf("Initializing FB\n");
	
	fb_fd = open(FB_DEV, O_RDWR);
	if (-1 == fb_fd) {
		perror("open()");	
		return NULL;
	}

	if (ioctl(fb_fd, FBIOGET_VSCREENINFO, &var_screeninfo) < 0) {
		perror("ioctl()");
		goto ERROR;
	}
	if (ioctl(fb_fd, FBIOGET_FSCREENINFO, &fix_screeninfo) < 0) {
		perror("ioctl()");
		goto ERROR;
	}
	
	//print_screeninfo();

	struct fb_control *fbcon;
	fbcon = (struct fb_control *)malloc(sizeof(struct fb_control));
	if (!fbcon) {
		perror("malloc()");
		goto ERROR;
	}
	fbcon->line_length = fix_screeninfo.line_length;
	fbcon->rgb_format = FRAMEBUFFER_FORMAT_RGB565;
	fbcon->bytes_per_pixel = (unsigned int)var_screeninfo.bits_per_pixel/8;
	fbcon->screen_width = var_screeninfo.xres;
	fbcon->screen_height = var_screeninfo.yres;
	fbcon->fb_width = fbcon->line_length/fbcon->bytes_per_pixel;
	fbcon->fb_height = var_screeninfo.yres;
	fbcon->fb_size = fbcon->fb_width * fbcon->fb_height * fbcon->bytes_per_pixel;
	fbcon->fb_base = mmap(0, fbcon->fb_size, PROT_READ | PROT_WRITE, MAP_SHARED, fb_fd, 0);

	if (fbcon->fb_base == MAP_FAILED) {
		perror("map()");
		free(fbcon);
		goto ERROR;
	}

	return fbcon;
ERROR:
	close(fb_fd);
	return NULL;
}

int fb_close(struct fb_control *fbcon)
{
	if (fbcon) {
		if (munmap(fbcon->fb_base, fbcon->fb_size) < 0) {
			perror("munmap()");
			
		}
		close(fb_fd);
		free(fbcon);
		return 0;
	}

	return -1;
}
