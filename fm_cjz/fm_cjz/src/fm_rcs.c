/**
 * Author: Jianzhong Cui
 * 
 * Copyright: Can not be used in commercial product
 */

#include <stdio.h>
#include <fm_rcs.h>

#define MAX_EVENTS 10

pthread_t fm_rcs_tid;

static void __fm_show_host_info(const struct addrinfo *info)
{
	char ip_addr[INET6_ADDRSTRLEN] = {0};
	if (info->ai_family == AF_INET) {
		struct sockaddr_in *sa = (struct sockaddr_in*)info->ai_addr;
		if (!inet_ntop(info->ai_family, (void*)&sa->sin_addr, ip_addr, sizeof(ip_addr))) {
			LOGE("inet_ntop(): %s\n", strerror(errno));
		} else {
			LOGD("server: %s\n", ip_addr);
		}
	} else if (info->ai_family == AF_INET6) {
		struct sockaddr_in6 *sa = (struct sockaddr_in6*)info->ai_addr;
		if (!inet_ntop(info->ai_family, (void*)&sa->sin6_addr, ip_addr, sizeof(ip_addr))) {
			LOGE("inet_ntop(): %s\n", strerror(errno));
		} else {
			LOGD("server: %s\n", ip_addr);
		}

	} else {
		LOGE("no such socket family\n");
	}
}

/**
 * brief: set the descripter which passed as parameter noblock
 * param: sockfd -- socket file descripter
 */
static void __fm_set_nonblocking(const int sockfd) {  
    int opts;  
  
    opts = fcntl(sockfd, F_GETFL);  
    if(opts < 0) {  
        LOGE("fcntl(F_GETFL)\n");  
        exit(EXIT_FAILURE);  
    }  
    opts = (opts | O_NONBLOCK);  
    if(fcntl(sockfd, F_SETFL, opts) < 0) {  
        LOGE("fcntl(F_SETFL)\n");  
        exit(EXIT_FAILURE);  
    }  
}  

/**
 * brief: Get client ip and port from socket descripter of connected
 * param: socket -- connected socket descripter
 *        ipstr -- pointer of client address storage buffer
 *        iplen -- client address buffer size
 *        port  -- pointer of client bind port
 */
void fm_rcs_get_peer_info(int socket, char *ipstr, int iplen, int *port) {
    socklen_t len;          
    struct sockaddr_storage addr;         

    len = sizeof(addr);    
    getpeername(socket, (struct sockaddr*) &addr, &len);

    if (addr.ss_family == AF_INET) {
        struct sockaddr_in *s = (struct sockaddr_in *) &addr; 
        *port = ntohs(s->sin_port);
        inet_ntop(AF_INET, &s->sin_addr, ipstr, iplen);    
    }
    else {
        struct sockaddr_in6 *s = (struct sockaddr_in6 *) &addr;
        *port = ntohs(s->sin6_port);
        inet_ntop(AF_INET6, &s->sin6_addr, ipstr, iplen);  
    }
}

/**
 * Brief : Once a new client connected, this function create a thread to communicate with this client
 * param : prcs -- 
 *         worker -- a call back fuction to communicate with the client
 * return:  0 -- successfule
 *         -1 -- failed
 */
static int __fm_handle_the_connected_socket(fm_rcs_t *prcs)
{
	
	pthread_attr_t attr;
	pthread_t thread;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	if (pthread_create (&thread, &attr, prcs->cb, prcs)) {
		LOGE("pthread_create(): %s\n", strerror(errno));
		return -1;
	}
	pthread_attr_destroy (&attr);
	
	return 0;
}

/*
 * Brief : 
 * param : prcs -- a fm_rcs_t type variable including hostname and service port
 * return: void
 */
static int __fm_rcs_accept(fm_rcs_t *prcs)
{
	int ret = 0;
	int i;
	struct sockaddr_storage client_addr;
	socklen_t client_addrlen = sizeof(struct sockaddr_storage);
	struct epoll_event ev, events[MAX_EVENTS];
	int epollfd, nfds, consfd;

	epollfd = epoll_create(10); //the parameter of epoll_create is no longer used, but it must greater than 0;
	if (epollfd == -1) {
		LOGE("epoll_create(): %s\n", strerror(errno));	
		ret = -1;
		goto error_out1;
	}
	
	ev.events = EPOLLIN;
	ev.data.fd = prcs->listen_fd;
	
	if (epoll_ctl(epollfd, EPOLL_CTL_ADD, prcs->listen_fd, &ev) == -1) {
		LOGE("epoll_ctl(): %s\n", strerror(errno));
		ret = -1;
		goto error_out2;
	}

	struct sigaction act;
	act.sa_handler = SIG_IGN;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, 0);

	for (;;) {
		nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
		if (nfds == -1) {
			LOGI("errno = %d, EINTR = %d\n", errno, EINTR);
			if (errno == EINTR) {
				LOGE("woke up by signal\n");
				//continue;
			}
			LOGE("epoll_wait(): %s\n", strerror(errno));
			ret = -1;
			goto error_out1;
		}
		for (i = 0; i < nfds; i++) {
			if (events[i].data.fd == prcs->listen_fd) {
				consfd = accept(prcs->listen_fd, (struct sockaddr*)&client_addr, &client_addrlen);
				if (consfd == -1) {
					LOGE("accept(): %s\n", strerror(errno));
				} else {
					prcs->consfd = consfd;
					__fm_handle_the_connected_socket(prcs);
				}
				continue;
			}
		}
	}

