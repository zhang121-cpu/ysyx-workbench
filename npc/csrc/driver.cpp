#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "Vtop.h"
#include <verilated.h>
#include <verilated_fst_c.h>    // 如果使用 FST 格式

#include "mem.h"

#define MAX_SIM_CYCLES 5000000

//设置3全局变量以供使用(nullptr在C++中类似NULL在C中，表示空指针)
VerilatedContext* contextp = nullptr;
Vtop* top = nullptr;                                      
VerilatedFstC* tfp = nullptr;                 // 波形文件对象

//波形文件的创立
static void filestart(int argc, char** argv){
    contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    top = new Vtop{contextp};

    contextp->traceEverOn(true);              // 启用跟踪

    // 创建波形文件对象
    tfp = new VerilatedFstC;   // FST 格式

    // 将 top 模块的信号写入波形，跟踪深度为 99（跟踪深度：从顶层模块开始向下追踪多少层子模块的信号）
    top->trace(tfp, 99);
    tfp->open("wave.fst");                    // 生成 wave.fst
}

//波形文件的结束
static void fileend() {
    tfp->close();
    delete tfp;
    delete top;
    delete contextp;
}

// 记录信号值到波形文件
static void record() {
    tfp->dump(contextp->time());          // 写入当前时间点的波形
    contextp->timeInc(1);                 // 时间递增
}

uint8_t pmem[PMEM_SIZE] = {0};

// 这里可以添加代码来加载程序到内存中
static void load_program(int argc, char** argv) {
    const char *img = (argc > 1) ? argv[1] : "resource/mem改.bin";
    FILE *file = fopen(img,"rb");

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    //确定MEM空间足够
    if (file_size > PMEM_SIZE) {
        printf("镜像过大: %ld 字节 > PMEM_SIZE\n", file_size);
        exit(1);
    }

    //将文件内容放入数组中
    size_t nread = fread(pmem, 1, file_size, file);
    if (nread != (size_t)file_size) {
        printf("镜像读取不完整: 期望 %ld 字节, 实际读到 %zu 字节\n", file_size, nread);
        exit(1);
    }

    fclose(file);
}

static void single_cycle() {
    top->clk = 0; 
    top->eval();
    top->clk = 1; 
    top->eval();
}

static void reset(int n) {
    top->rst = 1;
    while (n -- > 0) single_cycle();
    top->rst = 0;
}

int main(int argc, char** argv) {
    filestart(argc, argv);

    // 开始复位
    reset(10);
    load_program(argc, argv);
    record();

    int i = 0;
    for (i = 0; i < MAX_SIM_CYCLES && !contextp->gotFinish(); i++){
        single_cycle();
        //record();       记录内容，批量处理是可以注释掉
    }

    fileend();

    if (i == MAX_SIM_CYCLES) {
        printf("\033[1;31mTIMEOUT: simulation did not finish within %d cycles\033[0m\n",
            MAX_SIM_CYCLES);
        return 1;                           // 非 0 → cpu-tests 判 FAIL
    }

    return 0;
}
