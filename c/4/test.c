#include <stdio.h>

struct str {
	int len;
	char s[0];
};

struct foo {
	struct str *a;
	char *p;
	int *ip;
};

int main(int argc, char **argv)
{
	struct foo f = {0};
	struct foo *fp = NULL;
	if (f.a->s) {
		printf("%x\n", f.a->s);
	}
	
	return 0;
}
