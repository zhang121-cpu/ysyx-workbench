#include <stdio.h>
#include <stdint.h>

uint32_t PC = 0;
uint32_t R[16] = {0};// x0始终为0
uint32_t M[] = {0x01400513, 0x010000e7, 0x00c000e7, 0x00c00067, 0x00a50513, 0x00008067};

uint32_t rd;
uint32_t rs1;
uint32_t immediate;
uint32_t offset;

// 符号拓展函数：将 width 位的立即数符号拓展到 32 位
uint32_t sign_extend(uint32_t value, int width) {
    uint32_t sign_bit = (value >> (width - 1)) & 1;
    if (sign_bit) {
        value |= (~(uint32_t)0) << width; // 高位全补1
    }
    return value;
}

uint32_t execute(uint32_t instruction) {
    uint32_t opcode1 = (instruction >> 0) & 0x7f; // 获取第6-0位
    uint32_t opcode2 = (instruction >> 12) & 0x07; // 获取第14-12位

    switch(opcode1) {
        case 0b0010011:
            switch(opcode2) {
                case 0b000: // addi
                    rd = (instruction >> 7) & 0x1f; // 获取目标寄存器索引
                    rs1 = (instruction >> 15) & 0x1f; // 获取源寄存器rs1索引
                    immediate = (instruction >> 20) & 0xfff; // 获取立即数值
                    R[rd] = R[rs1] + sign_extend(immediate, 12);
                    return 0;

                default:
                    return 0;
            }

        case 0b1100111: 
            switch (opcode2){
                case 0b000: // jalr
                    rd = (instruction >> 7) & 0x1f; // 获取目标寄存器索引
                    rs1 = (instruction >> 15) & 0x1f; // 获取源寄存器rs1索引
                    offset = (instruction >> 20) & 0xfff; // 获取偏移量
                    int temp = PC + 4; // 保存当前PC值
                    PC = (R[rs1] + sign_extend(offset, 12)) & 0xfffffffe; // 跳转到指定地址
                    R[rd] = temp; // 将返回地址保存到目标寄存器中
                    return 1;
        
                default:
                    return 0;
            }

        default:
            // 未知指令处理
            return 0;
    }
    
}

void inst_cycle() {
    uint32_t instruction = M[PC >> 2]; // 从内存中获取指令
    if(execute(instruction) == 0) // 如果不是跳转指令，PC自增
        PC = PC + 4; 
    R[0] = 0;// x0寄存器始终为0
}     

int main(int argc, char *argv[]) {
    int i = 120;
    while(i--){inst_cycle();};
    printf("PC =  %d\n", PC);
    return 0;
} 