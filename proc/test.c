#include <stdio.h>

int main(int argc, char **argv)
{
	register unsigned long esp asm("esp");
	
	printf("esp: %lx\n", esp);
	
	return 0;
}
