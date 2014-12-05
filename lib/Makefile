#$(CURDIR)/Makefile Makefile: ;

srctree := $(if $(CURDIR),,) 
objtree := $(CURDIR)
src:=$(srctree)
obj:=$(objtree)

CROSS_COMPILE   ?=

# Make variables (CC, etc...)

AS      = $(CROSS_COMPILE)as
LD      = $(CROSS_COMPILE)ld
CC      = $(CROSS_COMPILE)gcc
CPP     = $(CC) -E
AR      = $(CROSS_COMPILE)ar
NM      = $(CROSS_COMPILE)nm
STRIP       = $(CROSS_COMPILE)strip
OBJCOPY     = $(CROSS_COMPILE)objcopy
OBJDUMP     = $(CROSS_COMPILE)objdump
AWK     = awk
GENKSYMS    = scripts/genksyms/genksyms
INSTALLKERNEL  := installkernel
DEPMOD      = /sbin/depmod
PERL        = perl
CHECK       = sparse

INCLUDE    := \
        -Iinclude \

CFLAGS += -O2 -Wall

all:test

test: test.c include/marco.h
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^

.PHONY:clean
clean:
	rm -rf test .*.swp *.o

