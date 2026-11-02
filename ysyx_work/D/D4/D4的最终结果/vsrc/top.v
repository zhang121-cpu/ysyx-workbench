import "DPI-C" function void ebreak_handler(input int unsigned a0);

module top (
    input clk,
    input rst
);


    wire [31:0] pc_state;             // 当前 PC
    wire [31:0] instruction;     // 取出的指令
    wire [4:0] rd, rs1, rs2;       // 目的/源寄存器编号
    wire [31:0] imm;                       // 译码得到的立即数
    wire [3:0] op_alu;                  // ALU 运算类型编码
    wire       alu_src2_sel;          // ALU 第二操作数选择：0=rdata2, 1=imm
    wire [1:0] wdata_sel;          // 写回来源选择：00=ALU 01=MEM 10=PC+4 11=IMM
    wire       m_ren, m_wen;          // 访存读/写使能
    wire [1:0] m_size;                // 访存宽度：0=字节 1=半字 2=字
    wire       wen;                             // 寄存器写使能
    wire       jump_en;                    // jalr 跳转使能
    wire       ebreak_en;               // 命中 ebreak 指令
    wire [31:0] rdata1, rdata2;  // GPR 读出的两个源操作数
    wire [31:0] alu_result;      // EXU 输出：运算结果 
    wire [31:0] m_addr;               // 访存地址
    wire [31:0] m_wdata;            // 写内存数据
    wire [31:0] m_rdata;            // 读内存数据
    wire [31:0] wdata;                // 写回寄存器的数据
    wire [31:0] reg_check;       //a0寄存器中的内容

    IFU ifu (clk, rst, jump_en, alu_result, pc_state);
    IDU idu(instruction, rd,  rs1, rs2, imm, op_alu, alu_src2_sel, wdata_sel, m_ren, m_wen, m_size, wen, jump_en, ebreak_en);
    EXU exu(op_alu, alu_src2_sel, rdata1, rdata2,  imm, alu_result);
    LSU lsu(alu_result, rdata2, m_ren, m_wen, m_addr, m_wdata);
    WBU wbu(wdata_sel, alu_result, pc_state, m_rdata, imm, wdata);

    MEM mem (clk, rst, pc_state, instruction, m_addr, m_rdata, m_wdata, m_ren, m_wen, m_size);
    GPR gpr(clk, rst, rs1, rs2, rdata1, rdata2, rd, wdata, wen, reg_check);

//ebreak是大事，为防止毛刺，使用时钟边沿采样
    always @(posedge clk) begin
        if (ebreak_en) ebreak_handler(reg_check);
    end

endmodule
