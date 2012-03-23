	.file	"test_leal.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "times%d(%d)=>%d\12\0"
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%ebx
	subl	$44, %esp
	call	___main
	movl	$2, 28(%esp)
	movl	$0, 24(%esp)
	movl	28(%esp), %eax
	movl	%eax, %ebx
/APP
 # 26 "test_leal.c" 1
	leal (%ebx,%ebx,2),%ebx
 # 0 "" 2
/NO_APP
	movl	%ebx, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, 12(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$3, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	28(%esp), %eax
	movl	%eax, %ebx
/APP
 # 28 "test_leal.c" 1
	leal (%ebx,%ebx,4),%ebx
 # 0 "" 2
/NO_APP
	movl	%ebx, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, 12(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$5, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	28(%esp), %eax
	movl	%eax, %ebx
/APP
 # 30 "test_leal.c" 1
	leal (%ebx,%ebx,8),%ebx
 # 0 "" 2
/NO_APP
	movl	%ebx, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, 12(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$9, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, %eax
	addl	$44, %esp
	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
	.def	_printf;	.scl	2;	.type	32;	.endef
