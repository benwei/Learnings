`timescale 1 ns / 1 ps

module rom_tb;
reg clk;
reg rstn;
reg [3:0] addr;
reg [4:0] counter;
wire [7:0] dout;

always #2 clk <= ~clk;

rom DUT(clk, addr, dout);

initial
begin
    rstn <= 1'b0;
    addr <= 0;
    clk <=0;
    counter <= 1;
    $dumpfile("test.vcd");
    $dumpvars(0,rom_tb);
end

always @(posedge clk)
begin
    if (clk)
    begin
        if (counter < 16) addr <= addr + 1;
        else addr <= 4'hx;
        counter <= counter + 1;
        $display("test rom(%d)", addr);
        if (counter >= 23) #1 $finish;
    end
end

endmodule
