module Reg_2b(
    input clk,
    input rst,
    input [1:0] in,
    output [1:0] out
);

    Reg #(2, 2'b00) i0 (clk, rst, in, out, 1'b1);

endmodule
