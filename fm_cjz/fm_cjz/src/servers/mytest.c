#include <stdio.h>
#include <provider.h>

extern provider_t *rprovider;

typedef struct mytest {
	provider_t pro;
	char *curl;
} mytest_t;

void mytest_login(provider_t *pro, const char *usr, const char *pwd)
{
	mytest_t *dou = (mytest_t*)pro;
	printf("mytest login\n");
}

void mytest_logout(provider_t *pro)
{
	printf("mytest logout\n");
}

channels_list_t *mytest_get_channel_list(provider_t *pro)
{
	printf("mytest get channel list\n");
}

mytest_t mytest_pro = {
	.pro = {
		.name = "mytest",
		.curl = "http://cjzswust.com.cn",
		.login = mytest_login,
		.logout = mytest_logout,
		.get_channel_list = mytest_get_channel_list,
	},
};

void provider_mytest_register(void)
{
	fm_provider_add((provider_t*)&mytest_pro);
}
