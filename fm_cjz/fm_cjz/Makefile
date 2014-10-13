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
HOSTCFLAGS   = -g -Wall -Wmissing-prototypes -Wstrict-prototypes -fomit-frame-pointer 
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

YTINCLUDE := \
		-I$(srctree)/include \
		-I$(srctree)/include/upnp \

YTLIBS := \
		-L$(srctree)/lib -lcurl -pthread -ljson-c -lupnp -lthreadutil -lixml

export SUBARCH ARCH CROSS_COMPILE HOSTCC HOSTCXX HOSTCFLAGS HOSTCXXFLAGS
export AS LD CC CPP AR NM STRIP OBJCOPY OBJDUMP

SERVER_SRC := \
	src/fm_rcs.c \
	src/util.c \
	src/proxy.c \
	src/service_provider.c \
	src/cmd_parse.c \
	src/server.c \
	src/upnp_util.c \
	src/upnp_player.c \
	src/servers/douban.c \
	src/servers/lapsule.c

CLIENT_SRC := \
	src/client.c

INCLUDE_FILE := \
	$(srctree)/include/debug.h \
	$(srctree)/include/service_provider.h \
	$(srctree)/include/fm_rcs.h \
	$(srctree)/include/proxy.h \
	$(srctree)/include/upnp_util.h \
	$(srctree)/include/upnp_player.h

.PHONY:_all
_all:server client

server: $(SERVER_SRC) $(INCLUDE_FILE)
	$(CC) $(YTINCLUDE) -o $@ $^ $(YTLIBS)

client: $(CLIENT_SRC)
	$(CC) -o $@ $^ $(YTLIBS)

.PHONY: clean
clean:
	rm -rf test xiami server client *.o .*.swp *.log *.cookie core
