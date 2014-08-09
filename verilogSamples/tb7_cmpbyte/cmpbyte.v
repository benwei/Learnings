/*
* compare two 8bit registers
**/

module cmpbyte(dina, dinb, gt, eq, le);
input [7:0] dina,dinb;
output le, eq, gt;

function [2:0] compare(input [7:0] dina, input [7:0] dinb);
    if (dina > dinb)
        compare = 3'b100; 
    else if (dina < dinb)
        compare = 3'b001;
    else if (dina == dinb)
        compare = 3'b010;
    else
        compare = 3'bzzz;
endfunction

wire le, eq, gt;
assign {gt, eq, le} = compare(dina, dinb);

endmodule
