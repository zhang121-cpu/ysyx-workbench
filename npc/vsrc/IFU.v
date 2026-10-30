//IFU(Instruction Fetch Unit): 负责存储PC
`include "include.v"

module IFU (
    input clk,
    input rst,
    input jump_en,
    input [31:0] pc_dnextstate,    //如果发生跳转，跳转的pc值(与npc中dnpc为确定的下一条pc值不同)
    output [31:0] pc_state,
    output [31:0] pc_nextstate   //下一条pc值
);

    assign pc_nextstate = jump_en ? (pc_dnextstate & ~32'h00000001) : pc_state + 4;
    Reg_noen_32b pc_reg (clk, rst, pc_nextstate, pc_state);

endmodule
