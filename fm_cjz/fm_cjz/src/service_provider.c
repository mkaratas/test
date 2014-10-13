/**
 * Author: Jianzhong Cui
 * 
 * Copyright: Can not be used in commercial product
 */

#include <stdio.h>
#include <string.h>
#include <debug.h>
#include <service_provider.h>

server *service_provider_get_current_server(service_provider *sp)
{
	return sp->cur_server;
}

server *service_provider_get_server_by_name(service_provider *sp, const char *name)
{
	server *psver = sp->servers_head;
	for (; psver; psver = psver->next_sver) {
		if ( (strlen(name) == strlen(psver->name)) &&
				!strncmp(name, psver->name, strlen(name)) ) {
			return psver;
		}
	}
	return NULL;
}

int service_provider_add_server(service_provider *sp, server *sver)
{
	if (!sver) {
		LOGE("Invalid server\n");
		return -1;
	}
	LOGI("provider add server: %s\n", sver->name);
	sver->next_sver = NULL;
	server *psver = sp->servers_head;

	if (!psver) {
		LOGD("first server is added\n");
		sp->servers_head = sver;
	} else { 
		LOGD("more server is added\n");
		for (; psver->next_sver; psver = psver->next_sver) 
			;
		psver->next_sver = sver;
	}
	sp->cur_server = sver;
	
	return 0;
}

service_provider *new_service_provider(fptr_servers_load load_cb)
{
	service_provider *sp = (service_provider*)malloc(sizeof(service_provider));
	if (!sp) {
		LOGE("malloc(): %s\n", strerror(errno));
		return NULL;
	}
	
	sp->pxy = new_proxy();
	if (!sp->pxy) {
		LOGE("malloc(): %s\n", strerror(errno));
		free(sp);
		sp = NULL;
		return NULL;
	}
	sp->cur_server = NULL;
	sp->servers_head = NULL;
	sp->servers_load = load_cb;
	sp->server_count = 0;
	sp->add_servers = service_provider_add_server;
	sp->get_server_by_name = service_provider_get_server_by_name;
	sp->get_current_server = service_provider_get_current_server;
}

void delete_service_provider(service_provider *sp)
{
	delete_proxy(sp->pxy);
	free(sp);
	sp = NULL;
}
