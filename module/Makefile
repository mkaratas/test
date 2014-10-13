CROSS_ARCH:=arm
ARCH=arm
#CROSS_COMPILE=arm-eabi-
CROSS_COMPILE=arm-linux-androideabi-
export CROSS_COMPILE CROSS_ARCH ARCH

#KDIR    := /home/CORPUSERS/xp014721/workspace/tianchi/kernel
KDIR=/home/CORPUSERS/xp014721/workspace/tianchi/out/target/product/tianchi/obj/KERNEL_OBJ
obj-m   := oops.o 
 
all: 
	#$(MAKE) -C $(KDIR) -I/home/CORPUSERS/xp014721/workspace/tianchi/kernel/include M=`pwd` modules
	$(MAKE) -C $(KDIR) M=`pwd` modules
clean:
	$(MAKE) -C $(KDIR) M=`pwd` modules clean
