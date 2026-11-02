module Reg_8b(
    input clk,
    input rst,
    input [7:0] in,
    output [7:0] out,
    input wen
);

    Reg #(8, 8'h00) i0 (clk, rst, in, out, wen);

endmodule
