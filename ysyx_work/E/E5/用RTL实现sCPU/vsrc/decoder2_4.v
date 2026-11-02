module decoder2_4 (
    input [1:0] pin,
    output [3:0] pout
);
    wire [1:0] npin;

    assign npin[1] = ~pin[1];
    assign npin[0] = ~pin[0];

    assign pout[0] = npin[1]&npin[0];
    assign pout[1] = npin[1]&pin[0];
    assign pout[2] = pin[1]&npin[0];
    assign pout[3] = pin[1]&pin[0];

endmodule
