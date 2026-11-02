module FSM (
    input clk,
    input rst,
    input [7:0] data_in,
    input ready,
    output en_out,
    output reg [7:0] data_out,
    output reg [7:0] count
);

    reg [1:0] next_state, state;
    reg [7:0] data_reg;
    parameter IDLE=2'b00, DOWN=2'b01, WAIT=2'b10;
    
    always @(*) begin
        if (ready && ~clk) begin
            case (state)
                IDLE:next_state = DOWN;
                DOWN:begin
                    if (data_in != 8'hF0)
                        next_state = DOWN;
                    else
                        next_state = WAIT;
                end
                WAIT:next_state = IDLE;
                default:next_state = IDLE;
            endcase
        end
    end

    Reg_2b i0 (clk, rst, next_state, state);

    assign en_out = (state == DOWN);
    always @ (posedge clk) begin
        if (rst) begin
            data_out <= 8'h00;
            data_reg <= 8'h00;
            count <= 8'h00;
        end
        else if (ready) begin
            data_out <= data_in;
            data_reg <= data_out;
            if (data_reg == 8'hF0) begin
                if (data_out == data_in)
                    count <= count +1;
                else
                    count <= 1;
            end
            else if ((data_reg == 8'h00) &&  (data_in != 8'h00))
                count <=1; 
        end
    end

    endmodule


