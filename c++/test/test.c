#include <stdio.h>

struct test {
	int a;
	char b;
};

int main(int argc, char **argv)
{
	struct test a = {
		.a = 10,
		.b = 'a',
	};

	return 0;
}
