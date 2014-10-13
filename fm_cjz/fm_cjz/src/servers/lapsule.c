#include <stdio.h>
#include <debug.h>
#include <service_provider.h>

#define LAPSULE_SONG_API "http://api.lapsule.com/service/"

typedef struct login_info {
    const char *user_id;
    const char *err;
    const char *token;
    const char *expire;
    const char *result;
    const char *user_name;
    const char *email;
} login_info_t;

typedef struct lapsule {
	server sver;
	login_info_t info;
	
	char *song_api;
	channel_entry cur_channel;
	channel_entry *channels_list;
	song_entry *song_list;
} lapsule_t;

void lapsule_login(server *sver, const proxy *pxy, const char *usr, const char *pwd)
{
	lapsule_t *ls = (lapsule_t*)sver;
	printf("lapsule login\n");
}

void lapsule_logout(server *sver)
{
	printf("lapsule logout\n");
}

song_entry *lapsule_next_song(server *sver, const proxy *pxy)
{
	printf("lapsule next song\n");
	return NULL;
}

void lapsule_set_channel(server *sver, const proxy *pxy, const int channel_id)
{
	printf("lapsule set channel %d\n", channel_id);
}

lapsule_t lapsule_sver = {
	.sver = {
		.name = "lapsule",
		.login = lapsule_login,
		.logout = lapsule_logout,
		.next_song = lapsule_next_song,
		.set_channel = lapsule_set_channel,
	},
	.song_api = LAPSULE_SONG_API,
	.cur_channel = {
		.id = 0,
	},
	.song_list = NULL,
	.channels_list = NULL,
};

server *lapsule_server_register(void)
{
	LOGI("lapsule server register\n");
	return (server*)&lapsule_sver;
}
