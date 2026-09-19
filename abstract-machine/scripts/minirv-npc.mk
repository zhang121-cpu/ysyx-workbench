include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/npc.mk

export PATH := $(PATH):$(abspath $(AM_HOME)/tools/minirv)
CC = minirv-gcc
AS = minirv-gcc
CXX = minirv-g++

COMMON_CFLAGS += -march=rv32e_zicsr -mabi=ilp32e  # overwrite
LDFLAGS       += -melf32lriscv                    # overwrite

AM_SRCS += riscv/npc/libgcc/div.S \
           riscv/npc/libgcc/muldi3.S \
           riscv/npc/libgcc/multi3.c \
           riscv/npc/libgcc/ashldi3.c \
           riscv/npc/libgcc/unused.c


# 修复：minirv 包装器丢掉了 -MMD 的头文件依赖，这里手动补回来，后面是追加依赖
AM_HDRS := $(shell find $(AM_HOME)/am/include \
                    $(AM_HOME)/am/src \
                    $(AM_HOME)/klib/include \
                    $(AM_HOME)/klib/src \
                    $(WORK_DIR) -name '*.h' 2>/dev/null)

$(OBJS): $(AM_HDRS)
