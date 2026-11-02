module top (
  input  [7:0] x,
  input  en,
  output reg [2:0]y,
  output y_en,
  output [6:0] y_hex
);
  
  decoder decoder(x, en, y, y_en);
  bcd7seg seg(y, en, y_hex);
  
endmodule


module decoder(  
  input  [7:0] x,
  input  en,
  output reg [2:0]y,
  output y_en
);

  integer i;
  assign y_en = (|x) || en;
  always @(*) begin
    y = 0;
    if (en) begin
      for( i = 0; i <= 7; i = i+1)
          if(x[i] == 1)  y = i[2:0];  //i本质上是寄存器变量
    end
    else  y = 0;
  end
endmodule

module bcd7seg(
  input  [2:0] b,
  input en,
  output reg [6:0] h
);
  
  always @(*) begin
    if (en)
      case(b)
        3'b000: h = 7'b0000001;
        3'b001: h = 7'b1001111;
        3'b010: h = 7'b0010010;
        3'b011: h = 7'b0000110;
        3'b100: h = 7'b1001100;
        3'b101: h = 7'b0100100;
        3'b110: h = 7'b0100000;
        3'b111: h = 7'b0001111; 
        default: h = 7'b0000000; 
      endcase
    else
      h = 7'b0000000; 
  end
endmodule