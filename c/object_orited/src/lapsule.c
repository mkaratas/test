#include <stdio.h>
#include <provider.h>

extern provider_t *rprovider;

typedef struct lapsule {
	provider_t pro;
	char *curl;
} lapsule_t;

void lapsule_login(provider_t *pro, const char *usr, const char *pwd)
{
	lapsule_t *dou = (lapsule_t*)pro;
	printf("lapsule login\n");
}

void lapsule_logout(provider_t *pro)
{
	printf("lapsule logout\n");
}

channels_list_t *lapsule_get_channel_list(provider_t *pro)
{
	printf("lapsule get channel list\n");
}

lapsule_t lapsule_pro = {
	.pro = {
		.name = "lapsule",
		.login = lapsule_login,
		.logout = lapsule_logout,
		.get_channel_list = lapsule_get_channel_list,
	},
	.curl = "http://cjzswust.com.cn",
};

void provider_lapsule_register(void)
{
	provider_add((provider_t*)&lapsule_pro);
}
