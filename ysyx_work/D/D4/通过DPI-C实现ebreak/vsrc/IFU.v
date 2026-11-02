//IFU(Instruction Fetch Unit): 负责根据当前PC从存储器中取出一条指令
//这里取指问题在C++上处理了，这里只处理pc寄存器问题
//为了流水线问题，这里将更新PC也放在这里处理了
`include "include.v"

module IFU (
    input clk,
    input rst,
    input jump_en,
    input [31:0] pc_dnextstate,
    output [31:0] pc_state
);

    wire [31:0] pc_nextstate;

    assign pc_nextstate = jump_en ? pc_dnextstate: pc_state + 4; 
    Reg_noen_32b pc_reg (clk, rst, pc_nextstate, pc_state);

endmodule
