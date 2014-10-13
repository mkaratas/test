#include <stdio.h>
#include <string.h>
#include <provider.h>

provider_t *providers_head;

extern douban_provider_register(void);
extern provider_lapsule_register(void);
extern provider_mytest_register(void);

provider_t *get_provider_by_name(const char *name)
{
	if (!providers_head) {
		return NULL;
	}

	provider_t *p;
	for (p = providers_head; p; p = p->next) {
		if (strncmp(name, p->name, strlen(name)) == 0) {
			return p;
		}	
	}
	return NULL;
}

int provider_add(provider_t *pro)
{
	provider_t *p = providers_head;
	if (!pro) {
		printf("new provider is not available\n");
		return -1;
	}
	if (!p) {
		pro->next = NULL;
		providers_head = pro;
	} else {
		for (; p->next; p = p->next) 
			;
		pro->next = NULL;
		p->next = pro;
	}

	return 0;
}

void provider_onload(void)
{
	douban_provider_register();	
	provider_lapsule_register();
	provider_mytest_register();
}
