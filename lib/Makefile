#$(CURDIR)/Makefile Makefile: ;

#Use "make V=1" to see the full command
ifeq ("$(origin V)", "command line")
	KBUILD_VERBOSE = $(V)
endif
ifndef KBUILD_VERBOSE
	KBUILD_VERBOSE = 0
endif



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

CFLAGS += -O2 -Wall -Wdeprecated-declarations

SRCS := \
	test.c \
	include/marco.h

all:test log

.PHONY: log
log:
	echo $(KBUILD_VERBOSE)

#test: test.c include/marco.h
test: $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(filter %c, $(SRCS))

.PHONY:clean
clean:
	rm -rf test .*.swp *.o

