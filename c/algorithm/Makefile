top=$(CURDIR)

target=test
src_files:= main.c 
obj_files:= $(patsubst %.c, %.o, $(src_files))

all: $(target)

$(target): $(obj_files)
	gcc -o test $^

$(obj_files) : $(src_files)

.PHONY:clean
clean:
	rm -rf $(target) $(obj_files) .*.swp
