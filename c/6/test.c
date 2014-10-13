#include <stdio.h>

#define RATE "?type=r&sid="
#define RATE_SONG(url, R) url##R
#define STR(s) #s

int main(int argc, char **argv)
{
	char *buf = "cjz";
	printf("%s", STR(RATE_SONG(buf, RATE)));
	return 0;
}
