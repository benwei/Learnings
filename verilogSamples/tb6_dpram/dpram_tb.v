`timescale 1 ns / 1 ps

`define READ    1'b0
`define WRITE   1'b1
`define ENABLE  1'b1
`define DISABLE 1'b0

module dpram_tb;
reg clk;
reg [7:0] addra, addrb;
reg [7:0] dina, dinb;
wire [7:0] douta, doutb;
reg [7:0] counter;
reg wea, web;

always #2 clk <= ~clk;

dpram DUT(.clka(clk),
          .addra(addra),
          .dina(dina), 
          .wea(wea), 
          .douta(douta), 
          .clkb(clk),
          .addrb(addrb),
          .dinb(dinb),
          .web(web),
          .doutb(doutb));

initial
begin
    addra <= 0;
    addrb <= 0;
    dina <= 0;
    dinb <= 0;
    clk <=0;
    counter <= 1;
    $dumpfile("test.vcd");
    $dumpvars(0,dpram_tb);
end

always @(posedge clk)
begin
    counter <= counter + 1;
    if (counter >= 16) #1 $finish;
end

always @(*)
begin
    case (counter)
    1 : begin  addra <= 8'h01; dina <= 8'ha0; wea <= `WRITE;
               addrb <= 8'h02; dinb <= 8'hb0; web <= `WRITE; end
    2 : begin  addra <= 8'h03; dina <= 8'hc0; wea <= `WRITE;
               addrb <= 8'h04; dinb <= 8'hd0; web <= `WRITE; end
    3 : begin  addra <= 8'h05; dina <= 8'he0; wea <= `WRITE;
               addrb <= 8'h06; dinb <= 8'he0; web <= `WRITE; end
    4 : begin  addra <= 8'h07; dina <= 8'h10; wea <= `WRITE;
               addrb <= 8'h08; dinb <= 8'h20; web <= `WRITE; end
    5 : begin  
               addrb <= 8'h08; dinb <= 8'h20; web <= `WRITE; end
    5+1: begin  addra <= 8'h01; dina <= 8'hxx; wea <= `READ;
                addrb <= 8'h02; dinb <= 8'hxx; web <= `READ; end
    6+1: begin  addra <= 8'h03; dina <= 8'hxx; wea <= `READ;
                addrb <= 8'h04; dinb <= 8'hxx; web <= `READ; end
    7+1: begin  addra <= 8'h05; dina <= 8'hxx; wea <= `READ;
                addrb <= 8'h06; dinb <= 8'hxx; web <= `READ; end
    8+1: begin  addra <= 8'h07; dina <= 8'hxx; wea <= `READ;
                addrb <= 8'h08; dinb <= 8'hxx; web <= `READ; end
    9+1: begin  
              addrb <= 8'h08; dinb <= 8'hxx; web <= `READ; end
    default:
       begin  addra <= 8'hxx; dina <= 8'h00; wea <= `READ;
              addrb <= 8'hxx; dinb <= 8'h00; web <= `READ; end
    endcase
    $display("test dpram(addra: %x, addrb: %x)", addra, addrb);
end

endmodule
