# refernce ProgrammingGroundUp 1.0 book
.section .data
person:
.ascii "persons\0"

fmtstring:
.ascii "There are %d %s\n\0"

number:
.long 3

.section .text
.globl _start

_start:

pushl $person
pushl number
pushl $fmtstring
call printf

push $0
call exit
