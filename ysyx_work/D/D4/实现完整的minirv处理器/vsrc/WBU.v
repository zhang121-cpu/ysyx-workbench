//将数据写入寄存器
`include "include.v"

module WBU(
    input [1:0] wdata_sel,
    input [31:0] alu_result,
    input [31:0] pc_state,
    input [31:0] m_rdata,
    input [31:0] imm,
    output reg [31:0] wdata
);

    always @(*) begin
        case (wdata_sel)
            `WB_ALU: wdata = alu_result;
            `WB_MEM: wdata = m_rdata;
            `WB_PC4: wdata = pc_state + 4;
            `WB_IMM: wdata = imm;
            default: wdata = 32'h00000000;
        endcase
    end

endmodule
