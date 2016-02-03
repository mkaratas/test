#include <stdio.h>
#include <sys/utsname.h>

int main(int argc, char** argv)
{
	int major, minor;
	struct utsname uts;

	if ( uname(&uts) != -1 ) {

		printf("sysname = %s, release = %s\n", uts.sysname, uts.release);
	}

	return 0;
}
