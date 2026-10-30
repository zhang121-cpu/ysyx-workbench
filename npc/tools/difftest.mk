ifdef CONFIG_DIFFTEST
# 编译npc对应的REF文件
DIFF_REF_PATH = $(NPC_HOME)/$(call remove_quote,$(CONFIG_DIFFTEST_REF_PATH))
DIFF_REF_SO = $(DIFF_REF_PATH)/build/$(GUEST_ISA)-$(call remove_quote,$(CONFIG_DIFFTEST_REF_NAME))-so
MKFLAGS = GUEST_ISA=$(GUEST_ISA) SHARE=1 ENGINE=interpreter
# 生成npc启动参数
ARGS_DIFF = --diff=$(DIFF_REF_SO)

# CONFIG_DIFFTEST_REF_NEMU这个参数表示是否使用NEMU作为参考模型
# 当前格式是为了对齐NEMU，后续考虑difftest时进行大规模修改
ifndef CONFIG_DIFFTEST_REF_NEMU
$(DIFF_REF_SO):
    $(MAKE) -s -C $(DIFF_REF_PATH) $(MKFLAGS)
endif

.PHONY: $(DIFF_REF_SO)
endif