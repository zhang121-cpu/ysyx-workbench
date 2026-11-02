module top (
  input [7:0] din,
  input [2:0] shamt,
  input LR,
  input AL,
  output [7:0] dout
);

  wire [7:0] tem1, tem2;
  wire ALtem;

  mux21 mux21_1(1'b0, din[7], AL, ALtem);

  mux328 i2 (
    {din[6], din[7], ALtem, din[7]},
    {din[5], din[6], din[7], din[6]},
    {din[4], din[5], din[6], din[5]},
    {din[3], din[4], din[5], din[4]},
    {din[2], din[3], din[4], din[3]},
    {din[1], din[2], din[3], din[2]},
    {din[0], din[1], din[2], din[1]},
    {1'b0, din[0], din[1], din[0]},
    {LR,shamt[0]}, tem1
    );
    mux328 i1 (
    {tem1[5], tem1[7], ALtem, tem1[7]},
    {tem1[4], tem1[6], ALtem, tem1[6]},
    {tem1[3], tem1[5], tem1[7], tem1[5]},
    {tem1[2], tem1[4], tem1[6], tem1[4]},
    {tem1[1], tem1[3], tem1[5], tem1[3]},
    {tem1[0], tem1[2], tem1[4], tem1[2]},
    {1'b0, tem1[1], tem1[3], tem1[1]},
    {1'b0, tem1[0], tem1[2], tem1[0]},
    {LR,shamt[1]}, tem2
    );
    mux328 i0 (
    {tem2[3], tem2[7], ALtem, tem2[7]},
    {tem2[2], tem2[6], ALtem, tem2[6]},
    {tem2[1], tem2[5], ALtem, tem2[5]},
    {tem2[0], tem2[4], ALtem, tem2[4]},
    {1'b0, tem2[3], tem2[7], tem2[3]},
    {1'b0, tem2[2], tem2[6], tem2[2]},
    {1'b0, tem2[1], tem2[5], tem2[1]},
    {1'b0, tem2[0], tem2[4], tem2[0]},
    {LR,shamt[2]}, dout
    );


endmodule

