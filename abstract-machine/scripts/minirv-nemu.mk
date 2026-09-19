include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/nemu.mk

export PATH := $(PATH):$(abspath $(AM_HOME)/tools/minirv)
CC = minirv-gcc
AS = minirv-gcc
CXX = minirv-g++

CFLAGS  += -DISA_H=\"riscv/riscv.h\"
COMMON_CFLAGS += -march=rv32i_zicsr -mabi=ilp32  # overwrite
LDFLAGS       += -melf32lriscv                   # overwrite

AM_SRCS += riscv/nemu/start.S \
           riscv/nemu/cte.c \
           riscv/nemu/trap.S \
           riscv/nemu/vme.c

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
