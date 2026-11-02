/* verilator lint_off UNUSEDSIGNAL */
//funct7与rdata2暂时不用
//负责根据控制信号控制ALU, 对数据进行计算
`include "include.v"

module EXU(
    input [6:0] opcode,
    input [2:0] funct3,
    input [6:0]funct7,
    input [31:0] rdata1,
    input [31:0] rdata2, 
    input [31:0] imm,
    output reg jump_en,
    output reg [31:0] alu_result
);

    always @(*) begin
        jump_en = 1'b0;           //默认跳转信号关闭
        case (opcode)
            `OP_I_ALU:begin
                case (funct3)
                    `F3_ADDSUB:alu_result = rdata1 + imm;                     //addi

                    default:alu_result = 32'b0; 
                endcase
            end
            `OP_I_JALR:begin
                case (funct3)
                    `F3_ADDSUB:begin                                                                //jalr
                        alu_result = (rdata1 + imm) & (~32'b1);    
                        jump_en = 1'b1;
                    end           

                    default:alu_result = 32'b0; 
                endcase
            end

            default:alu_result = 32'b0;
        endcase
    end

endmodule
