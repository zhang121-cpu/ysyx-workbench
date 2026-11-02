//IFU(Instruction Fetch Unit): 负责存储PC
`include "include.v"

module IFU (
    input clk,
    input rst,
    input jump_en,
    input [31:0] pc_dnextstate,
    output [31:0] pc_state
);

    wire [31:0] pc_nextstate;

    assign pc_nextstate = jump_en ? (pc_dnextstate & ~32'h00000001) : pc_state + 4;
    Reg_noen_32b pc_reg (clk, rst, pc_nextstate, pc_state);

endmodule
