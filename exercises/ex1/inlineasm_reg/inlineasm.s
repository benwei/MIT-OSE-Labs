	.file	"inlineasm.c"
	.section .rdata,"dr"
LC0:
	.ascii "before a=%d, b=%d\12\0"
LC1:
	.ascii "after  a=%d, b=%d\12\0"
	.text
.globl _swap
	.def	_swap;	.scl	2;	.type	32;	.endef
_swap:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%edx, %ecx
	movl	%eax, %edx
/APP
 # 13 "inlineasm.c" 1
	movl %edx, %eax	
movl %ecx, %ebx	
movl %eax, %ecx	
movl %ebx, %edx	

 # 0 "" 2
/NO_APP
	movl	%ecx, 8(%ebp)
	movl	%edx, 12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$1, 28(%esp)
	movl	$2, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	_swap
	movl	$0, %eax
	leave
	ret
	.def	_printf;	.scl	2;	.type	32;	.endef
