// 32路选8路多路选择器
module mux328(a7, a6, a5, a4, a3, a2, a1, a0, s, y);
    input [3:0] a7, a6, a5, a4, a3, a2, a1, a0;
    input [1:0] s;
    output [7:0] y;

    mux41 i7 (a7, s, y[7]);
    mux41 i6 (a6, s, y[6]);
    mux41 i5 (a5, s, y[5]);
    mux41 i4 (a4, s, y[4]);
    mux41 i3 (a3, s, y[3]);
    mux41 i2 (a2, s, y[2]);
    mux41 i1 (a1, s, y[1]);
    mux41 i0 (a0, s, y[0]);
endmodule
