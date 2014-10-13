#include <stdio.h>

typedef unsigned char DES_cblock[8];

unsigned char *unbase64(char *input, int length, int *outLen)
{

	return input;
}

int main(int argc, char **argv)
{
	DES_cblock key;	
	char keycode[8] = "cjzswust";
	key = unbase64(&keycode, sizeof(keycode), 8);

	
	return 0;
}
