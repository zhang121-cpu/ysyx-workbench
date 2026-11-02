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


// ----- system-opcode --------
`define OP_SYSTEM_EBREAK   32'h00100073   //ebreak


`endif  // __NPC_INCLUDE_V__
