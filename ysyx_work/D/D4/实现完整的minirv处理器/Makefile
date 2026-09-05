VERILATOR = verilator
VFLAGS    = --cc --exe --build -j 0 -Wall --trace-fst

# 自动收集所有源文件
VSRCS = $(wildcard vsrc/*.v)
CSRCS = $(wildcard csrc/*.cpp)

all: build

build:
	$(VERILATOR) $(VFLAGS) -Ivsrc --top-module top $(VSRCS) $(CSRCS)
	./obj_dir/Vtop

clean:
	rm -rf obj_dir wave.fst

