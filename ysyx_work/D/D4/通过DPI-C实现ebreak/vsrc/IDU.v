//负责对当前指令进行译码, 准备执行阶段需要使用的数据和控制信号
`include "include.v"

module IDU(
    input [31:0] instruction,
    output [6:0] opcode,
    output [4:0] rd,
    output [4:0] rs1,
    output [24:20] rs2,
    output [2:0] funct3,
    output [6:0]funct7,
    output reg [31:0] imm,
    output ebreak_en
);

    assign opcode = instruction[6:0];
    assign rd = instruction[11:7];
    assign funct3 = instruction[14:12];
    assign rs1 = instruction[19:15];
    assign rs2 = instruction[24:20];
    assign funct7 = instruction[31:25];

    assign  ebreak_en = (instruction == `OP_SYSTEM_EBREAK);

    wire [31:0] imm_I, imm_S, imm_B, imm_U, imm_J;

    assign imm_I = {{20{instruction[31]}}, instruction[31:20]};
    assign imm_S = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
    assign imm_B = {{20{instruction[31]}}, instruction[7], instruction[30:25], instruction[11:8], 1'b0};
    assign imm_U = {instruction[31:12], 12'h0000};
    assign imm_J = {{12{instruction[31]}}, instruction[19:12], instruction[20], instruction[30:21], 1'b0};

    always @(*) begin
        case (opcode)
            //RV32IM
            `OP_R_TYPE:          imm = 32'b0;      // R-type：无立即数（ALU 寄存器运算：add, sub, and, or, sll, slt, mul, div...）
            `OP_I_ALU:            imm = imm_I;     // I-type：算术/逻辑立即数（addi, andi, ori, slli, srai ...）
            `OP_I_LOAD:          imm = imm_I;     // I-type：访存加载（lb, lh, lw, lbu, lhu ...）
            `OP_I_JALR:          imm = imm_I;    // I-type：跳转寄存器（jalr）
            `OP_S_TYPE:          imm = imm_S;     // S-type：访存存储（sb, sh, sw）
            `OP_B_TYPE:          imm = imm_B;     // B-type：条件分支（beq, bne, blt, bge, bltu, bgeu）
            `OP_U_LUI:            imm = imm_U;     // U-type：高位立即数（lui）
            `OP_U_AUIPC:       imm = imm_U;     // U-type：PC 相对高位立即数（auipc）
            `OP_J_JAL:            imm = imm_J;     // J-type：跳转链接（jal）
            default:              imm = 32'b0;
        endcase
    end

endmodule
