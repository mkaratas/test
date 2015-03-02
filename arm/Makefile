#CROSS_COMPILE=/home/CORPUSERS/xp014721/Downloads/usr/bin/arm-none-eabi-
CROSS_COMPILE=/home/CORPUSERS/xp014721/Downloads/arm_gcc/gcc-arm-none-eabi-4_8-2014q1/bin/arm-none-eabi-

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

CFLAGS+= --specs=nosys.specs -g

test: test.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -o $@ $^ 

loop: loop.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -o $@ $^ 

.PHONY:clean
clean:
	rm -rf test
