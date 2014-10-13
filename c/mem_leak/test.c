#include <stdio.h>
#include <stdlib.h>
#include <error.h>

void getmem(char *p)
{
	p = (char *)malloc(100);
	if (!p) {
		perror("malloc()");
	}
}

int main(int argc, char **argv)
{
	char *ptr;
	getmem(ptr);

	return 0;
}
