//负责根据控制信号控制ALU, 对数据进行计算
`include "include.v"

module EXU(
    input [3:0] op_alu,
    input alu_src2_sel,
    input [31:0] rdata1,
    input [31:0] rdata2, 
    input [31:0] imm,
    output reg [31:0] alu_result
);

    wire [31:0] src2;

    assign src2 = alu_src2_sel ? imm : rdata2;

    always @(*) begin
        case (op_alu)
        `ALU_ADD:  alu_result = rdata1 + src2;

        default:  alu_result = 32'h00000000;
        endcase
    end

endmodule
