-include $(NPC_HOME)/../Makefile
include $(NPC_HOME)/scripts/build.mk
include $(NPC_HOME)/scripts/verilator.mk

include $(NPC_HOME)/tools/difftest.mk

compile_git:
	$(call git_commit, "compile NPC")
$(BINARY):: compile_git

override ARGS ?= --log=$(BUILD_DIR)/npc-log.txt
override ARGS += $(ARGS_DIFF)

override ELFFILE ?=
ifdef CONFIG_FTRACE
ifneq ($(ELFFILE),)  # 防止make run下空传
override ARGS += -e $(ELFFILE)   # 有 ELF 才加 -e
endif
endif

IMG ?=
NPC_EXEC := $(BINARY) $(ARGS) $(IMG)

run-env: $(BINARY) $(DIFF_REF_SO)

run: run-env
	$(call git_commit, "sim RTL")  # DO NOT REMOVE THIS LINE!!!
	$(NPC_EXEC)

gdb: run-env
	$(call git_commit, "gdb NPC")
	gdb -s $(BINARY) --args $(NPC_EXEC)

clean-tools = $(dir $(shell find ./tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	-@$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)
clean-all: clean distclean clean-tools

.PHONY: run gdb run-env clean-tools clean-all $(clean-tools) 
