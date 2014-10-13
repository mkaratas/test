#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid1, tid2;

void *routine1(void *args)
{
	printf("routine 1\n");
	sleep(2);
	pthread_exit(NULL);
}

void *routine2(void *args)
{
	printf("routine 2\n");
	//pthread_exit(NULL);
	//exit(-1);
	return NULL;
}

int main(int argc, char **argv)
{
	if (pthread_create(&tid1, NULL, routine1, NULL) != 0) {
		perror("pthread_create()");
	}
	if (pthread_create(&tid2, NULL, routine2, NULL) != 0) {
		perror("pthread_create()");
	}

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("main thread exit\n");
	return 0;
}
