`timescale 1 ns / 1 ps

module cmpbyte_tb;
reg clk;
reg [4:0] counter;
wire gt, eq, le;
reg [7:0] a, b;

cmpbyte DUT(.dina(a),.dinb(b),.le(le),.eq(eq),.gt(gt));

always #2 clk <= ~clk;

initial
begin
    counter <= 0;
    clk <=0;
    $dumpfile("test.vcd");
    $dumpvars(0,cmpbyte_tb);
end

always @(posedge clk)
begin
    counter <= counter + 1;
    $display("test cmpbyte inA:%d, inB:%d", a, b);
    if (counter > 10) #1 $finish;
end

always @(*)
begin
    case (counter)
    1:
        begin a <= 4; b <= 5; end
    2:
        begin a <= 6; b <= 6; end
    3:
        begin a <= 9; b <= 7; end
    4:
        begin a <= 0; b <= 8'hxx; end
    default:
        begin a <= 8'hxx; b <= 8'hxx; end
    endcase
end

endmodule
