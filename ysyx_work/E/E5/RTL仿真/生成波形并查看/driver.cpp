#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"    // 如果使用 FST 格式
// #include "verilated_vcd_c.h" // 如果使用 VCD 格式

#define MAX_SIM_CYCLES 100

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vtop* top = new Vtop{contextp};

    contextp->traceEverOn(true);              // 启用跟踪

    // 创建波形文件对象
    VerilatedFstC* tfp = new VerilatedFstC;   // FST 格式
    // VerilatedVcdC* tfp = new VerilatedVcdC; // VCD 格式

    // 将 top 模块的信号写入波形，跟踪深度为 99
    top->trace(tfp, 99);
    tfp->open("wave.fst");                    // 生成 wave.fst

    for (int i = 0; i < MAX_SIM_CYCLES && !contextp->gotFinish(); i++) {
        int a = rand() & 1;
        int b = rand() & 1;
        top->a = a;
        top->b = b;
        top->eval();

        // 在每个时间步后 dump 波形
        tfp->dump(contextp->time());          // 写入当前时间点的波形
        contextp->timeInc(1);                 // 时间递增

        printf("a = %d, b = %d, f = %d\n", a, b, top->f);
        assert(top->f == (a ^ b));
    }

    tfp->close();
    delete tfp;
    delete top;
    delete contextp;
    return 0;
}