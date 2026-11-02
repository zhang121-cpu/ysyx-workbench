module top(clk,rst,ps2_clk,ps2_data,
                    Seven_Segment_Display,overflow);
    input clk,rst,ps2_clk,ps2_data;
    output [6:0] Seven_Segment_Display [7:0];
    output reg overflow;     // fifo overflow
    // internal signal, for test
    
    wire [7:0] data1, data2, asc;
    wire [7:0] count;
    wire ready;
    wire en;

    ps2_keyboard i0 (clk, ~rst, ps2_clk, ps2_data, data1,
                                    ready, 0, overflow);
    FSM i1 (clk, rst, data1, ready, en, data2, count);
    scan2asc i2 (data2, asc);
    bcd7seg i3 (count[7:4], 1, Seven_Segment_Display[7]);
    bcd7seg i4 (count[3:0], 1, Seven_Segment_Display[6]);
    bcd7seg i5 (data2[7:4], 0, Seven_Segment_Display[5]);
    bcd7seg i6 (data2[3:0], 0, Seven_Segment_Display[4]);
    bcd7seg i7 (asc[7:4], en, Seven_Segment_Display[3]);
    bcd7seg i8 (asc[3:0], en, Seven_Segment_Display[2]);
    bcd7seg i9 (data2[7:4], en, Seven_Segment_Display[1]);
    bcd7seg i10 (data2[3:0], en, Seven_Segment_Display[0]);


endmodule

