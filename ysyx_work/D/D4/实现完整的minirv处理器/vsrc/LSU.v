//负责根据控制信号控制存储器, 从存储器中读出数据, 或将数据写入存储器
`include "include.v"

module LSU(
    input [31:0] alu_result,
    input [31:0] rdata2,
    input m_ren,
    input m_wen,     
    output reg [31:0] m_addr,
    output reg [31:0] m_wdata
);

    always @(*) begin
        m_addr  = 32'h00000000;     //默认访存地址为32'h00000000
        m_wdata = 32'h00000000;    //默认写数据为32'h00000000
        if (m_wen) begin
            m_wdata = rdata2;     
            m_addr = alu_result;    
        end  
        if (m_ren)         
            m_addr = alu_result;
    end

endmodule
