#include <stdio.h>
#include <string.h>

static inline const char *basename(const char *path)
{
	const char *tail = strrchr(path, '/');
	return tail ? tail+1 : path;
}

int main(int argc, char **argv)
{
	char *str = "/home/cjz/test.c";
	printf("%s\n", basename(str));

	return 0;
}
