/* verilator lint_off UNUSEDSIGNAL */
//防止将对gpr最高读取位因不使用警告，同时防止对dummy不对输出有影响警告
//riscv要求raddr为5位，但目前minirv只需要16个寄存器，故最后的选择器只需要raddr1[3:0],raddr2[3:0]
module GPR (
    input clk,
    input rst,
    input [4:0] raddr1,
    input [4:0] raddr2,
    output [31:0] rdata1,
    output [31:0] rdata2,
    input [4:0] waddr,
    input [31:0] wdata,
    input wen
);

    wire [15:1] reg_sel;
    wire [15:1] reg_wen;
    wire [511:0] reg_q; 
    wire dummy;

    decoder4_16 dec1 (waddr[3:0], {reg_sel, dummy});
    assign reg_wen = {15{wen}} & reg_sel;       //确定每个寄存器是否开启写信号

    assign reg_q[31:0] = 32'h00000000;         //0号寄存器永远为0
    Reg_32b reg1  (clk, rst, wdata, reg_q[63:32],   reg_wen[1]);
    Reg_32b reg2  (clk, rst, wdata, reg_q[95:64],   reg_wen[2]);
    Reg_32b reg3  (clk, rst, wdata, reg_q[127:96],  reg_wen[3]);
    Reg_32b reg4  (clk, rst, wdata, reg_q[159:128], reg_wen[4]);
    Reg_32b reg5  (clk, rst, wdata, reg_q[191:160], reg_wen[5]);
    Reg_32b reg6  (clk, rst, wdata, reg_q[223:192], reg_wen[6]);
    Reg_32b reg7  (clk, rst, wdata, reg_q[255:224], reg_wen[7]);
    Reg_32b reg8  (clk, rst, wdata, reg_q[287:256], reg_wen[8]);
    Reg_32b reg9  (clk, rst, wdata, reg_q[319:288], reg_wen[9]);
    Reg_32b reg10 (clk, rst, wdata, reg_q[351:320], reg_wen[10]);
    Reg_32b reg11 (clk, rst, wdata, reg_q[383:352], reg_wen[11]);
    Reg_32b reg12 (clk, rst, wdata, reg_q[415:384], reg_wen[12]);
    Reg_32b reg13 (clk, rst, wdata, reg_q[447:416], reg_wen[13]);
    Reg_32b reg14 (clk, rst, wdata, reg_q[479:448], reg_wen[14]);
    Reg_32b reg15 (clk, rst, wdata, reg_q[511:480], reg_wen[15]);

    mux16_1_32b mux1 (reg_q, raddr1[3:0], rdata1);
    mux16_1_32b mux2 (reg_q, raddr2[3:0], rdata2);

endmodule
            
