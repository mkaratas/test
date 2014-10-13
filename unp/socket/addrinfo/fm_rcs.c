#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include "fm_rcs.h"

fm_rcs *get_rcs_instance(void)
{
	static fm_rcs *server = NULL;
	
	if (server) {
		return server;
	}

	server = (fm_rcs*)malloc(sizeof(fm_rcs));
	if (!server) {
		perror("malloc() at get_rcs_instance");
	}
	fm_rcs_constructor(server);

	return server;
}

void fm_rcs_constructor(fm_rcs *server)
{
	server->ops.setup = __fm_rcs_setup();
}

int __fm_rcs_setup(int argc, char **argv)
{
	int ret = 0;
	char buf[100] = {0};
	struct addrinfo hints; 
	struct addrinfo *result, *rp;
	struct sockaddr_in *sa;

	if ( gethostname(buf, sizeof(buf)) < 0 ) {
		perror("gethostname()");
		return -1;
	}

	bzero(&hints, sizeof(hints));
	hints.ai_flags = AI_CANONNAME;
	hints.ai_family = AF_UNSPEC;
	if ( (ret = getaddrinfo(buf, NULL, &hints, &result)) != 0 ) {
		fprintf(stderr, "getaddrinfo(): %s\n", gai_strerror(ret));
		return -1;
	}
	
	rp = result;
	for (rp = result; rp != NULL && rp->ai_canonname; rp = rp->ai_next) {
		sa = (struct sockaddr_in *)rp->ai_addr;
		printf("name: %s\nip:%s\n\n", rp->ai_canonname, 
				inet_ntop(AF_INET, &sa->sin_addr.s_addr, buf, sizeof(buf)));
	}

	return 0;
}
