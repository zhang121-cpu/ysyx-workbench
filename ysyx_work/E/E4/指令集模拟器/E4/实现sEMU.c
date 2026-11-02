#include <stdio.h>
#include <stdint.h>

uint8_t PC = 0;
uint8_t R[4];
uint8_t M[16] = {0x8a, 0x90, 0xa0, 0xb1, 0x17, 0x29, 0xd1, 0xdf};

uint8_t rd;
uint8_t rs1;
uint8_t rs2;
uint8_t immediate_value;
uint8_t addr;
uint8_t rs2;


uint8_t execute(uint8_t instruction) {
    uint8_t opcode = instruction >> 6; // 获取高2位

    switch(opcode) {
        case 0x0://ADD
            rd = (instruction >> 4) & 0x03; // 获取目标寄存器索引
            rs1 = (instruction >> 2) & 0x03; // 获取源寄存器rs1索引
            rs2 = (instruction >> 0) & 0x03; // 获取源寄存器rs2索引
            R[rd] = R[rs1] + R[rs2];
            break;
        case 0x1: //非规范
            break;
        case 0x2: //li指令
            rd = (instruction >> 4) & 0x03; // 获取寄存器索引
            immediate_value = (instruction >> 0) & 0x0F; // 获取立即数值
            R[rd] = immediate_value; // 将立即数值加载到寄存器中
            break;
        case 0x3: // bner0指令
            addr = (instruction >> 2) & 0x0F;
            rs2 = (instruction >> 0) & 0x03; // 获取源寄存器索引
            if (R[0] != R[rs2]) {
                PC = addr; // 跳转到指定地址
            }
            break;
        // 可以添加更多的指令类型
        default:
            // 未知指令处理
            break;
    }
    
    if(opcode != 0x3)  // 如果不是跳转指令，PC在主循环中自增
        return 0;
    else
        return 1; // 跳转指令执行后，PC已经被更新，不需要在主循环中自增
}

void inst_cycle() {
    uint8_t instruction = M[PC];
    if(execute(instruction) == 0) // 如果不是跳转指令，PC自增
        PC++; 
}     

int main(int argc, char *argv[]) {
    int i = 90;
    while(i--){inst_cycle();};
    printf("Final sum: %d\n", R[2]);
    return 0;
} 