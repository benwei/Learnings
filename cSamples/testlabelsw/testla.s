	.section	__TEXT,__text,regular,pure_instructions
	.section	__DWARF,__debug_frame,regular,debug
Lsection_debug_frame:
	.section	__DWARF,__debug_info,regular,debug
Lsection_info:
	.section	__DWARF,__debug_abbrev,regular,debug
Lsection_abbrev:
	.section	__DWARF,__debug_aranges,regular,debug
Lsection_aranges:
	.section	__DWARF,__debug_macinfo,regular,debug
Lsection_macinfo:
Lsection_line:
	.section	__DWARF,__debug_loc,regular,debug
Lsection_loc:
	.section	__DWARF,__debug_pubnames,regular,debug
Lsection_pubnames:
	.section	__DWARF,__debug_pubtypes,regular,debug
Lsection_pubtypes:
	.section	__DWARF,__debug_str,regular,debug
Lsection_str:
	.section	__DWARF,__debug_ranges,regular,debug
Lsection_ranges:
	.section	__TEXT,__text,regular,pure_instructions
Ltext_begin:
	.section	__DATA,__data
Ldata_begin:
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_run
	.align	4, 0x90
_run:
Leh_func_begin1:
Lfunc_begin1:
Ltmp2:
	pushq	%rbp
Ltmp0:
	movq	%rsp, %rbp
Ltmp1:
	movq	%rdi, -8(%rbp)
Ltmp3:
	movq	-8(%rbp), %rax
	movq	%rax, -48(%rbp)
Ltmp4:
	movq	_C.0.1901(%rip), %rax
	movq	%rax, -80(%rbp)
	movq	_C.0.1901+8(%rip), %rax
	movq	%rax, -72(%rbp)
	movq	_C.0.1901+16(%rip), %rax
	movq	%rax, -64(%rbp)
	movq	_C.0.1901+24(%rip), %rax
	movq	%rax, -56(%rbp)
Ltmp5:
	movl	$1, -84(%rbp)
