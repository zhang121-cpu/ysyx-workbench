//将数据写入寄存器, 并更新PC
`include "include.v"

module WBU(
    input [6:0] opcode,
    input [2:0] funct3,
    input [6:0]funct7,
    input [31:0] alu_result,
    input [31:0] pc_state,
    input [31:0] m_rdata,
    output reg [31:0] wdata,
    output reg wen
);

    always @(*) begin
        wen = 1'b0;                       //默认写信号线关闭
        case (opcode) 
            `OP_R_TYPE:begin
                case (funct3)
                    `F3_ADDSUB:begin
                        case (funct7)
                            `F7_ADD_SLL:begin                            //add 
                                wdata = alu_result;
                                wen = 1'b1;
                            end

                            default:wdata = 32'b0;
                        endcase 
                    end

                    default:wdata = 32'b0;
                endcase
            end 
            `OP_I_ALU :begin
                case (funct3)
                    `F3_ADDSUB:begin            //addi
                        wdata = alu_result;
                        wen = 1'b1;
                    end

                    default:wdata = 32'b0;
                endcase
            end
            `OP_I_JALR :begin
                case (funct3)
                    `F3_ADDSUB:begin                    //jalr
                        wdata = pc_state + 4;
                        wen = 1'b1;
                    end

                    default:wdata = 32'b0;
                endcase
            end
            `OP_S_TYPE :begin
                case (funct3)

                    default:wdata = 32'b0;      //sw/sb
                endcase
            end
            `OP_U_LUI: begin                         //lui
                wdata = alu_result;
                wen = 1'b1;
            end
            `OP_I_LOAD:begin
                case (funct3)
                    `F3_SLT :begin                       //lw
                        wdata = m_rdata;
                        wen = 1'b1;
                    end
                    `F3_XOR :begin
                        wdata = m_rdata;              //lbu
                        wen = 1'b1;
                    end

                    default:wdata = 32'b0;
                endcase
            end


            default:wdata = 32'b0;

        endcase
    end            

endmodule
