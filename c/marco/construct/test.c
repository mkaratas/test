#include <stdio.h>

#define __constructor __attribute((constructor))
#define __destructor __attribute((destructor))

void __constructor hello_constructor(void)
{
	printf("constructor\n");
}

void __destructor hello_destructor(void)
{
	printf("destructor\n");
}

int main(int argc, char **argv)
{
	printf("in main\n");
	return 0;
}
