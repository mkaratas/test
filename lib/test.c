#include <stdio.h>
#include <marco.h>


void __constructor main_init(void)
{
	printf("constructor\n");
}

int main(int argc, char **argv)
{
/*
	int ret = 0;
	ret = min(10, 20);
	printf("===============================================\n");
	printf("Author: Fred Cui\n\
			\rDate: %s\n\
			\rTIME: %s\n", COMPILE_DATE, COMPILE_TIME);
	printf("===============================================\n");
	printf("ret = %d %s %s\n", ret, __DATE__, __TIME__);
	
*/
//	PRINT_BANNER;
	printf(BANNER(test));

	debug_error("cjz debug %s\n", "hehe");

	return 0;
}
