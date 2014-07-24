`timescale 1 ns / 1 ps

`define Length 6 

module adder_tb;
reg clk;
reg [3:0] counter;

initial
begin
    counter <= 0;
    clk <=0;

    begin: forever_test
        forever
        begin
            #10  counter <= counter + 1;
                 clk <= ~clk;
            if (counter == `Length)
            begin
                disable forever_test;
            end
        end
    end
end


wire [4:0] sum;

adder DUT(.A(counter), .B(counter),.sum(sum));

initial
begin
    begin: forever_test2
        forever
        begin
            #10 $display("test adder(%d, %d) -> sum %d", counter, counter, sum);
            if (counter == `Length + 1)
            begin
                disable forever_test2;
            end
        end
    end
end

endmodule