Ltmp6:
LBB1_1:
Ltmp7:
	movl	-84(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -84(%rbp)
Ltmp8:
	movq	-8(%rbp), %rax
	movabsq	$1, %rcx
	addq	%rcx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movb	(%rax), %al
	cmpb	$0, %al
	je	LBB1_3
	movq	-8(%rbp), %rax
	movq	-48(%rbp), %rcx
	subq	%rcx, %rax
	movabsq	$-6148914691236517205, %rcx
	movq	%rax, -104(%rbp)
	mulq	%rcx
	shrq	%rdx
	movq	%rdx, %rax
	leaq	(%rdx,%rax,2), %rax
	movq	-104(%rbp), %rcx
	subq	%rax, %rcx
	movl	%ecx, %eax
	movl	%eax, -40(%rbp)
	jmp	LBB1_4
LBB1_3:
	movl	$3, -40(%rbp)
LBB1_4:
	movl	-40(%rbp), %eax
	movl	%eax, -88(%rbp)
	movl	-88(%rbp), %eax
	movslq	%eax, %rax
	movq	-80(%rbp,%rax,8), %rax
	movq	%rax, -24(%rbp)
LBB1_5:
	movq	-24(%rbp), %rax
	jmpq	*%rax
Ltmp9:
Ltmp10:
LBB1_6:
Ltmp11:
	movl	-84(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -84(%rbp)
Ltmp12:
	movq	-8(%rbp), %rax
	movabsq	$1, %rcx
	addq	%rcx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movb	(%rax), %al
	cmpb	$0, %al
	je	LBB1_8
	movq	-8(%rbp), %rax
	movq	-48(%rbp), %rcx
	subq	%rcx, %rax
	movabsq	$-6148914691236517205, %rcx
	movq	%rax, -112(%rbp)
	mulq	%rcx
	shrq	%rdx
	movq	%rdx, %rax
	leaq	(%rdx,%rax,2), %rax
	movq	-112(%rbp), %rcx
	subq	%rax, %rcx
	movl	%ecx, %eax
	movl	%eax, -36(%rbp)
	jmp	LBB1_9
LBB1_8:
	movl	$3, -36(%rbp)
LBB1_9:
	movl	-36(%rbp), %eax
	movl	%eax, -92(%rbp)
	movl	-92(%rbp), %eax
	movslq	%eax, %rax
	movq	-80(%rbp,%rax,8), %rax
	movq	%rax, -24(%rbp)
	jmp	LBB1_5
Ltmp13:
Ltmp14:
LBB1_10:
Ltmp15:
	movl	-84(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -84(%rbp)
Ltmp16:
	movq	-8(%rbp), %rax
	movabsq	$1, %rcx
	addq	%rcx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movb	(%rax), %al
	cmpb	$0, %al
	je	LBB1_12
	movq	-8(%rbp), %rax
	movq	-48(%rbp), %rcx
	subq	%rcx, %rax
	movabsq	$-6148914691236517205, %rcx
	movq	%rax, -120(%rbp)
	mulq	%rcx
	shrq	%rdx
	movq	%rdx, %rax
	leaq	(%rdx,%rax,2), %rax
	movq	-120(%rbp), %rcx
	subq	%rax, %rcx
	movl	%ecx, %eax
	movl	%eax, -32(%rbp)
	jmp	LBB1_13
LBB1_12:
	movl	$3, -32(%rbp)
LBB1_13:
	movl	-32(%rbp), %eax
	movl	%eax, -96(%rbp)
	movl	-96(%rbp), %eax
	movslq	%eax, %rax
	movq	-80(%rbp,%rax,8), %rax
	movq	%rax, -24(%rbp)
	jmp	LBB1_5
Ltmp17:
Ltmp18:
LBB1_14:
Ltmp19:
	movl	-84(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	popq	%rbp
	ret
Ltmp20:
Lfunc_end1:
Leh_func_end1:

	.section	__DATA,__const
	.align	4
_C.0.1901:
	.quad	Ltmp6
	.quad	Ltmp10
	.quad	Ltmp14
	.quad	Ltmp18

	.section	__TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame0:
Lsection_eh_frame:
Leh_frame_common:
Lset0 = Leh_frame_common_end-Leh_frame_common_begin
	.long	Lset0
Leh_frame_common_begin:
	.long	0
	.byte	1
	.asciz	 "zR"
	.byte	1
	.byte	120
	.byte	16
	.byte	1
	.byte	16
	.byte	12
	.byte	7
	.byte	8
	.byte	144
	.byte	1
	.align	3
Leh_frame_common_end:
	.globl	_run.eh
_run.eh:
Lset1 = Leh_frame_end1-Leh_frame_begin1
	.long	Lset1
Leh_frame_begin1:
Lset2 = Leh_frame_begin1-Leh_frame_common
	.long	Lset2
Ltmp21:
	.quad	Leh_func_begin1-Ltmp21
Lset3 = Leh_func_end1-Leh_func_begin1
	.quad	Lset3
	.byte	0
	.byte	4
Lset4 = Ltmp0-Leh_func_begin1
	.long	Lset4
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset5 = Ltmp1-Ltmp0
	.long	Lset5
	.byte	13
	.byte	6
	.align	3
Leh_frame_end1:

	.section	__TEXT,__text,regular,pure_instructions
Ltext_end:
	.section	__DATA,__data
Ldata_end:
	.section	__TEXT,__text,regular,pure_instructions
Lsection_end1:
	.section	__DWARF,__debug_frame,regular,debug
Ldebug_frame_common:
Lset6 = Ldebug_frame_common_end-Ldebug_frame_common_begin
	.long	Lset6
Ldebug_frame_common_begin:
	.long	4294967295
	.byte	1
	.byte	0
	.byte	1
	.byte	120
	.byte	16
	.byte	12
	.byte	7
	.byte	8
	.byte	144
	.byte	1
	.align	2
Ldebug_frame_common_end:
Lset7 = Ldebug_frame_end1-Ldebug_frame_begin1
	.long	Lset7
Ldebug_frame_begin1:
Lset8 = Ldebug_frame_common-Lsection_debug_frame
	.long	Lset8
	.quad	Lfunc_begin1
Lset9 = Lfunc_end1-Lfunc_begin1
	.quad	Lset9
	.byte	4
Lset10 = Ltmp0-Lfunc_begin1
	.long	Lset10
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset11 = Ltmp1-Ltmp0
	.long	Lset11
	.byte	13
	.byte	6
	.align	2
Ldebug_frame_end1:
	.section	__DWARF,__debug_info,regular,debug
Linfo_begin1:
	.long	430
	.short	2
Lset12 = Labbrev_begin-Lsection_abbrev
	.long	Lset12
	.byte	8
	.byte	1
	.ascii	 "4.2.1 (Based on Apple Inc. build 5658) (LLVM build 2336.1.00)"
	.byte	0
	.byte	1
	.ascii	 "testla.c"
	.byte	0
	.quad	0
	.long	0
	.ascii	 "/Users/ben_wei/src/github/Learnings/cSamples/testlabelsw/"
	.byte	0
	.byte	2
	.byte	5
	.ascii	 "int"
	.byte	0
	.byte	4
	.byte	3
	.long	386
	.ascii	 "run"
	.byte	0
	.ascii	 "run"
	.byte	0
	.byte	1
	.byte	10
	.byte	1
	.long	154
	.byte	1
	.quad	Lfunc_begin1
	.quad	Lfunc_end1
	.byte	1
	.byte	86
	.byte	4
	.byte	115
	.byte	0
	.byte	1
	.byte	9
	.long	402
	.byte	2
	.byte	145
	.byte	120
	.byte	5
	.quad	Ltmp3
	.quad	Ltmp20
	.byte	6
	.ascii	 "head"
	.byte	0
	.byte	1
	.byte	11
	.long	402
	.byte	2
	.byte	145
	.byte	80
	.byte	6
	.ascii	 "tdispatch_list"
	.byte	0
	.byte	1
	.byte	12
	.long	417
	.byte	3
	.byte	145
	.byte	176
	.byte	127
	.byte	6
	.byte	97
	.byte	0
	.byte	1
	.byte	13
	.long	154
	.byte	3
	.byte	145
	.byte	172
	.byte	127
	.byte	7
	.long	318
	.quad	Ltmp8
	.quad	Ltmp9
	.byte	6
	.byte	110
	.byte	0
	.byte	1
	.byte	18
	.long	154
	.byte	3
	.byte	145
	.byte	168
	.byte	127
	.byte	0
	.byte	7
	.long	353
	.quad	Ltmp12
	.quad	Ltmp13
	.byte	6
	.byte	110
	.byte	0
	.byte	1
	.byte	22
	.long	154
	.byte	3
	.byte	145
	.byte	164
	.byte	127
	.byte	0
	.byte	5
	.quad	Ltmp16
	.quad	Ltmp17
	.byte	6
	.byte	110
	.byte	0
	.byte	1
	.byte	26
	.long	154
	.byte	3
	.byte	145
	.byte	160
	.byte	127
	.byte	0
	.byte	0
	.byte	0
	.byte	2
	.byte	6
	.ascii	 "char"
	.byte	0
	.byte	1
	.byte	8
	.long	386
	.byte	1
	.byte	1
	.byte	0
	.byte	9
	.long	394
	.byte	8
	.byte	1
	.byte	0
	.byte	10
	.byte	8
	.byte	1
	.byte	0
	.byte	11
	.byte	4
	.byte	5
	.byte	12
	.long	410
	.byte	13
	.long	414
	.byte	3
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
Linfo_end1:
	.section	__DWARF,__debug_abbrev,regular,debug
Labbrev_begin:
	.byte	1
	.byte	17
	.byte	1
	.byte	37
	.byte	8
	.byte	19
	.byte	11
	.byte	3
	.byte	8
	.byte	82
	.byte	1
	.byte	16
	.byte	6
	.byte	27
	.byte	8
	.byte	0
	.byte	0
	.byte	2
	.byte	36
	.byte	0
	.byte	62
	.byte	11
	.byte	3
	.byte	8
	.byte	11
	.byte	11
	.byte	0
	.byte	0
	.byte	3
	.byte	46
	.byte	1
	.byte	1
	.byte	19
	.byte	3
	.byte	8
	.byte	135
	.byte	64
	.byte	8
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	39
	.byte	12
	.byte	73
	.byte	19
	.byte	63
	.byte	12
	.byte	17
	.byte	1
	.byte	18
	.byte	1
	.byte	64
	.byte	10
	.byte	0
	.byte	0
	.byte	4
	.byte	5
	.byte	0
	.byte	3
	.byte	8
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	73
	.byte	19
	.byte	2
	.byte	10
	.byte	0
	.byte	0
	.byte	5
	.byte	11
	.byte	1
	.byte	17
	.byte	1
	.byte	18
	.byte	1
	.byte	0
	.byte	0
	.byte	6
	.byte	52
	.byte	0
	.byte	3
	.byte	8
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	73
	.byte	19
	.byte	2
	.byte	10
	.byte	0
	.byte	0
	.byte	7
	.byte	11
	.byte	1
	.byte	1
	.byte	19
	.byte	17
	.byte	1
	.byte	18
	.byte	1
	.byte	0
	.byte	0
	.byte	8
	.byte	38
	.byte	0
	.byte	73
	.byte	19
	.byte	11
	.byte	11
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	0
	.byte	0
	.byte	9
	.byte	15
	.byte	0
	.byte	73
	.byte	19
	.byte	11
	.byte	11
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	0
	.byte	0
	.byte	10
	.byte	15
	.byte	0
	.byte	11
	.byte	11
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	0
	.byte	0
	.byte	11
	.byte	36
	.byte	0
	.byte	11
	.byte	11
	.byte	62
	.byte	11
	.byte	0
	.byte	0
	.byte	12
	.byte	1
	.byte	1
	.byte	73
	.byte	19
	.byte	0
	.byte	0
	.byte	13
	.byte	33
	.byte	0
	.byte	73
	.byte	19
	.byte	47
	.byte	11
	.byte	0
	.byte	0
	.byte	0
Labbrev_end:
	.section	__DWARF,__debug_line,regular,debug
Lset13 = Lline_end-Lline_begin
	.long	Lset13
Lline_begin:
	.short	2
Lset14 = Lline_prolog_end-Lline_prolog_begin
	.long	Lset14
Lline_prolog_begin:
	.byte	1
	.byte	1
	.byte	246
	.byte	245
	.byte	10
	.byte	0
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	0
	.byte	0
	.byte	0
	.byte	1
	.asciz	 "/Users/ben_wei/src/github/Learnings/cSamples/testlabelsw/"
	.byte	0
	.asciz	 "testla.c"
	.byte	1
	.byte	0
	.byte	0
	.byte	0
Lline_prolog_end:
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp2
	.byte	29
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp3
	.byte	21
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp4
	.byte	21
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp5
	.byte	21
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp7
	.byte	24
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp8
	.byte	21
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp11
	.byte	23
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp12
	.byte	21
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp15
	.byte	22
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp16
	.byte	22
	.byte	0
	.byte	9
	.byte	2
	.quad	Ltmp19
	.byte	23
	.byte	0
	.byte	9
	.byte	2
	.quad	Lsection_end1
	.byte	0
	.byte	1
	.byte	1
Lline_end:
	.section	__DWARF,__debug_pubnames,regular,debug
Lset15 = Lpubnames_end1-Lpubnames_begin1
	.long	Lset15
Lpubnames_begin1:
	.short	2
Lset16 = Linfo_begin1-Lsection_info
	.long	Lset16
Lset17 = Linfo_end1-Linfo_begin1
	.long	Lset17
	.long	161
	.asciz	 "run"
	.long	0
Lpubnames_end1:
	.section	__DWARF,__debug_pubtypes,regular,debug
Lset18 = Lpubtypes_end1-Lpubtypes_begin1
	.long	Lset18
Lpubtypes_begin1:
	.short	2
Lset19 = Linfo_begin1-Lsection_info
	.long	Lset19
Lset20 = Linfo_end1-Linfo_begin1
	.long	Lset20
	.long	0
Lpubtypes_end1:
	.section	__DWARF,__debug_aranges,regular,debug
	.section	__DWARF,__debug_ranges,regular,debug
	.section	__DWARF,__debug_macinfo,regular,debug
	.section	__DWARF,__debug_inlined,regular,debug
Lset21 = Ldebug_inlined_end1-Ldebug_inlined_begin1
	.long	Lset21
Ldebug_inlined_begin1:
	.short	2
	.byte	8
Ldebug_inlined_end1:

.subsections_via_symbols
