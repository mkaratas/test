pathmap_INCL := \
    bootloader:bootable/bootloader/legacy/include \
    camera:system/media/camera/include \
    corecg:external/skia/include/core \
    frameworks-base:frameworks/base/include \
    frameworks-native:frameworks/native/include \
    graphics:external/skia/include/core \
    libc:bionic/libc/include \

sources := foo.c bar.c baz.s ugh.h

define include-path-for
$(foreach n, $(1), $(patsubst $(n):%, %, $(filter $(n):%, $(pathmap_INCL))))
endef

INC := bootloader libc

test:
	@#gcc test.c -o test
	@#echo $(filter %.c, $(sources))
	echo $(call include-path-for, $(INC))
	@#echo $(patsubst camera:%, %, $(filter camera:%, $(pathmap_INCL)))
	@#echo $(subst ee, EE, feet on the street)

.PHONY:clean
clean:
	rm -rf *.o test
