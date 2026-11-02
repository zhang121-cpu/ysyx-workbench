#include <stdio.h>
#include <stdint.h>
#include <am.h>
#include <klib-macros.h>

#define MEM_SIZE 300000
#define SHAPE_SIZE 256
#define EXECUTE_CYCLES 800000

uint32_t PC = 0;
uint32_t R[16] = {0};// x0始终为0
uint32_t M[MEM_SIZE] = {0};
uint32_t S[SHAPE_SIZE][SHAPE_SIZE] = {0};

uint32_t rd;
uint32_t rs1;
uint32_t rs2;
uint32_t immediate;
uint32_t offset;

// 这里可以添加代码来加载程序到内存中
void load_program() {
    FILE *file = fopen("vga.bin","rb");

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    fread(M, sizeof(uint32_t), file_size/sizeof(uint32_t), file);
    fclose(file);
}

// 符号拓展函数：将 width 位的立即数符号拓展到 32 位
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
    uint32_t opcode3 = (instruction >> 25  ) & 0x7f; // 获取第31-19位

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
        
        case 0b0110011:
            switch (opcode2){
                case 0b000:
                    switch (opcode3){
                        case 0b0000000://add
                            rd = (instruction >> 7) & 0x1f; // 获取目标寄存器索引
                            rs1 = (instruction >> 15) & 0x1f; // 获取源寄存器rs1索引
                            rs2 = (instruction >> 20) & 0x1f; // 获取源寄存器rs2索引
                            R[rd] = R[rs1] + R[rs2];
                            return 0;

                        default:
                            return 0;
                    }
                default:
                    return 0;
            }

        case 0b0110111://lui
                rd = (instruction >> 7) & 0x1f; // 获取目标寄存器索引
                immediate = (instruction >> 12) & 0xfffff; // 获取立即数值
                R[rd] = immediate << 12; // 将立即数值左移12位并存入目标寄存器
                return 0;

        case 0b0000011:
            switch (opcode2){
                case 0b010:// lw
                    rd = (instruction >> 7) & 0x1f; // 获取目标寄存器索引
                    rs1 = (instruction >> 15) & 0x1f; // 获取源寄存器rs1索引
                    offset = (instruction >> 20) & 0xfff; // 获取偏移量
                    R[rd] = M[(R[rs1] + sign_extend(offset, 12)) >> 2]; // 从内存中加载数据到目标寄存器
                    return 0;

                case 0b100:// lbu
                    rd = (instruction >> 7) & 0x1f; // 获取目标寄存器索引
                    rs1 = (instruction >> 15) & 0x1f; // 获取源寄存器rs1索引
                    offset = (instruction >> 20) & 0xfff; // 获取偏移量
                    uint32_t byte_offset = (R[rs1] + sign_extend(offset, 12)) & 0x3; // 计算字节偏移
                    R[rd] = (M[(R[rs1] + sign_extend(offset, 12)) >> 2] >> (byte_offset * 8)) & 0xff; // 从内存中加载数据到目标寄存器，并进行零扩展
                    return 0;

                default:
                    return 0;
            }

        case 0b0100011:
            switch (opcode2){
                case 0b010:// sw
                    rs1 = (instruction >> 15) & 0x1f; // 获取源寄存器rs1索引
                    rs2 = (instruction >> 20) & 0x1f; // 获取源寄存器rs2索引
                    offset =  (((instruction >> 25) & 0x7f) << 5) | ((instruction >> 7) & 0x1f); // 获取偏移量
                    if ((R[rs1] + sign_extend(offset, 12)) >= 0x20000000 && (R[rs1] + sign_extend(offset, 12)) <= 0x20040000) {
                        ((uint32_t *)S)[((R[rs1] + sign_extend(offset, 12)) - 0x20000000) >> 2] = R[rs2]; // 如果地址在形状缓冲区范围内，将数据存入形状缓冲区
                    }
                    else
                        M[(R[rs1] + sign_extend(offset, 12)) >> 2] = R[rs2]; // 否则将数据从源寄存器存入内存
                    return 0;

                case 0b000:// sb
                    rs1 = (instruction >> 15) & 0x1f; // 获取源寄存器rs1索引
                    rs2 = (instruction >> 20) & 0x1f; // 获取源寄存器rs2索引
                    offset =  (((instruction >> 25) & 0x7f) << 5) | ((instruction >> 7) & 0x1f); // 获取偏移量
                    uint32_t byte_offset = (R[rs1] + sign_extend(offset, 12)) & 0x3; // 计算字节偏移
                    if ((R[rs1] + sign_extend(offset, 12)) >= 0x20000000 && (R[rs1] + sign_extend(offset, 12)) <= 0x20040000) {
                        ((uint32_t *)S)[((R[rs1] + sign_extend(offset, 12)) - 0x20000000) >> 2] = ( ((uint32_t *)S)[((R[rs1] + sign_extend(offset, 12)) - 0x20000000) >> 2] & ~(uint32_t)(0xff << (byte_offset * 8))) | ((R[rs2] & 0xff) << (byte_offset * 8)); // 如果地址在形状缓冲区范围内，将数据存入形状缓冲区
                    }
                    else
                        M[(R[rs1] + sign_extend(offset, 12)) >> 2] = (M[(R[rs1] + sign_extend(offset, 12)) >> 2] & ~(uint32_t)(0xff << (byte_offset * 8))) | ((R[rs2] & 0xff) << (byte_offset * 8)); // 否则将数据从源寄存器存入内存的对应字节
                    return 0;

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

void draw() {                                      // 将 S 绘制到屏幕
    int color_buf[20*20];                  // 单色填充缓冲区
    int w = io_read(AM_GPU_CONFIG).width / SHAPE_SIZE;
    int h = io_read(AM_GPU_CONFIG).height / SHAPE_SIZE;
    int block_size = w * h;

    int x, y, k;                                              //y为行号，x为列号
    for (y = 0; y < SHAPE_SIZE; y ++) {
        for (x = 0; x < SHAPE_SIZE; x ++) {
            for (k = 0; k < block_size; k ++) {
                color_buf[k] = S[y][x];
            }
            io_write(AM_GPU_FBDRAW, x * w, y * h, color_buf, w, h, false); // 画一个格子
        }
    }
    io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);  // 刷新屏幕
}


int main(int argc, char *argv[]) {
    int i = EXECUTE_CYCLES;//指令执行次数
    load_program();
    while(i--){inst_cycle();};
    ioe_init(); // initialization for GUI 
    draw();  
    while(1);
    return 0;
} 