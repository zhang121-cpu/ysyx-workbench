#include <nvboard.h>
#include <Vtop.h>

static TOP_NAME dut;

void nvboard_bind_all_pins(TOP_NAME* top);

static void single_cycle() {
    dut.clk = 0; 
    dut.eval();
    dut.clk = 1; 
    dut.eval();
}

static void reset(int n) {
    dut.rst = 1;
    while (n -- > 0) single_cycle();
    dut.rst = 0;
}

int main() {
    nvboard_bind_all_pins(&dut);
    nvboard_init();

    reset(10);

    while(1) {
        for (int i = 0; i < 1000000000; i++) {
            // do nothing, just waste some time
        }
        nvboard_update();
        single_cycle();
    }
}
