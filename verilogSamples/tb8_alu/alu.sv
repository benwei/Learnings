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

`define OPERAND_IN8   input [7:0]
`define OPERAND_IN16  input [15:0]

`define OPERAND_OUT8  output [7:0]
`define OPERAND_OUT16 output [15:0]

`define OPERAND8  [7:0]
`define OPERAND16 [15:0]

`define OPCODED [3:0]
`define OPCODE_IN input [3:0]
`define OP_NOP  4'b0000
`define OP_ADD  4'b0001
`define OP_SUB  4'b0010
`define OP_MUL  4'b0011
`define OP_DIV  4'b0100

`define OP_SRL  4'b0101
`define OP_SRR  4'b0110
`define OP_SML  4'b0111
`define OP_SMR  4'b1000

`define OP_AND  4'b1001
`define OP_OR   4'b1010
`define OP_NOT  4'b1011
`define OP_XOR  4'b1100
`define OP_CLR  4'b1101
