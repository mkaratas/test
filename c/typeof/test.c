#include <stdio.h>

#define typecheck(x,y) {typeof(x) __dummy1;typeof(y) __dummy2; (void)(&__dummy1 == &__dummy2);}

int main(int argc, char **argv)
{
	int a;
	int b; 
	void c = typecheck(a, b);

	printf("%x\n", c);
	//typecheck(a, b);

	return 0;
}
