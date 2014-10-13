#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>


void *routine(void *args)
{
	int i;
	printf("sub thread id = %d\n", getpid());
	printf("sub thread tid = %d\n", pthread_self());
	for (i = 0; i < 10; i++) {
		printf("in thread\n");
		sleep(1);
	}
	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t tid;
	printf("main thread id = %d\n", getpid());
	printf("main thread tid = %d\n", pthread_self());
	if (pthread_create(&tid, NULL, routine, NULL)) {
		perror("pthread_create()");
		exit(-1);
	}
	pthread_join(tid, NULL);
	return 0;
}
