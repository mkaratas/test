SRCS:= \
	Persion.c \
	Employee.c \
	main.c

all: test

test: $(SRCS)
	gcc -o $@ $^ 

.PHONY:clean
clean:
	rm -rf test *.o .*.swp
