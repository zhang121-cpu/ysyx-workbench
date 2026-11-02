module Reg_noen_4b(
    input clk,
    input rst,
    input [3:0] in,
    output [3:0] out
);

    Reg #(4, 4'b0000) i0 (clk, rst, in, out, 1'b1);

endmodule
