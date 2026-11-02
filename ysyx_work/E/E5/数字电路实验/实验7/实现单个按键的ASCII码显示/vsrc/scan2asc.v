module scan2asc (
    input [7:0] data_in,
    output reg [7:0] data_out
);
    
    always @(*) begin
        case (data_in) 
            8'h1C: data_out = 8'h41;   // A
            8'h32: data_out = 8'h42;   // B
            8'h21: data_out = 8'h43;   // C
            8'h23: data_out = 8'h44;   // D
            8'h24: data_out = 8'h45;   // E
            8'h2B: data_out = 8'h46;   // F
            8'h34: data_out = 8'h47;   // G
            8'h33: data_out = 8'h48;   // H
            8'h43: data_out = 8'h49;   // I
            8'h3B: data_out = 8'h4A;   // J
            8'h42: data_out = 8'h4B;   // K
            8'h4B: data_out = 8'h4C;   // L
            8'h3A: data_out = 8'h4D;   // M
            8'h31: data_out = 8'h4E;   // N
            8'h44: data_out = 8'h4F;   // O
            8'h4D: data_out = 8'h50;   // P
            8'h15: data_out = 8'h51;   // Q
            8'h2D: data_out = 8'h52;   // R
            8'h1B: data_out = 8'h53;   // S
            8'h2C: data_out = 8'h54;   // T
            8'h3C: data_out = 8'h55;   // U
            8'h2A: data_out = 8'h56;   // V
            8'h1D: data_out = 8'h57;   // W
            8'h22: data_out = 8'h58;   // X
            8'h35: data_out = 8'h59;   // Y
            8'h1A: data_out = 8'h5A;   // Z

            // ── 数字 0-9 ──
            8'h45: data_out = 8'h30;   // 0
            8'h16: data_out = 8'h31;   // 1
            8'h1E: data_out = 8'h32;   // 2
            8'h26: data_out = 8'h33;   // 3
            8'h25: data_out = 8'h34;   // 4
            8'h2E: data_out = 8'h35;   // 5
            8'h36: data_out = 8'h36;   // 6
            8'h3D: data_out = 8'h37;   // 7
            8'h3E: data_out = 8'h38;   // 8
            8'h46: data_out = 8'h39;   // 9

            // ── 空格 ──
            8'h29: data_out = 8'h20;   // Space

            // ── 回车 ──
            8'h5A: data_out = 8'h0D;   // Enter

            // ── 未匹配 → 输出 0 ──
            default: data_out = 8'h00;
        endcase
    end
endmodule

