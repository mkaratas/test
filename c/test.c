#include <stdio.h>

char *getstr(void)
{
	char *aa = "cjzswust";
	return aa;
}

int main(int argc, char **argv)
{
	char *p;
	p = getstr();	
	printf("%s\n", p);
	free(p);


	return 0;
}
