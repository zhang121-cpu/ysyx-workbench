module Reg_32b(
    input clk,
    input rst,
    input [31:0] in,
    output [31:0] out,
    input wen
);

    Reg #(32, 32'h00000000) i0 (clk, rst, in, out, wen);

endmodule
