#include <stdio.h>
#include <provider.h>

int main(int argc, char **argv)
{
	provider_t *pro;
	provider_onload();
	
	pro = get_provider_by_name("mytest");
	//pro = get_provider_by_name("douban");
	if (!pro) {
		printf("no available provider\n");
	} else {
		pro->login(pro, "cjzswust@gmail.com", "cui5023091");
		pro->logout(pro);
	}

	return 0;
}
