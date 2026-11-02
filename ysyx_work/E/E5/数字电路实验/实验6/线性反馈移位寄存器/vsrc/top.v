module top (
    input clk,
    input rst,
    output [7:0] out
);

    Shift_Register shift_register1 (
        .in(out[4]^out[3]^out[2]^out[0]),
        .clk(clk),
        .rst(rst),
        .out(out)
    );

endmodule
