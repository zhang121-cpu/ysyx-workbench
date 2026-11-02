#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t PC = 0;
uint8_t R[4];
uint8_t M[16] = {0x90, 0xa0, 0xb1, 0x17, 0x29, 0xcd, 0x60, 0xdf};

uint8_t rd;
uint8_t rs1;
uint8_t rs2;
uint8_t immediate_value;
uint8_t addr;

uint8_t execute(uint8_t instruction) {
    uint8_t opcode = instruction >> 6; // 获取高2位

    switch(opcode) {
        case 0x0://ADD
            rd = (instruction >> 4) & 0x03; // 获取目标寄存器索引
            rs1 = (instruction >> 2) & 0x03; // 获取源寄存器rs1索引
            rs2 = (instruction >> 0) & 0x03; // 获取源寄存器rs2索引
            R[rd] = R[rs1] + R[rs2];
            return 0;
        case 0x1: //out指令  指令格式：opcode(2位) | rs2(2位) | xx(2位) | xx(2位)
            rs2 = (instruction >> 4) & 0x03; // 获取源寄存器索引
            printf("%d\n", R[rs2]); // 输出寄存器的值
            return 0;
        case 0x2: //li指令
            rd = (instruction >> 4) & 0x03; // 获取寄存器索引
            immediate_value = (instruction >> 0) & 0x0F; // 获取立即数值
            R[rd] = immediate_value; // 将立即数值加载到寄存器中
            return 0;
        case 0x3: // bner0指令
            addr = (instruction >> 2) & 0x0F;
            rs2 = (instruction >> 0) & 0x03; // 获取源寄存器索引
            if (R[0] != R[rs2]) {
                PC = addr; // 跳转到指定地址
                return 1;
            }
            return 0;
        default:
            // 未知指令处理
            return 0;
    }
    
}

void inst_cycle() {
    uint8_t instruction = M[PC];
    if(execute(instruction) == 0) // 如果不是跳转指令，PC自增
        PC++; 
}     

int main(int argc, char *argv[]) {
    R[0] = atoi(argv[1]); // 初始化寄存器
    while(1){inst_cycle();};
    return 0;
} 