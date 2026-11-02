module Shift_Register (
  input in,
  input clk,
  input rst,
  output [7:0] out
);

  DFF d7 (clk, rst, in, out[7]);
  DFF d6 (clk, rst, out[7], out[6]);
  DFF d5 (clk, rst, out[6], out[5]);
  DFF d4 (clk, rst, out[5], out[4]);
  DFF d3 (clk, rst, out[4], out[3]);
  DFF d2 (clk, rst, out[3], out[2]);
  DFF d1 (clk, rst, out[2], out[1]);
  DFF d0 (clk, rst, out[1], out[0]);

endmodule



