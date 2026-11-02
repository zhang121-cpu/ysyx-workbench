#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"

VerilatedContext* contextp = NULL;
VerilatedFstC* tfp = NULL;

static Vtop* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedFstC;
  top = new Vtop;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("wave.fst");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
  delete tfp;
  delete top;
  delete contextp;
}

int main() {
  sim_init();

  top->en=0b0; top->x =0b00000000; step_and_dump_wave();
               top->x =0b00000001; step_and_dump_wave();
               top->x =0b00000010; step_and_dump_wave();
               top->x =0b00000100; step_and_dump_wave();
               top->x =0b00001000; step_and_dump_wave();
               top->x =0b00010000; step_and_dump_wave();
               top->x =0b00100000; step_and_dump_wave();
               top->x =0b01000000; step_and_dump_wave();
               top->x =0b10000000; step_and_dump_wave();
  top->en=0b1; top->x =0b00000000; step_and_dump_wave();
               top->x =0b00000001; step_and_dump_wave();
               top->x =0b00000010; step_and_dump_wave();
               top->x =0b00000100; step_and_dump_wave();
               top->x =0b00001000; step_and_dump_wave();
               top->x =0b00010000; step_and_dump_wave();
               top->x =0b00100000; step_and_dump_wave();
               top->x =0b01000000; step_and_dump_wave();
               top->x =0b10000000; step_and_dump_wave();
 
  sim_exit();
  return 0;
}