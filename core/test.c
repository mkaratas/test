#include <stdio.h>

int funA()
{
	int *p;
	*p = 20;
}

int funB()
{
	funA();
}

int main(int argc, char argv)
{
	funB();

	return 0;
}
