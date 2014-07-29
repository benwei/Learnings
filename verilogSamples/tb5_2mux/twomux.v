`define WIRE_PART 1

module twomux(dina, dinb, sel, dout);
input [3:0] dina,dinb;
input sel;
output [3:0] dout;


`ifdef WIRE_PART
wire [3:0] dout;
assign dout[3:0] = (sel == 1'b1) ? dina[3:0] :
                   (sel == 1'b0) ? dinb[3:0] :
                   dout[3:0];
`else
reg [3:0] dout;
always @(*)
begin 
    case (sel)
    1'b1:
    dout[3:0] = dina[3:0];
    1'b0:
    dout[3:0] = dinb[3:0];
    default:
    dout[3:0] = dout[3:0];
    endcase
end
`endif

endmodule
