/**
 * Author: Jianzhong Cui
 * 
 * Copyright: Can not be used in commercial product
 */

#ifndef __SERVICE_PROVIDER_H__
#define __SERVICE_PROVIDER_H__

#include <proxy.h>
#include <json-c/json.h>

typedef struct __server server;
typedef struct __service_provider service_provider;

typedef struct __song_entry {
	char *name;
	char *artist;
	char *album;
	char *picture;
	char *url;
	int id;
	int like; 
	struct __song_entry *next;
} song_entry;

typedef struct __channel_entry {
	int id;
	char *name;
	struct __channel_entry *next;
} channel_entry;

typedef void (*fptr_login)(server *sver, const proxy *pxy, const char *usr, const char *pwd);
typedef void (*fptr_logout)(server *sver);
typedef song_entry *(*fptr_play)(server *sver);
typedef song_entry *(*fptr_next)(server *sver, const proxy *pxy);
typedef void *(*fptr_pause)(server *sver);
typedef void (*fptr_stop)(server *sver);
typedef int  (*fptr_save_login_info)(server *sver, const char *infostr);
typedef char *(*fptr_get_login_info)(server *sver);
typedef void (*fptr_set_channel)(server *sver, const proxy *pxy, const int channel_id);

typedef struct __server {
	char *name;
	fptr_login      login;
	fptr_logout     logout;
	fptr_play		play;
	fptr_next		next_song;
	fptr_pause		pause;
	fptr_stop		stop;
	fptr_save_login_info save_login_info;
	fptr_get_login_info get_login_info;
	fptr_set_channel set_channel;
	struct __server *next_sver;
} server;

typedef void (*fptr_servers_load)(service_provider *sp);
typedef int (*fptr_add_server)(service_provider *sp, server *sver);
typedef server *(*fptr_get_server_by_name)(service_provider *sp, const char *name);
typedef server *(*fptr_get_current_server)(service_provider *sp);

typedef struct __service_provider {
	proxy           *pxy;
	server          *cur_server;
	server          *servers_head;
	int 			server_count;
	fptr_servers_load            servers_load;
	fptr_add_server              add_servers;
	fptr_get_server_by_name      get_server_by_name;
	fptr_get_current_server      get_current_server;
} service_provider;

service_provider *new_service_provider(fptr_servers_load);
void delete_service_provider(service_provider *sp);

#endif /*__SERVICE_PROVIDER_H__*/
