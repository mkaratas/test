#ifndef __PROVIDER_H__
#define __PROVIDER_H__

struct provider;
struct channels;

typedef struct login_info {
    const char *user_id;
    const char *err;
    const char *token;
    const char *expire;
    const char *result;
    const char *user_name;
    const char *email;
} login_info_t;

typedef struct song_info {
    const char *picture;
    const char *song_id;
    const char *like;    
    const char *artists_name;
    const char *duration;
    const char *songurl;
    const char *song_name;
    const char *ssid;                             
    const char *albumsname; 
} song_info_t;                                    


typedef struct song_list {
    int song_num; 
    song_info_t *current_song;
} song_list_t;

typedef struct channels {
    const char *name;  
    const char *channel_id;
    const char *name_en;
    const char *seq_id;
    const char *abbr_en;
} channels_list_t;

typedef struct provider {
	char *name;
	CURL *curl;
	login_info_t info;

	void (*login)(struct provider* pro, const char *usr, const char *pwd);
	void (*logout)(struct provider* pro);
	channels_list_t *(*get_channel_list)(struct provider *pro);
	song_list_t *(*get_song_list)(struct provider *pro);
	
	struct provider *next;
} provider_t;

extern provider_t *providers_head;

int provider_add(provider_t *pro);
provider_t *get_provider_by_name(const char *name);

#endif /*__PROVIDER_H__*/
