#include <stdio.h>

typedef struct {                     
    char data[8192];
    size_t len;
} buffer_t;

static size_t proxy_receive_data(char *ptr, size_t size, size_t nmemb, void *userp)
{
    buffer_t *buffer = (buffer_t*) userp;
    size_t bytes = size * nmemb;
    memcpy(buffer->data + buffer->len, ptr, bytes); 
    buffer->len += bytes;
    return bytes;
}


size_t proxy_post_request(const proxy *pro, const char *url, const char *postdata, char *buf)
{
	buffer_t curl_buffer;
    LOGD("url: %s, postdata: %s\n", url, postdata);

    curl_easy_setopt(pro->curl, CURLOPT_URL, url);
    curl_easy_setopt(pro->curl, CURLOPT_POSTFIELDS, postdata);
	curl_easy_setopt(pro->curl, CURLOPT_USERAGENT, AGENT_NAME);
    curl_easy_setopt(pro->curl, CURLOPT_WRITEFUNCTION, proxy_receive_data);
    curl_easy_setopt(pro->curl, CURLOPT_WRITEDATA, &curl_buffer);

    curl_easy_perform(pro->curl);
	memcpy(buf, curl_buffer.data, curl_buffer.len);

	return curl_buffer.len;
}

size_t proxy_get_request(const proxy *pro, const char *url, char *buf)
{
    buffer_t curl_buffer;
    LOGD("url: %s, postdata: %s\n", url, postdata);

    curl_easy_setopt(pro->curl, CURLOPT_URL, url);
    //curl_easy_setopt(pro->curl, CURLOPT_POSTFIELDS, postdata);
    curl_easy_setopt(pro->curl, CURLOPT_USERAGENT, AGENT_NAME);
    curl_easy_setopt(pro->curl, CURLOPT_WRITEFUNCTION, proxy_receive_data);
    curl_easy_setopt(pro->curl, CURLOPT_WRITEDATA, &curl_buffer);

    curl_easy_perform(pro->curl);
    memcpy(buf, curl_buffer.data, curl_buffer.len);

    return curl_buffer.len;
}

proxy* new_proxy(void)
{
	proxy *pro = (proxy*)malloc(sizeof(proxy));
	if (!pro) {
		LOGE("malloc(): %s\n", strerror(errno));
		return NULL;
	}
	curl_global_init(CURL_GLOBAL_ALL);
	pro->curl = curl_easy_init();
	pro->post_request = proxy_post_request;
	pro->get_request = proxy_get_request;
}

void delete_proxy(proxy *pro)
{
	curl_easy_cleanup(pro->curl);
	free(pro);
	curl_global_cleanup();
}
