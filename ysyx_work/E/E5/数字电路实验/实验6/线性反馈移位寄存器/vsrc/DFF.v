// 使用触发器模板的示例
module DFF(
  input clk,
  input rst,
  input  in,
  output  out
);
  Reg #(1, 1'b1) i0 (clk, rst, in, out, 1'b1);
endmodule
