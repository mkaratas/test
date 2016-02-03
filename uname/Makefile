srctree=$(CURDIR)

CC=gcc
CXX=g++
CFLAGS= -O2 -Wall

LOCAL_DIR:=$(GET_LOCAL_DIR)

all: hello
	echo $(LOCAL_DIR)
	echo $(GET_LOCAL_DIR)
hello: hello.c
	$(CC) $(CFLAGS) -o $@ $^


PHONY:clean
clean:
	rm -rf hello .*.swp
