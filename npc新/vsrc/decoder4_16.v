module decoder4_16 (
    input [3:0] pin,
    output [15:0] pout
);
    wire [3:0] npin;

    assign npin[0] = ~pin[0];
    assign npin[1] = ~pin[1];
    assign npin[2] = ~pin[2];
    assign npin[3] = ~pin[3];

    assign pout[0] = npin[3]&npin[2]&npin[1]&npin[0];
    assign pout[1] = npin[3]&npin[2]&npin[1]&pin[0];
    assign pout[2] = npin[3]&npin[2]&pin[1]&npin[0];
    assign pout[3] = npin[3]&npin[2]&pin[1]&pin[0];
    assign pout[4] = npin[3]&pin[2]&npin[1]&npin[0];
    assign pout[5] = npin[3]&pin[2]&npin[1]&pin[0];
    assign pout[6] = npin[3]&pin[2]&pin[1]&npin[0];
    assign pout[7] = npin[3]&pin[2]&pin[1]&pin[0];
    assign pout[8] = pin[3]&npin[2]&npin[1]&npin[0];
    assign pout[9] = pin[3]&npin[2]&npin[1]&pin[0];
    assign pout[10] = pin[3]&npin[2]&pin[1]&npin[0];
    assign pout[11] = pin[3]&npin[2]&pin[1]&pin[0];
    assign pout[12] = pin[3]&pin[2]&npin[1]&npin[0];
    assign pout[13] = pin[3]&pin[2]&npin[1]&pin[0];
    assign pout[14] = pin[3]&pin[2]&pin[1]&npin[0];
    assign pout[15] = pin[3]&pin[2]&pin[1]&pin[0];


endmodule
