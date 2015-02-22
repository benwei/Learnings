;  hello.s  a first program for nasm for OSX
;
; assemble:	nasm -f mecho64 -l hello.lst  hello.s
; link:		gcc -m64 -o hello hello.o
; run:	        hello 
; output is:	Hello, OSX64

	section .data
CR      equ 10

msg:	db "Hello, OSX64",CR
.len:	equ $-msg

	section .text
        global _main
_main:		
	sub esp,12
	mov	rax,0x2000004 ; write
    mov rdi, 1       ; stdout: 1
	mov	rsi, msg
	mov	rdx, msg.len ; call write(1, msg, len)
	syscall

	mov	rax,0x2000001  ; exit 0 
	mov rdi,0          ; 
	syscall
