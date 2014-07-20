`timescale 1 ns / 1 ps

`define Length 6 

module test;
reg clk;
reg [2:0] counter;

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

initial
begin
    begin: forever_test2
        forever
        begin
            #10 $display("test mux %d", counter);
            if (counter == `Length + 1)
            begin
                disable forever_test2;
            end
        end
    end
end

endmodule
