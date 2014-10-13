#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b = 0;

	if ( (a = b) ) {
		printf("true\n");
	} else {
		printf("false\n");
	}
	return 0;
}
