#ifndef __PROXY_H__
#define __PROXY_H__

/**
 * brief: use post method to get data from a url publiced web server
 * param: pro -- pointer of a proxy variable
 *        url -- a url of web url
 *        postdata -- use post method to request data
 *        buf -- a buf pointer which saves reqeusted data from web sever
 * return: 
 *        size of received data
 */
typedef size_t (*proxy_post_request_t)(proxy *pro, const char *url, const char *postdata, char *buf);

typedef size_t (*proxy_get_request_t)(proxy *pro, const char *url, char *buf);

typedef struct __proxy {
	CURL *curl;
	proxy_post_request_t post_request;
	proxy_get_request_t get_request;
} proxy;

/**
 * brief:
 * param:
 * return:
 */
proxy* new_proxy(proxy *pro);

/**
 * brief:
 * param:
 * return:
 */
void delete_proxy(proxy *pro);

#endif /*__PROXY_H__*/
