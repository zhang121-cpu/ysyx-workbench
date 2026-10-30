# 默认生成目标
.DEFAULT_GOAL = app

WORK_DIR  = $(shell pwd)
BUILD_DIR = $(WORK_DIR)/build

INC_PATH := $(WORK_DIR)/include $(INC_PATH)
OBJ_DIR  = $(BUILD_DIR)/obj-$(NAME)$(SO)

# 对齐 nemu
CC  := gcc
CXX := g++
LD  := g++ 

INCLUDES = $(addprefix -I, $(INC_PATH))

# 与nemu对齐
CFLAGS := -O2 -MMD -Wall $(INCLUDES) $(CFLAGS)
LDFLAGS := -O2 $(LDFLAGS)

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# 编译规则：.c -> .o
$(OBJ_DIR)/%.o: %.c
	echo + CC $<
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c -o $@ $<
	$(call call_fixdep, $(@:.o=.d), $@)

# 依赖追踪
-include $(OBJS:.o=.d)

# 不等时用于 tools/kconfig（BINARY=build/conf）和 tools/fixdep（BINARY=build/fixdep）
# 相等时用于主程序的编译，其他相关内容在veilator.mk
ifneq ($(WORK_DIR),$(NPC_HOME))

BINARY = $(BUILD_DIR)/$(NAME)$(SO)

$(BINARY):: $(OBJS)
	echo + LD $@
	$(LD) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)

else
BINARY = $(BUILD_DIR)/Vtop
endif

.PHONY: app clean

app: $(BINARY)

clean:
	rm -rf $(BUILD_DIR)