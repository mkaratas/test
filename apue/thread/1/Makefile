all:thread

CFLAGS+=-pthread

thread:thread.c
	gcc $(CFLAGS) -o $@ $< 

.PHONY:clean
clean:
	rm -rf thread .*.swp *.o
