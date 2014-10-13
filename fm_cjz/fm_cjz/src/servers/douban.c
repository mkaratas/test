#include <stdio.h>
#include <service_provider.h>
#include <string.h>
#include <debug.h>
#include <util.h>

#define MAXFILEDS 4096 
#define DOUBAN_LOGIN_API "http://www.douban.com/j/app/login"
#define DOUBAN_CHANNEL_API "http://www.douban.com/j/app/radio/channels"
#define DOUBAN_SONG_API "http://www.douban.com/j/app/radio/people"
#define DOUBAN_APP_NAME "radio_desktop_win"
#define DOUBAN_VERSION 100

typedef struct login_info {
    const char *user_id;
    const char *err;
    const char *token;
    const char *expire;
    const char *result;
    const char *user_name;
    const char *email;
} login_info_t;

typedef struct __douban {
	server sver;
	login_info_t info;

    char *login_api;
    char *song_api;
    char *channel_api;
    char *app_name;
	channel_entry cur_channel;
    int version;
	
	channel_entry *channels_list;
	song_entry *song_list;
} douban_t;

static int __douban_get_channel_list(douban_t *db, const proxy *pxy);

static const char *__object_strkey2strval(json_object *obj, const char *str)
{
	json_object *val_obj;

	json_object_object_get_ex(obj, str, &val_obj);
	return json_object_get_string(val_obj);
}

static int __object_strkey2intval(json_object *obj, const char *str)
{
    json_object *val_obj;

    json_object_object_get_ex(obj, str, &val_obj);
    return json_object_get_int(val_obj);
}

static void __douban_print_login_info(douban_t *db)
{
    LOGV("\n");
    LOGV("user_id  : %s\n", db->info.user_id);
    LOGV("err      : %s\n", db->info.err);
    LOGV("token    : %s\n", db->info.token);
    LOGV("expire   : %s\n", db->info.expire);
    LOGV("result   : %s\n", db->info.result);
    LOGV("user_name: %s\n", db->info.user_name);
    LOGV("email    : %s\n", db->info.email);
}

static int __douban_set_login_info(douban_t *db, const char *info_str)
{
	if (!info_str) {
		LOGE("__douban_set_login_info(): login info str is NULL\n");
		return -1;
	}

	static json_object *obj;
	if (obj) {
		printf("free object \n");
		json_object_put(obj);
	}
	obj = json_tokener_parse(info_str);

	if (!obj) {
		LOGD("parse info_str error\n");
		return -1;
	} else {
		LOGD("parse info_str\n");
		db->info.user_id = __object_strkey2strval(obj, "user_id");
		db->info.err = __object_strkey2strval(obj, "err");
		db->info.token = __object_strkey2strval(obj, "token");
		db->info.expire = __object_strkey2strval(obj, "expire");
		db->info.result = __object_strkey2strval(obj, "r");
		db->info.user_name = __object_strkey2strval(obj, "user_name");
		db->info.email = __object_strkey2strval(obj, "email");
		//printf("email: %s\n", db->info.email);
	}

	return 0;
}

static struct json_object* __douban_request_song_list(const douban_t *db, const proxy *pxy, char act)
{
    char url[1024];
    static char buffer[8096] = {0};
    bzero(buffer, sizeof(buffer));

	if (db->info.token) {
		sprintf(url, "%s?app_name=%s&version=%d&user_id=%s&expire=%s&token=%s&channel=%d&type=%c",
				db->song_api, db->app_name, db->version, db->info.user_id, db->info.expire, 
				db->info.token, db->cur_channel.id, act);
	} else {
		sprintf(url, "%s?app_name=%s&version=%d&channel=%d&type=%c",
				db->song_api, db->app_name, db->version, db->cur_channel.id, act);
	}
    LOGV("Playlist request: %s\n", url);

	pxy->get_request(pxy, url, buffer);

    return json_tokener_parse(buffer);
}

static void __douban_song_free(song_entry *song)
{       
    free(song->name);
    free(song->artist);
    free(song->album);
    free(song->picture);
    free(song->url);
    free(song);
}   


static void __douban_song_list_add(douban_t *db, song_entry *song)
{
	song->next = db->song_list;
	db->song_list = song;
}

/**
 * brief : delete a song node from song list head
 * param : db -- a pointer of douban server
 * return: a song struct variable pointer
 */
