module top (
    input clk,
    input rst,
    output [6:0] Seven_Segment_Display1,
    output [6:0] Seven_Segment_Display0
);

    wire [3:0] pc_state;
    reg [3:0] pc_nextstate;
    wire [127:0] rom_context;
    wire [7:0] instruction;
    wire [1:0] opcode;
    wire [1:0] rd, rs1, rs2;
    wire [3:0] imm, addr;
    wire [7:0] rdata1, rdata2;
    reg [1:0] raddr1, raddr2, waddr;
    reg [7:0] wdata;
    reg wen,seg_dis;

    Reg_noen_4b pc_reg (clk, rst, pc_nextstate, pc_state);

    assign rom_context[7:0]    = 8'b10001010;  
    assign rom_context[15:8]   = 8'b10010000;  
    assign rom_context[23:16]  = 8'b10100000;  
    assign rom_context[31:24]  = 8'b10110001;
    assign rom_context[39:32]  = 8'b00010111;
    assign rom_context[47:40]  = 8'b00101001;
    assign rom_context[55:48]  = 8'b11010001;
    assign rom_context[63:56]  = 8'b01000010;
    assign rom_context[71:64]  = 8'b11011111;
    assign rom_context[79:72]  = 8'b0000_1001;
    assign rom_context[87:80]  = 8'b0000_1010;
    assign rom_context[95:88]  = 8'b0000_1011;
    assign rom_context[103:96] = 8'b0000_1100;
    assign rom_context[111:104]= 8'b0000_1101;
    assign rom_context[119:112]= 8'b0000_1110;
    assign rom_context[127:120]= 8'b0000_1111;
    mux16_1_8b rom (rom_context, pc_state, instruction);

    assign opcode = instruction[7:6];
    assign rd = instruction[5:4];
    assign rs1 = instruction[3:2];
    assign rs2 = instruction[1:0];
    assign imm = instruction[3:0];
    assign addr = instruction[5:2];

    always @ (*) begin
        raddr1 = 2'b00;
        raddr2 = 2'b00;
        waddr  = 2'b00;
        wdata  = 8'h00;
        wen    = 1'b0;
        seg_dis = 1'b0;
        pc_nextstate = pc_state + 4'd1; 

        case (opcode)
            2'b00:begin
                raddr1 = rs1;
                raddr2 = rs2;
                waddr = rd;
                wdata = rdata1 + rdata2;
                wen = 1; 
            end
            2'b01:begin
                raddr2 = rs2;
                wen = 1'b0;
                seg_dis = 1'b1;
            end
            2'b10:begin
                waddr = rd;
                wdata = {4'b0000,imm};
                wen = 1;
            end
            2'b11:begin
                raddr1 = 2'b00;
                raddr2 = rs2;
                wen = 0;
                if (rdata1 != rdata2)
                    pc_nextstate = addr;
            end
            default:begin

            end
        endcase        
    end

    GPR gpr (clk, rst, raddr1, raddr2, rdata1, rdata2, waddr, wdata, wen);

    bcd7seg display1 (rdata2[7:4], seg_dis, Seven_Segment_Display1);
    bcd7seg display2 (rdata2[3:0], seg_dis, Seven_Segment_Display0);

endmodule