error_out2:
	close(epollfd);

error_out1:
	return ret;
}

/*
 * Brief    : Create a noblock socket and bind it to a specified port by prcs->service
 * parameter: prcs -- including hostname and port
 * return   : on success, zero is returned
 *            on error, -1 is returned 
 */
static int __fm_rcs_init(fm_rcs_t *prcs)
{
	int ret = 0;
	struct addrinfo hints;
	struct addrinfo *result, *rp;

	bzero(&hints, sizeof(hints));

	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;
	hints.ai_addr = NULL;
	hints.ai_addrlen = 0;
	hints.ai_canonname = NULL;
	hints.ai_next = NULL;
	
	if (ret = getaddrinfo(prcs->hostname, prcs->service, &hints, &result) != 0) {
		LOGE("getaddrinfo(): %s\n", gai_strerror(ret));
		//exit(EXIT_FAILURE);
		ret = -1;
		goto out1;
	}

	for (rp = result; rp != NULL; rp = rp->ai_next) {
		prcs->listen_fd = socket(rp->ai_family, rp->ai_socktype, 0);
		if (prcs->listen_fd == -1) {
			continue;
		} else {
			LOGV("socket create successfully\n");
		}
		//1.set nonblock socket
		__fm_set_nonblocking(prcs->listen_fd);

		//2.set socket reuse property
		//in order to make server restart quickly
        int opt = 1;
        setsockopt(prcs->listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	
		//3.set slinger if necessary to deal with the TIME_WAIT problem

		if (bind(prcs->listen_fd, rp->ai_addr, rp->ai_addrlen) == -1) {
			LOGE("bind(): %s\n", strerror(errno));	
			//exit(EXIT_FAILURE);
			ret = -1;
		} else {
			LOGV("bind successfully\n");
			ret = 0;
			break;
		}
		close(prcs->listen_fd);
	}
	if (rp == NULL) {
		LOGE("socket creat failed\n");
		//exit(EXIT_FAILURE);
		ret = -1;
		goto out3;
	}
	//why port number is not same as getaddrinfo's second parameter
	//LOGD("port: %u\n", ((struct sockaddr_in*)rp->ai_addr)->sin_port);
	
	__fm_show_host_info(result);

	freeaddrinfo(result);
	if (listen(prcs->listen_fd, LISTEN_BACKLOG) == -1) {
		LOGE("listen(): %s\n", strerror(errno));
		//exit(EXIT_FAILURE);
		close(prcs->listen_fd);
		ret = -1;
		goto out2;
	}

	if (__fm_rcs_accept(prcs) == -1) {
		//close(prcs->listen_fd);
		//exit(EXIT_FAILURE);
		ret = -1;
		goto out2;
	}
	goto out1;


out3: 
	freeaddrinfo(result);
out2:
	close(prcs->listen_fd);
out1:
	return ret;
}

static void __fm_rcs_destroy(fm_rcs_t *prcs)
{
	close(prcs->listen_fd);
	free(prcs);
}

/**
 * brief: this thread is used to create a remote control server, 
 *        and accept connections from remote client
 */
static void *__fm_rcs_thread(void *args)
{
	fm_rcs_t *prcs = (fm_rcs_t*)args;

	if (__fm_rcs_init(prcs) < 0) {
		LOGE("Remote control server start failed\n");
		exit(EXIT_FAILURE);
	}

	__fm_rcs_destroy(prcs);

	return NULL;
}

int fm_rcs_start(fm_rcs_cb cb, void *data)
{
    pthread_attr_t attr;

    //pthread_attr_init(&attr);
    //pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	fm_rcs_t *prcs = (fm_rcs_t*)malloc(sizeof(fm_rcs_t));
	if (!prcs) {
		LOGE("malloc(): %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	prcs->hostname = HOST_NAME;
	prcs->service = SERVICE;
	prcs->cb = cb;
	prcs->data = data;

	if (pthread_create(&fm_rcs_tid, NULL, __fm_rcs_thread, prcs)) {
		LOGE("pthread_create(): %s\n", strerror(errno));
		return -1;
	}

	//pthread_attr_destroy(&attr);
	
	return 0;
}

void fm_rcs_end(void)
{
	pthread_join(fm_rcs_tid, NULL);
}

/**
 * brief: stop this remote control server
 */
void fm_rcs_stop(fm_rcs_t *prcs)
{
	kill(getpid(), SIGUSR1);
}