static song_entry* __douban_song_list_delete(douban_t *db)
{       
    song_entry *ret = NULL;

    if (db->song_list) {
        ret = db->song_list;
        db->song_list = db->song_list->next;
    }       
    return ret;
}     

static song_entry* __douban_song_parse_json(struct json_object *song_obj)
{
    song_entry *song = (song_entry*)malloc(sizeof(song_entry));
    const char json_escape = '\"';

	song->name = escape(__object_strkey2strval(song_obj, "title"), json_escape);
    song->artist = escape(__object_strkey2strval(song_obj, "artist"), json_escape);
    song->album = escape(__object_strkey2strval(song_obj, "albumtitle"), json_escape);
    song->picture = escape(__object_strkey2strval(song_obj, "picture"), json_escape);
    song->url = escape(__object_strkey2strval(song_obj, "url"), json_escape);
    song->id = __object_strkey2intval(song_obj, "sid");
    song->like = __object_strkey2intval(song_obj, "like");
    if (song->id == 0) {
        __douban_song_free(song);
        song = NULL;
    }
    return song;
}

static void __douban_song_json2song_list(douban_t *db, struct json_object *song_list_obj)
{
    int i;
	json_object *val_obj;

	//check if there's any error happend 
	json_object_object_get_ex(song_list_obj, "r", &val_obj);
    int ret = json_object_get_int(val_obj);
    if (ret != 0) {
		json_object_object_get_ex(song_list_obj, "err", &val_obj);
        LOGE("API error: %s\n", json_object_get_string(val_obj));
        exit(ret);
    }
	
	//parse song list json content
    LOGV("Playlist parsing new API response\n");
	json_object_object_get_ex(song_list_obj, "song", &val_obj);
    array_list *songs = json_object_get_array(val_obj);
	//printf("song num = %d\n", array_list_length(songs));

    for (i = songs->length - 1; i >= 0; i--) {
        struct json_object *song_obj = (struct json_object*)array_list_get_idx(songs, i);
        song_entry *song = __douban_song_parse_json(song_obj);
        if (song) {
            __douban_song_list_add(db, song);
            LOGV("song id: %d \nsong albumtitle: %s\nsong name: %s\nsong url: %s\n\n", song->id, song->album, song->name, song->url);
        }
    }

    json_object_put(song_list_obj);
}

/**
 * brief : request songs and add them to douban server's song list
 * param : db  -- pointer of douban server
 *         pxy -- pointer of a proxy which help us to get we requested
 * return:
 */
static void __douban_get_song_list(douban_t *db, const proxy *pxy)
{
	json_object *song_list_obj = __douban_request_song_list(db, pxy, 'n');
	__douban_song_json2song_list(db, song_list_obj);
}

void douban_login(server *sver, const proxy *pxy, const char *email, const char *pwd)
{
	LOGV("douban login\n");
	douban_t *db = (douban_t*)sver;
    char postfile[MAXFILEDS] = {0};
    char buffer[8196] = {0};
    bzero(buffer, sizeof(buffer));

    snprintf(postfile, sizeof(postfile), "email=%s&password=%s&app_name=%s&version=%d", 
			email, pwd, db->app_name, db->version);
    LOGD("postfile: %s\n", postfile);

	do {
		pxy->post_request(pxy, db->login_api, postfile, buffer);
		//here print login return json content
		//LOGD("login return data: %s\n", buffer);
		__douban_set_login_info(db, buffer);
	} while (!db->info.user_id || !db->info.err || !db->info.token || 
			!db->info.expire || !db->info.result || !db->info.user_name || !db->info.email);
	__douban_print_login_info(db);
	
 	__douban_get_channel_list(db, pxy);
}

int douban_save_login_info(server *sver, const char *infostr)
{
	__douban_set_login_info((douban_t*)sver, infostr);
}


song_entry* douban_next_song(server *sver, const proxy *pxy)
{
    int sid = 0;         
    printf("Playlist next song\n");
	douban_t *db = (douban_t*)sver;
    if (db->song_list) {
        __douban_song_free(__douban_song_list_delete(db));
        if (db->song_list == NULL) {
            printf("Playlist empty, request more\n");
			__douban_get_song_list(db, pxy);
        }
    } else {
        printf("Playlist init empty, request new\n");
		__douban_get_song_list(db, pxy);
    }  

    return db->song_list; 
}

