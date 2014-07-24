module adder(A, B, sum);
input [3:0] A, B;
output [4:0] sum;
wire [4:0] sum;

assign sum = A + B;

endmodule
