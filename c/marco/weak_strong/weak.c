#include <stdio.h>

#define __weak __attribute((weak))


void __weak hello()
{
	printf("weak hello\n");
}

int main(int argc, char **argv)
{
	hello();
	return 0;
}
