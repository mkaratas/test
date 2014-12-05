#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define DEV_MEM "/dev/mem"

int main(int argc, char **argv)
{
	int fd;
	char *start_addr = 0;
	start_addr = getenv("elfcorehdr");
	if (!start_addr) {
		perror("getenv()");
	} else {
		printf("hdr: %s\n", start_addr);
	}

	fd = open(DEV_MEM, O_RDONLY)
	if (fd < 0) {
		perror("open");
	}

	volatile 

	close(fd);

	return 0;
}
