CROSS_COMPILE=/home/CORPUSERS/xp014721/Downloads/usr/bin/arm-none-eabi-

ARCH=arm
# Make variables (CC, etc...)

AS      = $(CROSS_COMPILE)as
LD      = $(CROSS_COMPILE)ld
REAL_CC     = $(CROSS_COMPILE)gcc
CPP     = $(CC) -E
AR      = $(CROSS_COMPILE)ar
NM      = $(CROSS_COMPILE)nm
STRIP       = $(CROSS_COMPILE)strip
OBJCOPY     = $(CROSS_COMPILE)objcopy
OBJDUMP     = $(CROSS_COMPILE)objdump

export ARCH CROSS_COMPILE AS LD CC
export CPP AR NM STRIP OBJCOPY OBJDUMP


test: test.o
	$(CROSS_COMPILE)gcc -o test test.o

.PHONY:clean
clean:
	rm -rf test
