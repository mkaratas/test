#include <stdio.h>
#include <unistd.h>

void usage()
{


}

int main(int argc, char *argv[])
{
	int opt;
	while((opt = getopt(argc, argv, "d:h")) != -1) {
		switch (opt) {
			case 'd':
				printf("directory is: %s\n", optarg);
				break;
			case 'h':
				break;
			default:
				usage();
				break;
		}
	}

	return 0;
}

