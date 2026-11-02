#include "Vtop__Dpi.h"
#include <verilated.h>
#include <stdio.h>

extern VerilatedContext* contextp;

extern "C" void ebreak_handler() {
    printf("ebreak: simulation finished.\n");
    contextp->gotFinish(true);   // 通知 main 循环结束，走正常 fileend() 收尾
}
