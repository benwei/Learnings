`timescale 1 ns / 1 ps

`define WIDTH  6
`define INA 4'ha
`define INB 4'hb

module twomux_tb;
reg clk;
reg rstn;
reg [`WIDTH-1:0] counter;
wire [3:0] dout;
reg sel;

twomux DUT(.dina(`INA),.dinb(`INB),.sel(sel),.dout(dout));

always #2 clk <= ~clk;

initial
begin
    rstn <= 1'b0;
    clk <=0;
    $dumpfile("test.vcd");
    $dumpvars(0,twomux_tb);
end

always @(posedge clk or negedge rstn)
begin
    if (!rstn) begin
        counter <= 0;
        rstn <= 1'b1;
    end else begin
        counter <= counter + 1;
        $display("test twomux inA:%d, inB:%d, sel:%d", `INA, `INB, sel);
        if (counter > 30) #1 $finish;
    end
end

always @(*)
begin
    if (counter[1:0] == 2'b01)  sel <= 1'b1;
    else if (counter[1:0] == 2'b11)  sel <= 1'b0;
    else sel <= sel;
end

endmodule
