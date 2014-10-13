#include <stdio.h>
#include <stdlib.h>

int callback(char a, int b)
{
	return a+b;
}

int main(int argc, char **argv)
{
	int i;
	i = callback(10, 99);

	return 0;
}
