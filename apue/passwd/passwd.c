#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>


int main(int argc, char **argv)
{
	struct passwd *pwd;
	pwd = getpwuid(getuid());
	printf("pwd name: %s\n", pwd->pw_name);
	printf("pwd : %s\n", pwd->pw_passwd);
	printf("pwd uid: %u\n", pwd->pw_uid);

	return 0;
}
