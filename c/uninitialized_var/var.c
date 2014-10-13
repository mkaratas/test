#include <stdio.h>

#define uninitialized_var(x) x = x

int main(int argc, char **argv)
{
	int uninitialized_var(a);

	printf("%d\n", a);
	return 0;
}

