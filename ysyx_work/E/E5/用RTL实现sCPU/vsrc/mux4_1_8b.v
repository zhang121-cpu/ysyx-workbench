module mux4_1_8b(a,s,y);
    input [31:0] a;         
    input [1:0] s;
    output [7:0] y;

    MuxKey #(4, 2, 8) i0 (y, s, {
    2'b00, a[7:0],
    2'b01, a[15:8],
    2'b10, a[23:16],
    2'b11, a[31:24]
    });
endmodule
