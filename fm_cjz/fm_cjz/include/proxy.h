/**
 * Author: Jianzhong Cui
 * 
 * Copyright: Can not be used in commercial product
 */

#ifndef __PROXY_H__
#define __PROXY_H__

#include <curl/curl.h>

#define AGENT_NAME "CJZ"

typedef struct __proxy proxy;
/**
 * brief: use post method to get data from a url publiced web server
 * param: pro -- pointer of a proxy variable
 *        url -- a url of web url
 *        postdata -- use post method to request data
 *        buf -- a buf pointer which saves reqeusted data from web sever
 * return: 
 *        size of received data
 */
typedef size_t (*fptr_proxy_post_request)(const proxy *pro, const char *url, const char *postdata, char *buf);

typedef size_t (*fptr_proxy_get_request)(const proxy *pro, const char *url, char *buf);

typedef struct __proxy {
	CURL *curl;
	fptr_proxy_post_request post_request;
	fptr_proxy_get_request get_request;
} proxy;

/**
 * brief:
 * param:
 * return:
 */
proxy* new_proxy(void);

/**
 * brief:
 * param:
 * return:
 */
void delete_proxy(proxy *pro);

#endif /*__PROXY_H__*/
