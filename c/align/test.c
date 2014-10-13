#include <stdio.h>

#pragma pack(1) 

struct test {
	char a;
	int b;
	short c;
};

int main()
{
	printf("sizeof test = %lu\n", sizeof(struct test));
	return 0;
}
