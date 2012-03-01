	.section	__TEXT,__text,regular,pure_instructions
	.globl	_swap
	.align	4, 0x90
_swap:
Leh_func_begin1:
	pushq	%rbp
Ltmp0:
	movq	%rsp, %rbp
Ltmp1:
	pushq	%rbx
	subq	$24, %rsp
Ltmp2:
	movl	%edi, %eax
	movl	%eax, -12(%rbp)
	movl	%esi, -16(%rbp)
	movl	-12(%rbp), %eax
	movl	-16(%rbp), %ecx
	xorb	%dl, %dl
	leaq	L_.str(%rip), %rsi
	movq	%rsi, %rdi
	movl	%eax, %esi
	movb	%dl, -21(%rbp)
	movl	%ecx, %edx
	movb	-21(%rbp), %al
	callq	_printf
	movl	-12(%rbp), %ecx
	movl	-16(%rbp), %edi
	## InlineAsm Start
	movl %edi, %eax;movl %ecx, %ebx;movl %eax, %ecx;movl %ebx, %edi
	## InlineAsm End
	movl	%ecx, -12(%rbp)
	movl	%edi, -16(%rbp)
	movl	-12(%rbp), %ecx
	xorb	%r8b, %r8b
	leaq	L_.str1(%rip), %r9
	movl	%edi, -28(%rbp)
	movq	%r9, %rdi
	movl	%ecx, %esi
	movl	-28(%rbp), %ecx
	movl	%ecx, %edx
	movb	%r8b, %al
	callq	_printf
	movl	-20(%rbp), %eax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
Leh_func_end1:

	.globl	_main
	.align	4, 0x90
_main:
Leh_func_begin2:
	pushq	%rbp
Ltmp3:
	movq	%rsp, %rbp
Ltmp4:
	subq	$16, %rsp
Ltmp5:
	movl	$1, -12(%rbp)
	movl	$2, -16(%rbp)
	movl	-12(%rbp), %eax
	movl	-16(%rbp), %ecx
	movl	%eax, %edi
	movl	%ecx, %esi
	callq	_swap
	movl	$0, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
Leh_func_end2:

	.section	__TEXT,__cstring,cstring_literals
L_.str:
	.asciz	 "before a=%d, b=%d\n"

L_.str1:
	.asciz	 "after  a=%d, b=%d\n"

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
	.globl	_swap.eh
_swap.eh:
Lset1 = Leh_frame_end1-Leh_frame_begin1
	.long	Lset1
Leh_frame_begin1:
Lset2 = Leh_frame_begin1-Leh_frame_common
	.long	Lset2
Ltmp6:
	.quad	Leh_func_begin1-Ltmp6
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
	.byte	4
Lset6 = Ltmp2-Ltmp1
	.long	Lset6
	.byte	131
	.byte	3
	.align	3
Leh_frame_end1:

	.globl	_main.eh
_main.eh:
Lset7 = Leh_frame_end2-Leh_frame_begin2
	.long	Lset7
Leh_frame_begin2:
Lset8 = Leh_frame_begin2-Leh_frame_common
	.long	Lset8
Ltmp7:
	.quad	Leh_func_begin2-Ltmp7
Lset9 = Leh_func_end2-Leh_func_begin2
	.quad	Lset9
	.byte	0
	.byte	4
Lset10 = Ltmp3-Leh_func_begin2
	.long	Lset10
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset11 = Ltmp4-Ltmp3
	.long	Lset11
	.byte	13
	.byte	6
	.align	3
Leh_frame_end2:


.subsections_via_symbols
