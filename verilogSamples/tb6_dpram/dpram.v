/*
 * AUG 2014 written by ben6 
 * dual port ram
 */

`define READ    1'b0
`define WRITE   1'b1

module dpram(
    /* a port */
    input clka,
    input  [7:0] addra,
    input  [7:0] dina,
    input        wea,
    output [7:0] douta,
    /* b port */
    input clkb,
    input  [7:0] addrb,
    input  [7:0] dinb,
    input        web,
    output [7:0] doutb 
);

reg [7:0] maddr[7:0];
reg [7:0] addrae, addrbe;
reg [7:0] addra1, addrb1;

always @(posedge clka)
begin
    if(wea == `WRITE) maddr[addra] <= dina;
end

always @(posedge clkb)
begin
    if(web == `WRITE) maddr[addrb] <= dinb;
end

always @(posedge clka)
begin
    if (wea == `READ) begin
    addra1 <= addra;
    addrae <= addra1;
    end else begin
    addra1 <= addra1;
    addrae <= addrae;
    end
end

always @(posedge clkb)
begin
    if (web == `READ) begin
    addrb1 <= addrb;
    addrbe <= addrb1;
    end else begin
    addrb1 <= addrb1;
    addrbe <= addrbe;
    end
end

assign douta = (wea == `READ) ? maddr[addrae]: 8'hxx;
assign doutb = (web == `READ) ? maddr[addrbe]: 8'hxx;

endmodule
