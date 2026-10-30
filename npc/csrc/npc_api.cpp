// eval会先计算是否当前的 ico 全组合链，
//接着如果检测到上升沿，计算当前的 nba 全组合链
//这种方式在verilog可以保证在一个时钟周期内，所有的组合逻辑都被计算到
//但使用DPI-C的情况下，会导致函数的多次触发
// 所以 mtrace 的 READ 记录用 npc_in_clk0_eval() 做相位门控。
#include "npc_api.h"
#include "Vtop.h"
#include <verilated.h>
#include <verilated_fst_c.h>

extern VerilatedContext *contextp;
extern Vtop *top;
extern VerilatedFstC *tfp;

static bool in_clk0_eval = false;

bool npc_in_clk0_eval(void) {
    return in_clk0_eval;
}

void npc_single_cycle(void) {
    in_clk0_eval = true; top->clk = 0; top->eval();
    in_clk0_eval = false; top->clk = 1; top->eval();
}

#ifdef CONFIG_WAVE_RECORD
void npc_wave_record(void) {
    tfp->dump(contextp->time());
    contextp->timeInc(1);
}
#endif

void npc_reset(int n) {
    top->rst = 1;
    for (int i = 0; i < n; i++) npc_single_cycle();
    top->rst = 0;
}
