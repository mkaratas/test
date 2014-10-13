#include <stdio.h>
#include <fbcon.h>
#include <graphic.h>

void ui_init(void)
{
	screen_init();
}

int main(int argc, char **argv)
{
	int i, j;
	ui_init();

	graphic_setcolor(0x00bb88aa);
	/*screen_setcolor(0x00ffff11);
	
	for (i = 0; i < 100; i++) {
		for (j = 0; j<100; j++) {
			set_pixel(i, j);
		}
	}
	*/
	struct pos_t start = {
		.x = 10,
		.y = 10,
	};
	struct pos_t end = {
		.x = 500,
		.y = 200,
	};
	//graphic_line(start, end, 100);
	
	//graphic_putc(end, 'A');
	struct pos_t str = {
		.x = 300,
		.y = 100,
	};
	graphic_puts(str, "cjzswust@gmail.com");
	
	return 0;
}
