VERILATOR = verilator
VFLAGS    = --cc --exe --build -j 0 -Wall --trace-fst

# 自动收集所有源文件
VSRCS = $(wildcard vsrc/*.v)
CSRCS = $(wildcard csrc/*.cpp)

# 设定被加载程序，可被AM指定，默认情况下为空
IMG ?= 

all: run

run: build
	./obj_dir/Vtop $(IMG)

build:
	$(VERILATOR) $(VFLAGS) -Ivsrc --top-module top $(VSRCS) $(CSRCS)

clean:
	rm -rf obj_dir wave.fst

.PHONY: all run build clean

