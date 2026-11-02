#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"    // 如果使用 FST 格式
// #include "verilated_vcd_c.h" // 如果使用 VCD 格式

#define MAX_SIM_CYCLES 20

VerilatedContext* contextp = NULL;
VerilatedFstC* tfp = NULL;

static Vtop* top;

void sim_init(int argc, char** argv){
    contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    top = new Vtop{contextp};
    tfp = new VerilatedFstC;  
    contextp->traceEverOn(true);
    top->trace(tfp, 10);
    tfp->open("wave.fst");
}

void sim_exit(){
    tfp->close();
    delete tfp;
    delete top;
    delete contextp;
}

static void single_cycle() {
    //top->clk = 0; 
    //top->eval();
    //tfp->dump(contextp->time());
    //contextp->timeInc(1); 

    //top->clk = 1; 
    top->eval();
    tfp->dump(contextp->time());          
    contextp->timeInc(1);                
}

static void reset(int n) {
    //top->rst = 1;
    while (n -- > 0) single_cycle();
    //top->rst = 0;
}

int main(int argc, char** argv) {

    sim_init(argc, argv);

    reset(5);

    for (int i = 0; i < MAX_SIM_CYCLES && !contextp->gotFinish(); i++) {
        int din = rand() % 256;
        int shamt  = rand() % 8;
        int LR  = rand() & 1;
        int AL  = rand() & 1;
        top->din = din;
        top->shamt = shamt;
        top->LR = LR;
        top->AL = AL;
        single_cycle();

        unsigned dout = (unsigned)top->dout;
        printf("din = ");
        for (int b = 7; b >= 0; --b) putchar(((din  >> b) & 1) ? '1' : '0');
        printf(", shamt = %d, LR = %d, AL = %d, dout = ", shamt, LR, AL);
        for (int b = 7; b >= 0; --b) putchar(((dout >> b) & 1) ? '1' : '0');
        printf("\n");
    }

    sim_exit();
    return 0;
}

