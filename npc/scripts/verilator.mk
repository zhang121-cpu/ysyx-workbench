# 这些只用于主程序的编译，tools/kconfig 和 tools/fixdep 不需要
ifeq ($(WORK_DIR),$(NPC_HOME))

# 在build.mk中将.c文件编译为.o文件
# verilator.mk中将.c和.cpp文件编译为.o文件
# 并将Verilog文件编译为可执行文件
VERILATOR ?= verilator

# 通用 VFLAGS（去掉 --build，分离生成和编译）
VFLAGS    ?= --cc --exe -j 0 -Wall --trace-fst

# 特定于当前NPC项目的 VFLAGS
NPC_VFLAGS = $(VFLAGS) --Mdir $(BUILD_DIR)/obj_dir

# 自动搜集所有源文件
VSRCS   = $(wildcard vsrc/*.v)
CSRCS   = $(wildcard csrc/*.cpp)

# LIBS：带条件（对齐 nemu 的写法），去掉 -pie（Verilator 链接不适用）
# 虽然目前似乎不可能触发这个条件，保留下来只是为了对齐 nemu 的写法
LIBS += $(if $(CONFIG_TARGET_NATIVE_ELF),-lreadline -ldl,)

# 只带入必要的标志，不带入 -MMD 和 -Wall
# -O2会发现在 $(CFLAGS_BUILD)中确认，在前面CFLAGS中加上是为了对齐 nemu 的写法
VERILATOR_CFLAGS = $(INCLUDES) $(CFLAGS_BUILD)

# 步骤 1：Verilator 生成 C++ 代码（不编译）
$(BUILD_DIR)/obj_dir/Vtop.cpp: $(VSRCS) $(CSRCS)
	@echo + VERILATE $@
	$(VERILATOR) $(NPC_VFLAGS) -Ivsrc --top-module top $(VSRCS) $(CSRCS)

# 步骤 2：编译 C++ 代码（编译链接成可执行文件）
$(BINARY):: $(OBJS) $(BUILD_DIR)/obj_dir/Vtop.cpp $(CSRCS)
	@echo + BUILD $@
	@rm -f $(BUILD_DIR)/wave.fst  # 删除上次的波形文件
	$(MAKE) -C $(BUILD_DIR)/obj_dir -f Vtop.mk \
		CXXFLAGS="$(VERILATOR_CFLAGS)" \
		LDFLAGS="$(OBJS) $(LIBS) $(LDFLAGS)"
	@mv $(BUILD_DIR)/obj_dir/Vtop $@  # 移动到 build/Vtop

endif

