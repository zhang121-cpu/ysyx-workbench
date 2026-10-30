// ============================================
// NPC - RISC-V 指令编码宏定义
// ============================================

`ifndef __NPC_INCLUDE_V__
`define __NPC_INCLUDE_V__

// -------- opcode --------
`define OP_R_TYPE    7'b0110011   // add, sub, and, or, sll, slt, mul, div...
`define OP_I_ALU     7'b0010011   // addi, andi, ori, slli, srai...
`define OP_I_LOAD    7'b0000011   // lb, lh, lw, lbu, lhu
`define OP_I_JALR    7'b1100111   // jalr
`define OP_S_TYPE    7'b0100011   // sb, sh, sw
`define OP_B_TYPE    7'b1100011   // beq, bne, blt, bge, bltu, bgeu
`define OP_U_LUI     7'b0110111   // lui
`define OP_U_AUIPC   7'b0010111   // auipc
`define OP_J_JAL     7'b1101111   // jal

// -------- funct3 --------
`define F3_ADDSUB    3'b000       // add/sub/addi/jalr/lb/sb/beq
`define F3_SLL       3'b001       // sll/slli/lh/sh/bne
`define F3_SLT       3'b010       // slt/slti/lw/sw
`define F3_SLTU      3'b011       // sltu/sltiu
`define F3_XOR       3'b100       // xor/xori/lbu
`define F3_SRL_SRA   3'b101       // srl/sra/srli/srai/lhu
`define F3_OR        3'b110       // or/ori
`define F3_AND       3'b111       // and/andi

// -------- funct7 --------
`define F7_ADD_SLL   7'b0000000   // add, sll, slt, sltu, xor, srl, or, and
`define F7_SUB_SRA   7'b0100000   // sub, sra
`define F7_MULDIV    7'b0000001   // mul, mulh, mulhsu, mulhu, div, divu, rem, remu


// ---------alu_op --------（ALU 运算类型编码：IDU 译码生成，EXU 据此执行运算）
`define ALU_ADD  4'b0000    // add / addi：加法；lw/sw/jalr 的地址、跳转目标计算也用加法
`define ALU_SUB  4'b0001    // sub：减法
`define ALU_SLL  4'b0010    // sll / slli：逻辑左移
`define ALU_SLT  4'b0011    // slt / slti：有符号小于比较，结果置 0/1
`define ALU_SLTU 4'b0100    // sltu / sltiu：无符号小于比较，结果置 0/1
`define ALU_XOR  4'b0101    // xor / xori：按位异或
`define ALU_SRL  4'b0110    // srl / srli：逻辑右移
`define ALU_SRA  4'b0111    // sra / srai：算术右移（高位符号扩展）
`define ALU_OR   4'b1000    // or / ori：按位或
`define ALU_AND  4'b1001    // and / andi：按位与
`define ALU_NOP 4'b1111     //ebreak :system 或未实现指令


// -------- wdata_sel --------（写回数据来源选择）
`define WB_ALU  2'b00    // 写回 ALU 结果（R/I 型运算）
`define WB_MEM  2'b01    // 写回访存数据（lw/lbu）
`define WB_PC4  2'b10    // 写回 pc+4（jalr）
`define WB_IMM  2'b11    // 写回立即数（lui）


// ----- system-opcode --------
`define OP_SYSTEM_EBREAK   32'h00100073   //ebreak


`endif  // __NPC_INCLUDE_V__
