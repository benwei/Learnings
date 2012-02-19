	.file	"hello.bc"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
# BB#0:
	subl	$4, %esp
	movl	$str, (%esp)
	call	puts
	xorl	%eax, %eax
	addl	$4, %esp
	ret
.Ltmp0:
	.size	main, .Ltmp0-main

	.type	str,@object             # @str
	.section	.rodata.str1.1,"aMS",@progbits,1
str:
	.asciz	 "Hello Clang!!!"
	.size	str, 15


	.section	.note.GNU-stack,"",@progbits
