srctree	:= $(CURDIR)
export srctree

SUBARCH := $(shell uname -m | sed -e s/i.86/x86/ -e s/x86_64/x86/ \
                  -e s/sun4u/sparc64/ \
                  -e s/arm.*/arm/ -e s/sa110/arm/ \
                  -e s/s390x/s390/ -e s/parisc64/parisc/ \
                  -e s/ppc.*/powerpc/ -e s/mips.*/mips/ \
                  -e s/sh[234].*/sh/ -e s/aarch64.*/arm64/ )

ARCH        ?= $(SUBARCH)
CROSS_COMPILE   ?= 

HOSTCC       = gcc
HOSTCXX      = g++
HOSTCFLAGS   = -g -Wall -Wmissing-prototypes -Wstrict-prototypes -O2 -fomit-frame-pointer -Wdeprecated-declarations
HOSTCXXFLAGS = -O2

AS      = $(CROSS_COMPILE)as
LD      = $(CROSS_COMPILE)ld
CC      = $(CROSS_COMPILE)gcc
CPP     = $(CC) -E
AR      = $(CROSS_COMPILE)ar
NM      = $(CROSS_COMPILE)nm
STRIP       = $(CROSS_COMPILE)strip
OBJCOPY     = $(CROSS_COMPILE)objcopy
OBJDUMP     = $(CROSS_COMPILE)objdump

CINC := \
		-I$(srctree)/include

CLIBS := \
		-L$(srctree)/lib -pthread

export SUBARCH ARCH CROSS_COMPILE HOSTCC HOSTCXX HOSTCFLAGS HOSTCXXFLAGS
export AS LD CC CPP AR NM STRIP OBJCOPY OBJDUMP

SRCS := \
	fonts/font_8x12.c \
	fonts/font_12x20.c \
	fonts/font_24x38.c \
	graphic.c \
	fbcon.c \
	screen.c \
	main.c

.PHONY:_all
_all:fb

fb: $(SRCS)
	$(CC) $(CINC) -o $@ $^ $(CLIBS)

.PHONY: clean
clean:
	rm -rf fb *.o .*.swp *.log *.cookie
