#include <stdio.h>

void functionA(int a, char b)
{
	printf("in functionA, %p\n", __builtin_return_address(0));
}

void functionB(int c)
{
	functionA(3, 5);
}

int main(int argc, char **argv)
{
	functionB(5);

	return 0;
}