void douban_logout(server *sver)
{
	LOGI("douban logout\n");
}

static void __douban_channel_free(channel_entry *channel)
{       
    free(channel->name);
    free(channel);
}   

static void __douban_channel_list_add(douban_t *db, channel_entry *channel)
{
	channel->next = db->channels_list;
	db->channels_list = channel;
}

static channel_entry* __douban_channel_parse_json(struct json_object *channel_obj)
{
    channel_entry *channel = (channel_entry*)malloc(sizeof(channel_entry));
    const char json_escape = '\"';

	channel->name = escape(__object_strkey2strval(channel_obj, "name"), json_escape);
    channel->id = __object_strkey2intval(channel_obj, "channel_id");

    return channel;
}

static void __douban_channels_json2channel_list(douban_t *db, struct json_object *channel_list_obj)
{
    int i;
	json_object *val_obj;

	//check if there's any error happend 
	json_object_object_get_ex(channel_list_obj, "r", &val_obj);
    int ret = json_object_get_int(val_obj);
    if (ret != 0) {
		json_object_object_get_ex(channel_list_obj, "err", &val_obj);
        LOGE("API error: %s\n", json_object_get_string(val_obj));
        exit(ret);
    }
	
	//parse channel list json content
    LOGV("Playlist parsing new API response\n");
	json_object_object_get_ex(channel_list_obj, "channels", &val_obj);
    array_list *channels = json_object_get_array(val_obj);

    for (i = channels->length - 1; i >= 0; i--) {
        struct json_object *channel_obj = (struct json_object*)array_list_get_idx(channels, i);
        channel_entry *channel = __douban_channel_parse_json(channel_obj);
        if (channel) {
            __douban_channel_list_add(db, channel);
            //LOGV("channel id: %d \nchannel name: %s\n\n", channel->id, channel->name);
        }
    }

    json_object_put(channel_list_obj);
}

static void __douban_print_channels(douban_t *db)
{
	LOGI("douban channels list\n");
	channel_entry *ch = db->channels_list;
	for (; ch->next; ch = ch->next) {
		LOGV("name: %s\n", ch->name);
		LOGV("id  : %d\n", ch->id);
	}
}

static int __douban_get_channel_list(douban_t *db, const proxy *pxy)
{
	LOGI("douban get channel list\n");
	if (!db || !pxy) {
		LOGE("server or proxy is invalid\n");
		return -1;
	}
    int i;
    char buffer[8196] = {0};             
    bzero(buffer, sizeof(buffer)); 

	
	db->channels_list ? __douban_channel_free(db->channels_list): NULL;
	pxy->get_request(pxy, db->channel_api, buffer);

    LOGV("%s", buffer);               

    json_object *channels_obj = json_tokener_parse(buffer);                                                                                                                                                  
	__douban_channels_json2channel_list(db, channels_obj);
	__douban_print_channels(db);

	return 0;
}

void douban_set_channel(server *sver, const proxy *pxy, const int channel_id)
{
	douban_t *db = (douban_t*)sver;
	if (!db->channels_list) {
		__douban_get_channel_list(db, pxy);
	}
	channel_entry *ch = db->channels_list;
	
	for (; ch; ch = ch->next) {
		if (ch->id == channel_id) {
			db->cur_channel.id = ch->id;
			strcpy(db->cur_channel.name, ch->name);
		}
	}
	LOGV("channel content\n");
	LOGV("name: %s\n", db->cur_channel.name);
	LOGV("id  : %d\n", db->cur_channel.id);
}

douban_t douban_pro = {
	.sver = {
		.name = "douban",
		.login = douban_login,
		.logout = douban_logout,
		.save_login_info = douban_save_login_info,
		//.get_channel_list = douban_get_channel_list,
		.next_song = douban_next_song,
		.set_channel = douban_set_channel,
	},

    .login_api = DOUBAN_LOGIN_API,
    .song_api = DOUBAN_SONG_API,
    .channel_api = DOUBAN_CHANNEL_API,
    .app_name = DOUBAN_APP_NAME,
    .version = DOUBAN_VERSION,
	.cur_channel = {
		.id = 1,
	},
	.song_list = NULL,
	.channels_list = NULL,
};

server *douban_server_register(void)
{
	LOGI("douban server register\n");
	return (server*)&douban_pro;
}
