`define ROM_SIZE  128  /* BYTES */
`define ROM_DEPTH 16
`define ROM_ADDR_WIDTH 4
`define ROM_ADDR_BUS 3:0
`define ROM_ADDR_LOC 3:0

module rom(clk, addr, dout);
input clk;

input [3:0] addr;
output [7:0] dout;

wire [7:0] dout;

reg  [3:0] addri;
reg  [3:0] addri1;
reg  [3:0] addri2;
reg  [7:0] datao;

always @(posedge clk)
begin
    if (clk) begin
        addri1 <= addr;
        addri2 <= addri1;
        addri <= addri2;
    end
end

always @(*)
begin
    case (addri)
    4'b0000: datao[7:0] <= 8'h10;
    4'b0001: datao[7:0] <= 8'h11;
    4'b0010: datao[7:0] <= 8'h12;
    4'b0011: datao[7:0] <= 8'h13;
    4'b0100: datao[7:0] <= 8'h14;
    4'b0101: datao[7:0] <= 8'h15;
    4'b0110: datao[7:0] <= 8'h16;
    4'b1111: datao[7:0] <= 8'h1F;
    default:
       datao[7:0] <= 8'h00;
    endcase
end

assign dout[7:0] = datao[7:0];

endmodule
