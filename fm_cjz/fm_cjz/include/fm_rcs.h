/**
 * Author: Jianzhong Cui
 * 
 * Copyright: Can not be used in commercial product
 */

#ifndef __FM_RCS_H__
#define __FM_RCS_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <string.h>
#include <fm_rcs.h>
#include <arpa/inet.h>
#include <debug.h>
#include <errno.h>
#include <sys/epoll.h>
#include <signal.h>

#define HOST_NAME NULL
#define SERVICE "10098"
#define LISTEN_BACKLOG 5

typedef struct __cb_param {
	int confd;
	void *data;
} cb_param;

typedef void *(*fm_rcs_cb)(void *);

typedef struct fm_rcs {
	char *hostname;
	char *service;
	int listen_fd;
	int consfd; //current connected client socket descripter
	fm_rcs_cb cb;
	void *data;
} fm_rcs_t;

int fm_rcs_start(fm_rcs_cb cb, void *data);
void fm_rcs_stop(fm_rcs_t *server);

/**
 * brief: Get client ip and port from socket descripter of connected
 * param: socket -- connected socket descripter
 *        ipstr -- pointer of client address storage buffer
 *        iplen -- client address buffer size
 *        port  -- pointer of client bind port
 */
void fm_rcs_get_peer_info(int socket, char *ipstr, int iplen, int *port);

#endif /*__FM_RCS_H__*/
