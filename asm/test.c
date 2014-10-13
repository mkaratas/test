#include <stdio.h>

int B(int a, int b)
{
	int c;
	
	return c;
}

int A(char a, char b)
{
	B(3, 5);
}

int main()
{
	int a;
	a = A('c', 'j');
	printf("a = %d\n", a);

	return 0;
}
