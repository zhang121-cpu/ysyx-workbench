AM_SRCS := native/trm.c \
           native/ioe.c \
           native/cte.c \
           native/trap.S \
           native/vme.c \
           native/mpe.c \
           native/platform.c \
           native/ioe/input.c \
           native/ioe/timer.c \
           native/ioe/gpu.c \
           native/ioe/uart.c \
           native/ioe/audio.c \
           native/ioe/disk.c \

CFLAGS  += -fpie $(shell sdl2-config --cflags)
ASFLAGS += -fpie -pie
comma = ,

# -pie,-ldl与abstract-machine/am/src/native/platform.c中的dlsym(RTLD_NEXT, ...)配合，
#能够让SDL库内部使用的malloc函数必然调用glibc中的实现而不是klib中的
LDFLAGS_CXX = $(addprefix -Wl$(comma), $(LDFLAGS)) -pie -ldl $(shell sdl2-config --libs)

run: image
	$(IMAGE).elf

gdb: image
	gdb -ex "handle SIGUSR1 SIGUSR2 SIGSEGV noprint nostop" $(IMAGE).elf
