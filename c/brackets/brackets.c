#include <stdio.h>

int main(int argc, char **argv)
{
	int b = 0;
	
	//b+=b=((b=(2, 3), b+2), 15+b);
	b = ((b=(2,3), b+2), 15+b);
	printf("b= %d\n", b);
	
	return 0;
}
