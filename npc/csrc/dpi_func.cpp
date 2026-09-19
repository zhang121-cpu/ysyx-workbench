#include "Vtop__Dpi.h"
#include <verilated.h>
#include <stdio.h>
#include <stdint.h>

#include "mem.h"  
#include "timer.h"

#define CONFIG_MBASE 0x80000000u

#define DEVICE_BASE 0x10000000

#define SERIAL_PORT (DEVICE_BASE + 0x00000000)
#define RTC_ADDR    (DEVICE_BASE + 0x00000004)

extern VerilatedContext* contextp;

static bool out_pmem(uint32_t addr) {
    return addr < CONFIG_MBASE || addr >= CONFIG_MBASE + PMEM_SIZE;
}

static uint64_t rtc_latch = 0;       //用于时间快照

extern "C" uint32_t pmem_read(uint32_t addr, int len) {
    if (addr == RTC_ADDR + 4) {
        rtc_latch = uptime_us();
        return (uint32_t)(rtc_latch >> 32);
    }
    if (addr == RTC_ADDR) {
        return (uint32_t)rtc_latch;          // 低 32 位：同一快照
    }
    
    if (out_pmem(addr)) {
        printf("pmem_read: addr out of range: 0x%08x\n", addr);
        contextp->gotFinish(true);                                             // 通知 main 循环结束，走正常 fileend() 收尾
        return 0;
    } else {
        uint32_t off = addr - CONFIG_MBASE;
        u_int32_t data = 0;
        for (int i = 0; i < len; i++) {
            data |= pmem[off + i] << (i * 8);                               //每个数组元素中只存储一个字节的数据，低位在前，高位在后
        }
        return data;
    }
}

extern "C" void pmem_write(uint32_t addr, uint32_t data, int len) {
    if (addr == SERIAL_PORT) {  // 如果地址是串口输出地址
        putchar(data);
        return;
    }
    
    if (out_pmem(addr)) {
        printf("pmem_write: addr out of range: 0x%08x\n", addr);
        contextp->gotFinish(true);                                           // 通知 main 循环结束，走正常 fileend() 收尾
    } else {
        uint32_t off = addr - CONFIG_MBASE;
        for (int i = 0; i < len; i++) {
            pmem[off + i] = (data >> (i * 8)) & 0xff;               //每个数组元素中只存储一个字节的数据，低位在前，高位在后
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
        printf("\033[1;32mHIT GOOD TRAP.\033[0m\n");   // 加粗绿色
    else 
        printf("\033[1;31mHIT BAD TRAP\033[0m\n");     // 加粗红色
    contextp->gotFinish(true);   // 通知 main 循环结束，走正常 fileend() 收尾
}
