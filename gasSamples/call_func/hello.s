# refernce ProgrammingGroundUp 1.0 book
.section .data
hello:
.ascii "hello world!\n\0"

.section .text
.globl _start

_start:
pushl $hello
call printf

push $0
call exit
