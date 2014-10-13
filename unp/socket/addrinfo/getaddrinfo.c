#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUF_SIZE 500

int main(int argc, char **argv)
{
	int sfd, s;
	//sfd = socket(AF_UNIX, SOCK_STREAM, 0);

	struct addrinfo hints;
	struct addrinfo *result, *rp;
	struct sockaddr_storage peer_addr;
	socklen_t peer_addr_len;
	ssize_t nread;
	char buf[BUF_SIZE];

	bzero(&hints, sizeof(hints));
	hints.ai_flags = AI_PASSIVE | AI_ALL;//AI_CANONNAME;
	hints.ai_family = AF_INET;//AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	//hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = 0;
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;
	struct sockaddr_in *sinp;
	struct sockaddr_in6 *sin6p;
	char ipbuf[INET_ADDRSTRLEN] = {0};
	char ip6buf[INET6_ADDRSTRLEN] = {0};
	
	s = getaddrinfo(NULL, "10098", &hints, &result);
	if (s != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		exit(EXIT_FAILURE);
	}

	for (rp = result; rp != NULL; rp = rp->ai_next) {
		if (rp->ai_family == AF_INET) {
			sinp = (struct sockaddr_in *)rp->ai_addr;
			inet_ntop(AF_INET, &sinp->sin_addr, ipbuf, sizeof(ipbuf));
			printf("ip: %s\n", ipbuf);
		} else if (rp->ai_family == AF_INET6){
			sin6p = (struct sockaddr_in6 *)rp->ai_addr;
			inet_ntop(AF_INET6, &sin6p->sin6_addr, ip6buf, sizeof(ip6buf));
			printf("ip: %s\n", ip6buf);
		}
		/*sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
		if (sfd == -1) {
			continue;
		}
		if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0) 
			break;
		
		close(sfd);
		*/
	}
	
	/*
	if (rp == NULL) {
		fprintf(stderr, "Could not bind\n");
		exit(EXIT_FAILURE);
	}
	
	freeaddrinfo(result);
	
	for (;;) {
		peer_addr_len = sizeof(struct sockaddr_storage);
		nread = recvfrom(sfd, buf, BUF_SIZE, 0, (struct sockaddr *)&peer_addr, &peer_addr_len);
		if (nread == -1)
			continue;
		
		char host[NI_MAXHOST], service[NI_MAXSERV];
		s = getnameinfo((struct sockaddr *)&peer_addr, peer_addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICSERV);
		if (s == 0) {
			printf("Received %ld bytes from %s:%s\n", (long)nread, host, service);
		} else {
			fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));
		}
		if (sendto(sfd, buf, nread, 0, (struct sockaddr *)&peer_addr, peer_addr_len) != nread) {
			fprintf(stderr, "Error sending response\n");
		}
	}
	*/

	return 0;
}
