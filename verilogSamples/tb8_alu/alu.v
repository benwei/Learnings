//  DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//  Version 2, December 2004
//
//  Copyright (C) 2015 Ben Wei<ben@juluos.org>
//
//  Everyone is permitted to copy and distribute verbatim or modified
//  copies of this license document, and changing it is allowed as long
//  as the name is changed.
//
//  DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//  TERMS AND CONDITIONS FOR COPYING,
//  DISTRIBUTION AND MODIFICATION
//
//  0. You just DO WHAT THE FUCK YOU WANT TO.
// --------------------------------------------------------------------
// alu code dwexperiments v1

`include "alu.sv"

module alu(
    `OPERAND_IN8 a,
    `OPERAND_IN8 b,
    `OPCODE_IN opcode,
    output reg `OPERAND16 result);

always@(a or b or opcode)
begin
    case (opcode)
    `OP_NOP: ; // No Operation
    `OP_ADD: result = a + b;
    `OP_SUB: result = a - b;
    `OP_MUL: result = a * b;
    `OP_DIV: result = a / b;
    `OP_SRL: result = a << 1;
    `OP_SRR: result = a >> 1;
    `OP_SML: result = a << b;
    `OP_SMR: result = a >> b;
    `OP_AND: result = a & b;
    `OP_OR : result = a | b;
    `OP_NOT: result = ~a;
    `OP_XOR: result = a ^ b;
    `OP_CLR: ; // Reserved
    endcase
end

endmodule
