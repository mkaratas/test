all:thread

thread: thread.c
	gcc -o $@ $^ -lpthread

.PHONY:clean
clean:
	rm -rf *.o .*.swp thread
