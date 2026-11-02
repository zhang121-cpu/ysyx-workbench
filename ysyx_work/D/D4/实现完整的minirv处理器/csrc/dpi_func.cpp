#include "Vtop__Dpi.h"
#include <verilated.h>
#include <stdio.h>
#include <stdint.h>

#include "mem.h"  

extern VerilatedContext* contextp;

extern "C" uint32_t pmem_read(uint32_t addr, int len) {
    if (addr >= sizeof(pmem)) {
        printf("pmem_read: addr out of range: 0x%x\n", addr);
        contextp->gotFinish(true);                                             // 通知 main 循环结束，走正常 fileend() 收尾
        return 0;
    } else {
        u_int32_t data = 0;
        for (int i = 0; i < len; i++) {
            data |= pmem[addr + i] << (i * 8);                               //每个数组元素中只存储一个字节的数据，低位在前，高位在后
        }
        return data;
    }
}

extern "C" void pmem_write(uint32_t addr, uint32_t data, int len) {
    if (addr >= sizeof(pmem)) {
        printf("pmem_write: addr out of range: 0x%x\n", addr);
        contextp->gotFinish(true);                                           // 通知 main 循环结束，走正常 fileend() 收尾
    } else {
        for (int i = 0; i < len; i++) {
            pmem[addr + i] = (data >> (i * 8)) & 0xff;               //每个数组元素中只存储一个字节的数据，低位在前，高位在后
        }
    }
}

extern "C" void pmem_rst() {
    for (int i = 0; i < PMEM_SIZE; i++) {
        pmem[i] = 0;
    }
}

extern "C" void ebreak_handler(uint32_t a0) {
    printf("ebreak: simulation finished.\n");
    if (a0 == 0)                                 // 如果a0寄存器的值为0，表示程序正常结束
        printf("HIT GOOD TRAP.\n");
    else 
        printf("HIT BAD TRAP\n");
    contextp->gotFinish(true);   // 通知 main 循环结束，走正常 fileend() 收尾
}
