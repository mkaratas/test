
LOC_INCLUDE:= -I./include 
SRCS:= \
	src/provider.c \
	src/douban.c \
	src/lapsule.c \
	src/mytest.c \
	src/main.c

all: server

server: $(SRCS)
	gcc -g -o $@ $^ $(LOC_INCLUDE)

.PHONY:clean
clean:
	rm -rf *.o .*.swp server
