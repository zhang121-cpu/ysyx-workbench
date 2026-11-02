#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Vtop.h"
#include "verilated.h"
#include <verilated_fst_c.h>    // 如果使用 FST 格式

#define PMEM_SIZE 65536*4
#define MAX_SIM_CYCLES 100

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

static uint8_t pmem[PMEM_SIZE] = {0};                                                  

static uint32_t pmem_read(uint32_t addr, int len) {
    if (addr >= sizeof(pmem)) {
        printf("pmem_read: addr out of range: 0x%x\n", addr);
        exit(-1);
    }
    u_int32_t data = 0;
    for (int i = 0; i < len; i++) {
        data |= pmem[addr + i] << (i * 8);                               //每个数组元素中只存储一个字节的数据，低位在前，高位在后
    }
    return data;
}

static void pmem_write(uint32_t addr, uint32_t data, int len) {
    if (addr >= sizeof(pmem)) {
        printf("pmem_write: addr out of range: 0x%x\n", addr);
        exit(-1);
    }
    for (int i = 0; i < len; i++) {
        pmem[addr + i] = (data >> (i * 8)) & 0xff;               //每个数组元素中只存储一个字节的数据，低位在前，高位在后
    }
}

static void single_cycle() {
    top->clk = 0; 
    top->eval();

    //硬件上gpr与mem写入是在下一周期的开始
    if (top->m_wen) {                          // 写操作
    int len = (top->m_size == 0) ? 1 :     // sb
                (top->m_size == 1) ? 2 :     // sh
                4;                          // sw
    pmem_write(top->m_addr, top->m_wdata, len);
    }

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

    //load_program
    static const uint8_t program[] = {
        // _start:
        0x13, 0x05, 0x40, 0x01,  // 0x01400513  addi a0, zero, 20
        0xe7, 0x00, 0x00, 0x01,  // 0x010000e7  jalr ra, 16(zero)
        0xe7, 0x00, 0xc0, 0x00,  // 0x00c000e7  jalr ra, 12(zero)
        // halt:
        0x73, 0x00, 0x10, 0x00,  // 0x00100073  ebreak
        // fun:
        0x13, 0x05, 0xa5, 0x00,  // 0x00a50513  addi a0, a0, 10
        0x67, 0x80, 0x08, 0x00,  // 0x00008067  jalr zero, 0(ra)
    };
    memcpy(pmem, program, sizeof(program));   // 需要 #include <cstring>

    for (int i = 0; i < MAX_SIM_CYCLES && !contextp->gotFinish(); i++){
        // 取指阶段
        top->instruction = pmem_read(top->pc_state, 4);             //pc每次从内存中读取4个字节的指令
        top->eval();

        // 数据读取（LSU 需要）
        if (top->m_ren) {                          // 读操作
            int len = (top->m_size == 0) ? 1 :     // lb
                      (top->m_size == 1) ? 2 :     // lh
                      4;                          // lw
            top->m_rdata = pmem_read(top->m_addr, len);
            top->eval();  // 更新 m_rdata 后重新求值
        }

        record();
        single_cycle();
    }

    fileend();
    return 0;
}
