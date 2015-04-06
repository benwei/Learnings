`timescale 1 ns / 1 ps
`include "alu.sv"

module test;
reg `OPCODED op_counter;
reg `OPERAND8 a;
reg `OPERAND8 b;
wire `OPERAND16 result;

initial
begin
    op_counter = 3'b000;
    a = 8'h55;
    b = 8'h03;
end

initial #150 $finish;

reg [8*3:1] string_opcode;

always #10
begin
    case(op_counter)
    `OP_NOP: string_opcode = "NOP";
    `OP_ADD: string_opcode = "ADD";
    `OP_SUB: string_opcode = "SUB";
    `OP_MUL: string_opcode = "MUL";
    `OP_DIV: string_opcode = "DIV";
    `OP_AND: string_opcode = "AND";
    `OP_OR : string_opcode = "_OR";
    `OP_NOT: string_opcode = "NOT";
    `OP_XOR: string_opcode = "XOR";
    `OP_SRL: string_opcode = "SRL";
    `OP_SRR: string_opcode = "SRR";
    `OP_SML: string_opcode = "SML";
    `OP_SMR: string_opcode = "SMR";
    default:
    string_opcode = "---";
    endcase

    $display("%3dns op=%s(%b),a=%x,b=%x,r=%x", $stime, string_opcode, op_counter, a, b, result);
    op_counter = op_counter + 1;
end

alu SIMPLE_ALU(
        .a(a),
        .b(b),
        .opcode(op_counter),
        .result(result));
endmodule
