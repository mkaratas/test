#include <stdio.h>

#define __PAST(a, b) a##b

int main(int argc, char **argv)
{
	printf("%s\n", __PAST("cjz", "swust"));
	return 0;
}
