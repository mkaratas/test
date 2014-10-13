#include <stdio.h>
#include <provider.h>

#define AGENT_NAME "CJZ"
#define MAXURL 1024
#define MAXFILEDS 4096 
#define DOUBAN_LOGIN_API "http://www.douban.com/j/app/login"
#define DOUBAN_CHANNEL_API "http://www.douban.com/j/app/radio/channels";
#define DOUBAN_SONG_API "http://www.douban.com/j/app/radio/people";
#define DOUBAN_APP_NAME "radio_desktop_win"
#define DOUBAN_VERSION 100

extern provider_t *rprovider;

typedef struct {            
    char data[8192];              
    size_t length;              
} buffer_t;

typedef struct douban {
	provider_t pro;

    char *login_api;
    char *song_api;
    char *channel_api;
    char *app_name;
    int version;
} douban_t;

static size_t douban_data_receive(char *ptr, size_t size, size_t nmemb, void *userp)
{
    buffer_t *buffer = (buffer_t*) userp;
    size_t bytes = size * nmemb;
    memcpy(buffer->data + buffer->length, ptr, bytes);
    buffer->length += bytes;
    return bytes;
}

static void douban_provider_init(douban_t *db)
{
    curl_global_init(CURL_GLOBAL_ALL);
    db->pro->curl = curl_easy_init();

    db->login_api = DOUBAN_LOGIN_API;
    db->song_api = DOUBAN_SONG_API;
    db->channel_api = DOUBAN_CHANNEL_API;
    db->app_name = DOUBAN_APP_NAME;
    db->version = DOUBAN_VERSION;
}

static void douban_login(provider_t *db, const char *email, const char *pwd)
{
	printf("douban login\n");
	douban_t *db = (douban_t*)pro;
    char posturl[MAXURL] = {0};
    char postfile[MAXFILEDS] = {0};
    static buffer_t curl_buffer;
    bzero(curl_buffer.data, sizeof(curl_buffer.data));
    curl_buffer.length = 0;

    snprintf(postfile, sizeof(postfile), "email=%s&password=%s&app_name=%s&version=%d", 
				email, pwd, db->app_name, db->version);
    LOGD("postfile: %s\n", postfile);

    curl_easy_setopt(db->curl, CURLOPT_URL, db->login_api);
    curl_easy_setopt(db->curl, CURLOPT_POSTFIELDS, postfile);
    curl_easy_setopt(db->curl, CURLOPT_USERAGENT, AGENT_NAME);

    curl_easy_setopt(db->curl, CURLOPT_WRITEFUNCTION, douban_data_receive);
    curl_easy_setopt(db->curl, CURLOPT_WRITEDATA, &curl_buffer);
    curl_easy_perform(db->curl);

    LOGD("curl_buffer.length: %zu\nmcurl_buffer.data: %s", curl_buffer.length, curl_buffer.data);
    json_object *obj = json_tokener_parse(curl_buffer.data);
    db->info.user_id = json_object_get_string(json_object_object_get(obj, "user_id"));
    db->info.err = json_object_get_string(json_object_object_get(obj, "err"));
    db->info.token = json_object_get_string(json_object_object_get(obj, "token"));
    db->info.expire = json_object_get_string(json_object_object_get(obj, "expire"));
    db->info.result = json_object_get_string(json_object_object_get(obj, "r"));
    db->info.user_name = json_object_get_string(json_object_object_get(obj, "user_name"));
    db->info.email = json_object_get_string(json_object_object_get(obj, "email"));
    printf("\n");
    LOGI("user_id  : %s\n", db->info.user_id);
    LOGI("err      : %s\n", db->info.err);
    LOGI("token    : %s\n", db->info.token);
    LOGI("expire   : %s\n", db->info.expire);
    LOGI("result   : %s\n", db->info.result);
    LOGI("user_name: %s\n", db->info.user_name);
    LOGI("email    : %s\n", db->info.email);
}


void douban_logout(provider_t *pro)
{
	printf("douban logout\n");
}

channels_list_t *douban_get_channel_list(provider_t *pro)
{
	printf("douban get channel list\n");
}

channels_list_t *douban_get_channel_list(provider_t *pro)
{
	douban_t *db = (douban_t*)pro;
    int i;
    static buffer_t curl_buffer;                  
    bzero(curl_buffer.data, sizeof(curl_buffer.data)); 
    curl_buffer.length = 0; 

    curl_easy_setopt(db->curl, CURLOPT_USERAGENT, AGENT_NAME);
    curl_easy_setopt(db->curl, CURLOPT_URL, db->channel_api);
    curl_easy_setopt(db->curl, CURLOPT_WRITEFUNCTION, data_receive);
    curl_easy_setopt(db->curl, CURLOPT_WRITEDATA, curl_buffer.data);
    curl_easy_perform(db->curl);
    printf("%s", curl_buffer.data);               

    json_object *obj = json_tokener_parse(curl_buffer.data);                                                                                                                                                  

    //array_list *channels = json_object_get_array(json_object_object_get(obj, "channels"));
    json_object *channels = json_object_object_get(obj, "channels");
    array_list *chans = json_object_get_array(channels);
    LOGE("channels num = %d\n", array_list_length(chans));                                                                                                                                                    

    int array_length = json_object_array_length(channels);
    LOGD("lenghth = %d\n", array_length);

    json_object *channel8 = json_object_array_get_idx(channels, 38);                                                                                                                                          
       
    channels_t ch;      
    ch.name_en = json_object_get_string(json_object_object_get(channel8, "name_en"));
    ch.seq_id = json_object_get_string(json_object_object_get(channel8, "seq_id"));
    ch.abbr_en    = json_object_get_string(json_object_object_get(channel8, "abbr_en"));
    ch.name  = json_object_get_string(json_object_object_get(channel8, "name"));
    ch.channel_id = json_object_get_string(json_object_object_get(channel8, "channel_id"));                                                                                                                   
       
    LOGI("name_en   : %s\n", ch.name_en);         
    LOGI("seq_id    : %s\n", ch.seq_id);          
    LOGI("abbr_en   : %s\n", ch.abbr_en);         
    LOGI("name      : %s\n", ch.name);            
    LOGI("channel_id: %s\n", ch.channel_id);
/*
    if (channels) {
        for (i = 0; array_list_length(channels); i++) {
            struct json_object *o = (struct json_object*)array_list_get_idx(channels, i);                                                                                                                     
            LOGD("i = %d\n", i);
        }
    }
*/
}

douban_t douban_pro = {
	.pro = {
		.name = "douban",
		.login = douban_login,
		.logout = douban_logout,
		.get_channel_list = douban_get_channel_list,
	},
	.curl = "http://cjzswust.com.cn",
};

void douban_douban_register(void)
{
	douban_provider_init(&douban_pro)

	provider_add((provider_t*)&douban_pro);
}
