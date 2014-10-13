all: getaddrinfo

getaddrinfo: getaddrinfo.c
	gcc -o $@ -Wall $^

.PHONY:clean
clean:
	rm -rf *.o .*.swp getaddrinfo
