//负责对当前指令进行译码, 准备执行阶段需要使用的数据和控制信号
`include "include.v"

module IDU(
    input [31:0] instruction,
    output [4:0] rd,
    output [4:0] rs1,
    output [4:0] rs2,
    output reg [31:0] imm,
    output reg [3:0] op_alu,
    output alu_src2_sel,
    output reg [1:0] wdata_sel,
    output m_ren,
    output m_wen,
    output [1:0] m_size,
    output wen,
    output reg jump_en,
    output ebreak_en
);

    wire [6:0] opcode;
    wire [2:0] funct3;
    wire [6:0] funct7;

    assign opcode = instruction[6:0];
    assign rd = instruction[11:7];
    assign funct3 = instruction[14:12];
    assign rs1 = instruction[19:15];
    assign rs2 = instruction[24:20];
    assign funct7 = instruction[31:25];

    wire [31:0] imm_I, imm_S, imm_B, imm_U, imm_J;

    assign imm_I = {{20{instruction[31]}}, instruction[31:20]};
    assign imm_S = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
    assign imm_B = {{20{instruction[31]}}, instruction[7], instruction[30:25], instruction[11:8], 1'b0};
    assign imm_U = {instruction[31:12], 12'h0000};
    assign imm_J = {{12{instruction[31]}}, instruction[19:12], instruction[20], instruction[30:21], 1'b0};

    always @(*) begin
        case (opcode)
            //RV32IM
            `OP_R_TYPE:          imm = 32'b0;      // R-type：无立即数（ALU 寄存器运算：add, sub, and, or, sll, slt, mul, div...）
            `OP_I_ALU:            imm = imm_I;     // I-type：算术/逻辑立即数（addi, andi, ori, slli, srai ...）
            `OP_I_LOAD:          imm = imm_I;     // I-type：访存加载（lb, lh, lw, lbu, lhu ...）
            `OP_I_JALR:          imm = imm_I;    // I-type：跳转寄存器（jalr）
            `OP_S_TYPE:          imm = imm_S;     // S-type：访存存储（sb, sh, sw）
            `OP_B_TYPE:          imm = imm_B;     // B-type：条件分支（beq, bne, blt, bge, bltu, bgeu）
            `OP_U_LUI:            imm = imm_U;     // U-type：高位立即数（lui）
            `OP_U_AUIPC:       imm = imm_U;     // U-type：PC 相对高位立即数（auipc）
            `OP_J_JAL:            imm = imm_J;     // J-type：跳转链接（jal）
            default:              imm = 32'b0;
        endcase
    end

    assign  ebreak_en = (instruction == `OP_SYSTEM_EBREAK);

    always @(*) begin
        op_alu       = `ALU_NOP;     //默认alu码为无行动码
        alu_src2_sel = 1'b0;      //决定第二个数值是rdata2还是imm，默认为rada2
        wdata_sel = `WB_ALU;     //默认写回的是ALU运算结果
        m_ren        = 1'b0;               //默认存储器读信号关闭
        m_wen        = 1'b0;               //默认存储器写信号关闭
        m_size       = 2'b00;           //默认长度为1字节（0->1字节, 1->2字节, 2-> 4字节）
        wen          = 1'b0;                 //默认寄存器写信号关闭
        jump_en = 0;                        //默认跳转信号关闭
        

        case (opcode)
            `OP_R_TYPE: case (funct3)
                `F3_ADDSUB: begin      
                        case (funct7)
                            `F7_ADD_SLL :begin                 // add
                                op_alu = `ALU_ADD;
                                alu_src2_sel = 1'b0; 
                                wdata_sel = `WB_ALU; 
                                wen    = 1'b1;
                            end

                        default: ;
                        endcase
                end

                default: ;
            endcase
            `OP_I_ALU: case (funct3)
                `F3_ADDSUB: begin                       // addi
                    op_alu = `ALU_ADD; 
                    alu_src2_sel = 1'b1; 
                    wdata_sel = `WB_ALU; 
                    wen = 1'b1;
                end

                default: ;
            endcase
            `OP_I_LOAD: case (funct3)
                `F3_SLT: begin                          // lw
                    op_alu = `ALU_ADD; 
                    alu_src2_sel = 1'b1;
                    wdata_sel = `WB_MEM; 
                    m_ren = 1'b1; 
                    m_size = 2'b10;
                    wen = 1'b1;
                end
                `F3_XOR: begin                          // lbu
                    op_alu = `ALU_ADD; 
                    alu_src2_sel = 1'b1;
                    wdata_sel = `WB_MEM; 
                    m_ren = 1'b1; 
                    m_size = 2'b00; 
                    wen = 1'b1;
                end

                default: ;
            endcase
            `OP_I_JALR: begin                           // jalr
                op_alu = `ALU_ADD; 
                alu_src2_sel = 1'b1; 
                wdata_sel = `WB_PC4; 
                wen = 1'b1;
                jump_en = 1'b1;
            end
            `OP_S_TYPE: case (funct3)
                `F3_ADDSUB: begin                       // sb
                    op_alu = `ALU_ADD; 
                    alu_src2_sel = 1'b1;
                    m_wen = 1'b1; 
                    m_size = 2'b00;
                end
                `F3_SLT: begin                          // sw
                    op_alu = `ALU_ADD; 
                    alu_src2_sel = 1'b1;
                    m_wen = 1'b1; 
                    m_size = 2'b10;
                end

                default: ;
            endcase
            `OP_U_LUI: begin                            // lui
                wdata_sel = `WB_IMM;
                wen = 1'b1;
            end

            default: ;                                
        endcase
    end

endmodule
