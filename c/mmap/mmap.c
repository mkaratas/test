#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>

#define TEMP_FILE "./tmp.txt"

int main(int argc, char **argv)
{
	if (open(TEMP_FILE, O_RDWR|O_CREAT)<0) {
		perror("open()");
		exit(-1);
	}
	//mmap(0, );
	return 0;
}
