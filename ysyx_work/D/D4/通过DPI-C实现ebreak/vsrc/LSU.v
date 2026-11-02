//负责根据控制信号控制存储器, 从存储器中读出数据, 或将数据写入存储器
`include "include.v"

module LSU(
    input [6:0] opcode,
    input [2:0] funct3,
    input [31:0] alu_result,
    input [31:0] rdata2,
    output reg [31:0] m_addr,
    output reg [31:0] m_wdata,
    output reg m_ren,
    output reg m_wen,
    output reg [1:0] m_size
);


    always @(*) begin
        m_wdata = 32'h00000000;     //默认存储器写数据
        m_ren = 1'b0;                           //默认读信号关闭
        m_wen = 1'b0;                           //默认写信号关闭
        m_size = 2'b00;                      //默认长度为1字节（0->1字节, 1->2字节, 2-> 4字节）
        case (opcode)
            `OP_I_LOAD:begin
                case (funct3)
                    `F3_SLT:begin                                                                   //lw
                        m_addr = alu_result;
                        m_ren = 1'b1;
                        m_size = 2'b10;
                    end
                    `F3_XOR:begin                                                                   //lbu
                        m_addr = alu_result;
                        m_ren = 1'b1;
                        m_size = 2'b00;
                    end

                    default:m_addr = 32'h00000000;
                endcase
            end
            `OP_S_TYPE:begin
                case (funct3)
                    `F3_SLT:begin                                                                //sw
                        m_addr = alu_result;
                        m_wdata = rdata2;
                        m_wen = 1'b1;
                        m_size = 2'b10;
                    end        
                    `F3_ADDSUB:begin                                                        //sb
                        m_addr = alu_result;
                        m_wdata = {24'h000000, rdata2[7:0]};
                        m_wen = 1'b1;
                        m_size = 2'b00;
                    end   
                    
                    default:m_addr = 32'h00000000;
                endcase
            end

            default:m_addr = 32'h00000000;
        endcase
    end

endmodule
