`timescale 1 ns / 1 ps

`define WIDTH  6

module adder_tb;
reg clk;
reg rstn;
reg [`WIDTH-1:0] counter;
wire [`WIDTH:0] sum;

adder_param # (.width(`WIDTH)) DUT(.A(counter), .B(counter),.sum(sum));

always #2 clk <= ~clk;

initial
begin
    rstn <= 1'b0;
    clk <=0;
    $dumpfile("test.vcd");
    $dumpvars(0,adder_tb);
end

always @(posedge clk or negedge rstn)
begin
    if (!rstn) begin
        counter <= 0;
        rstn <= 1'b1;
    end else begin
        counter <= counter + 1;
        $display("test adder(%d, %d) -> sum %d", counter, counter, sum);
        if (counter > 30) #1 $finish;
    end
end

endmodule
