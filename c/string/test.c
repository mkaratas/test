#include <stdio.h>
#include <string.h>

typedef char *TAG;

#define END "\033[0m"

#define RED_BEGIN "\033[31m"
#define RED_END END

#define STR "cjz"

#define LOGE(fmt, ...) \
{printf("["RED_BEGIN"%s"RED_END"]: "RED_BEGIN fmt RED_END, "ERROR", ##__VA_ARGS__);}

int main(int argc, char **argv)
{
	char dest[6] = {0};
	dest[3] = 's';
	dest[4] = 'w';
	dest[5] = 'u';
	strncpy(dest, STR, sizeof(STR));
	
	TAG a = "ERROR";
	
	LOGE("%s\n", dest);
	LOGE("helo\n");
	
	return 0;
}
