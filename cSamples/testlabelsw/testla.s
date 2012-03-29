	.section	__TEXT,__text,regular,pure_instructions
	.globl	_run
	.align	4, 0x90
_run:                                   ## @run
Ltmp3:
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp4:
	.cfi_def_cfa_offset 16
Ltmp5:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp6:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	pushq	%rax
Ltmp7:
	.cfi_offset %rbx, -56
Ltmp8:
	.cfi_offset %r12, -48
Ltmp9:
	.cfi_offset %r13, -40
Ltmp10:
	.cfi_offset %r14, -32
Ltmp11:
	.cfi_offset %r15, -24
	movq	%rdi, %r15
	movb	(%r15), %bl
	leaq	L_run.tdispatch_list(%rip), %r12
	movabsq	$-6148914691236517205, %r13 ## imm = 0xAAAAAAAAAAAAAAAB
	movq	%r15, %r14
	.align	4, 0x90
Ltmp12:                                 ## Block address taken
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_6 Depth 2
                                        ##     Child Loop BB0_4 Depth 2
	movsbl	%bl, %esi
	leaq	L_.str(%rip), %rdi
	xorb	%al, %al
	callq	_printf
	movb	1(%r14), %bl
	incq	%r14
	movl	$3, %eax
	testb	%bl, %bl
	jne	LBB0_3
LBB0_2:                                 ##   in Loop: Header=BB0_1 Depth=1
	xorb	%bl, %bl
	jmpq	*(%r12,%rax,8)
LBB0_3:                                 ##   in Loop: Header=BB0_1 Depth=1
	movq	%r14, %rcx
	subq	%r15, %rcx
	movq	%rcx, %rax
	mulq	%r13
	shrq	%rdx
	leaq	(%rdx,%rdx,2), %rax
	subq	%rax, %rcx
	jmpq	*(%r12,%rcx,8)
	.align	4, 0x90
Ltmp13:                                 ## Block address taken
LBB0_4:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movsbl	%bl, %esi
	leaq	L_.str1(%rip), %rdi
	xorb	%al, %al
	callq	_printf
	movb	1(%r14), %bl
	incq	%r14
	movl	$3, %eax
	testb	%bl, %bl
	je	LBB0_2
## BB#5:                                ##   in Loop: Header=BB0_4 Depth=2
	movq	%r14, %rcx
	subq	%r15, %rcx
	movq	%rcx, %rax
	mulq	%r13
	shrq	%rdx
	leaq	(%rdx,%rdx,2), %rax
	subq	%rax, %rcx
	jmpq	*(%r12,%rcx,8)
	.align	4, 0x90
Ltmp14:                                 ## Block address taken
LBB0_6:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movsbl	%bl, %esi
	leaq	L_.str2(%rip), %rdi
	xorb	%al, %al
	callq	_printf
	movb	1(%r14), %bl
	incq	%r14
	movl	$3, %eax
	testb	%bl, %bl
	je	LBB0_2
## BB#7:                                ##   in Loop: Header=BB0_6 Depth=2
	movq	%r14, %rcx
	subq	%r15, %rcx
	movq	%rcx, %rax
	mulq	%r13
	shrq	%rdx
	leaq	(%rdx,%rdx,2), %rax
	subq	%rax, %rcx
	jmpq	*(%r12,%rcx,8)
Ltmp15:                                 ## Block address taken
LBB0_8:
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
Ltmp16:
	.cfi_endproc
Leh_func_end0:

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
Ltmp19:
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp20:
	.cfi_def_cfa_offset 16
Ltmp21:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp22:
	.cfi_def_cfa_register %rbp
	leaq	L_.str3(%rip), %rdi
	callq	_run
	xorl	%eax, %eax
	popq	%rbp
	ret
Ltmp23:
	.cfi_endproc
Leh_func_end1:

	.section	__DATA,__const
	.align	4                       ## @run.tdispatch_list
L_run.tdispatch_list:
	.quad	Ltmp12
	.quad	Ltmp13
	.quad	Ltmp14
	.quad	Ltmp15

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	 "a:%c\n"

L_.str1:                                ## @.str1
	.asciz	 "b:%c\n"

L_.str2:                                ## @.str2
	.asciz	 "c:%c\n"

L_.str3:                                ## @.str3
	.asciz	 "hello"


.subsections_via_symbols
