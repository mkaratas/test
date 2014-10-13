/**
 * Author: Jianzhong Cui
 * 
 * Copyright: Can not be used in commercial product
 */

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int sfd;
	unsigned char buf[sizeof(struct in_addr)] = {0};
	struct sockaddr_in addr;
	sfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10098);
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	
	if (connect(sfd, (struct sockaddr*)&addr, sizeof(struct sockaddr)) < 0) {
		perror("connect()");
	}
	char send_buf[1024] = {0};
	while(1) {
		//fgets(send_buf, sizeof(send_buf), stdin);
		//gets(send_buf);
		//printf("%s\n", send_buf);
		//fputs(send_buf, stdout);
		printf("%s\n", fgets(send_buf, sizeof(send_buf), stdin));
		write(sfd, send_buf, strlen(send_buf));
		//write(sfd, send_buf, strlen(send_buf));
	}
	while(1) {
		sleep(100);
	}
	close(sfd);
	return 0;
}
