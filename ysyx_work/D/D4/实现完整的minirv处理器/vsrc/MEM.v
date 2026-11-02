import "DPI-C" function int unsigned pmem_read(input int unsigned addr, input int len);
import "DPI-C" function void pmem_write(
    input int unsigned addr, input int unsigned data, input int len);
import "DPI-C" function void pmem_rst();

module MEM(    
    input clk,
    input rst,
    //指令读取接口
    input [31:0] pc_state,     
    output reg [31:0] instruction,      
    //数据访存接口
    input [31:0] m_addr,
    output reg [31:0] m_rdata,
    input [31:0] m_wdata,
    input m_ren,
    input m_wen,
    input [1:0] m_size
);

    reg [31:0] len;

    always @(*) begin
        // 读取pc对应的instruction
        instruction = pmem_read(pc_state, 4);
    end

    always @(*) begin
        //将传递的m_size改为实际的字节长度
        case (m_size)
            2'b00:   len = 32'd1;
            2'b01:   len = 32'd2;
            2'b10:   len = 32'd4;
            default: len = 32'd0;
        endcase
        // 有读写请求时
        if (m_ren)
            m_rdata = pmem_read(m_addr, len);
        else
            m_rdata = 32'h00000000;
    end

    always @(posedge clk) begin
        if (rst)                        //复位时全清零
            pmem_rst();
        else       
            if (m_wen) begin // 有写请求时
                pmem_write(m_addr, m_wdata, len);
            end
    end

endmodule
