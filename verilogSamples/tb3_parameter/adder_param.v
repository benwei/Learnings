module adder_param(A, B, sum);
parameter width = 4;
input [width-1:0] A, B;
output [width:0] sum;
wire [width:0] sum;

assign sum = A + B;

endmodule
