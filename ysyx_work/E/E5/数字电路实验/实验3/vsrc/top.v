module top (
  input  [3:0] A,
  input  [3:0] B,
  input  [2:0] opcode,
  output Carry,
  output Zero,
  output Overflow,
  output [3:0] Result
);

  wire [3:0] result1, result3, result4, result5, result7, result8;
  wire [3:0] data;
  
  ADD_SUB add_sub(A, B, |opcode, Carry, Zero, Overflow, result1);  //主要是Sub_Add在opcode为000时为0,在001,110,111时为1,其中110,111两种在最后算大小与相等时有用
  mux21 mux21_1 (4'b1111, B, opcode[2], data);  //opcode在010时传入111,在101时传入B
  assign result3 = A ^ data;
  assign result4 = A & B;
  assign result5 = A | B;
  assign result7 = {4{result1[3] ^ Overflow}};
  assign result8 = {4{Zero}};
  mux81 mux81_1 (result1, result1, result3, result4, result5, result3, result7, result8, opcode, Result);
endmodule


module ADD_SUB #(n = 4)(  
  input  [n-1:0] A,
  input  [n-1:0] B,
  input  Sub_Add,
  output Carry,
  output Zero,
  output Overflow,
  output [n-1:0] Result
);
  
  wire Cin;
  wire [n-1:0] t_no_Cin;

  assign Cin = Sub_Add;

  assign t_no_Cin = {n{ Cin }}^B;
  assign {Carry,Result} = A + t_no_Cin + Cin;
  assign Overflow = (A[n-1] == t_no_Cin[n-1]) && (Result [n-1] != A[n-1]);
  assign Zero = ~(| Result);

endmodule

// 选择器模板内部实现
module MuxKeyInternal #(NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1, HAS_DEFAULT = 0) (
  output reg [DATA_LEN-1:0] out,
  input [KEY_LEN-1:0] key,
  input [DATA_LEN-1:0] default_out,
  input [NR_KEY*(KEY_LEN + DATA_LEN)-1:0] lut
);

  localparam PAIR_LEN = KEY_LEN + DATA_LEN;
  wire [PAIR_LEN-1:0] pair_list [NR_KEY-1:0];
  wire [KEY_LEN-1:0] key_list [NR_KEY-1:0];
  wire [DATA_LEN-1:0] data_list [NR_KEY-1:0];

  genvar n;
  generate
    for (n = 0; n < NR_KEY; n = n + 1) begin
      assign pair_list[n] = lut[PAIR_LEN*(n+1)-1 : PAIR_LEN*n];
      assign data_list[n] = pair_list[n][DATA_LEN-1:0];
      assign key_list[n]  = pair_list[n][PAIR_LEN-1:DATA_LEN];
    end
  endgenerate

  reg [DATA_LEN-1 : 0] lut_out;
  reg hit;
  integer i;
  always @(*) begin
    lut_out = 0;
    hit = 0;
    for (i = 0; i < NR_KEY; i = i + 1) begin
      lut_out = lut_out | ({DATA_LEN{key == key_list[i]}} & data_list[i]);
      hit = hit | (key == key_list[i]);
    end
    if (!HAS_DEFAULT) out = lut_out;
    else out = (hit ? lut_out : default_out);
  end
endmodule

// 不带默认值的选择器模板
module MuxKey #(NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1) (
  output [DATA_LEN-1:0] out,
  input [KEY_LEN-1:0] key,
  input [NR_KEY*(KEY_LEN + DATA_LEN)-1:0] lut
);
  MuxKeyInternal #(NR_KEY, KEY_LEN, DATA_LEN, 0) i0 (out, key, {DATA_LEN{1'b0}}, lut);
endmodule

module mux21(a,b,s,y);
  input  [3:0] a, b;
  input   s;
  output  [3:0] y;

  MuxKey #(2, 1, 4) i0 (y, s, {
    1'b0, a,
    1'b1, b
  });
endmodule

module mux81(a,b,c,d,e,f,g,h,s,y);
  input  [3:0] a, b;
  input  [3:0] c, d;
  input  [3:0] e, f;
  input  [3:0] g, h;
  input  [2:0] s;
  output  [3:0] y;
  
  MuxKey #(8, 3, 4) i0 (y, s, {
    3'b000, a,
    3'b001, b,
    3'b010, c,
    3'b011, d,
    3'b100, e,
    3'b101, f,
    3'b110, g,
    3'b111, h
  });
endmodule

