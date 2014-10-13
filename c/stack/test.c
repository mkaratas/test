#include <stdio.h>

struct test {
	int a1[4096];
	int a2[4096];
	int a3[4096];
	int a4[4096];
};

int main(int argc, char **argv)
{
	struct test b[1500];

	return 0;
}
