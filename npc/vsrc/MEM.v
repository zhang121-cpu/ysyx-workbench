import "DPI-C" function int unsigned npc_mem_read(input int unsigned addr, input int len);
import "DPI-C" function int unsigned npc_mem_ifetch(input int unsigned addr, input int len);
import "DPI-C" function void npc_mem_write(
    input int unsigned addr, input int unsigned data, input int len);

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

    // 读取pc对应的instruction
    always @(*) begin
        if (rst)
            instruction = 32'h00000000;   // 复位期间不取指，输出 0
        else
            instruction = npc_mem_ifetch(pc_state, 4);
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
            m_rdata = npc_mem_read(m_addr, len);
        else
            m_rdata = 32'h00000000;
    end

    //读寄存器任何时候都可以，但写寄存器发生在时钟上升沿
    always @(posedge clk) begin
        if (!rst && m_wen) begin       //只有非复位且有写请求时才写
                                                                 // 对于内存，初始化时候需要清理，单纯的复位不需要
            npc_mem_write(m_addr, m_wdata, len);
        end
    end

endmodule
