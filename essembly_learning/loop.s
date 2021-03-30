	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.globl	__Z9call_loopiiiiiiiii  ## -- Begin function _Z9call_loopiiiiiiiii
	.p2align	4, 0x90
__Z9call_loopiiiiiiiii:                 ## @_Z9call_loopiiiiiiiii
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movl	32(%rbp), %eax
	movl	24(%rbp), %r10d
	movl	16(%rbp), %r11d
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	%r8d, -20(%rbp)
	movl	%r9d, -24(%rbp)
	movl	-8(%rbp), %ecx
	movl	%ecx, -32(%rbp)
	movl	-12(%rbp), %ecx
	movl	%ecx, -36(%rbp)
	movl	-16(%rbp), %ecx
	movl	%ecx, -40(%rbp)
	movl	-20(%rbp), %ecx
	movl	%ecx, -44(%rbp)
	movl	-24(%rbp), %ecx
	movl	%ecx, -48(%rbp)
	movl	16(%rbp), %ecx
	movl	%ecx, -52(%rbp)
	movl	24(%rbp), %ecx
	movl	%ecx, -56(%rbp)
	movl	32(%rbp), %ecx
	movl	%ecx, -60(%rbp)
	movl	$0, -28(%rbp)
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	movl	%r10d, -68(%rbp)        ## 4-byte Spill
	movl	%r11d, -72(%rbp)        ## 4-byte Spill
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-28(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-28(%rbp), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -76(%rbp)         ## 4-byte Spill
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
	jmp	LBB0_1
LBB0_4:
	leaq	-28(%rbp), %rax
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movl	$0, -4(%rbp)
	movl	$10, -8(%rbp)
	movl	-8(%rbp), %edi
	movl	-12(%rbp), %esi
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %ecx
	movl	-24(%rbp), %r8d
	movl	-28(%rbp), %r9d
	movl	-32(%rbp), %eax
	movl	-36(%rbp), %r10d
	movl	-40(%rbp), %r11d
	movl	%eax, (%rsp)
	movl	%r10d, 8(%rsp)
	movl	%r11d, 16(%rsp)
	callq	__Z9call_loopiiiiiiiii
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rsi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-48(%rbp), %rsi
	addq	$48, %rsi
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rsi
	leaq	L_.str.2(%rip), %rdi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	-48(%rbp), %rsi
	movl	$24, (%rsi)
	movl	-8(%rbp), %esi
	leaq	L_.str.4(%rip), %rdi
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"this is num:%d\n"

L_.str.1:                               ## @.str.1
	.asciz	"before, j add: %p\n"

L_.str.2:                               ## @.str.2
	.asciz	"after, j add: %p\n"

L_.str.3:                               ## @.str.3
	.asciz	"i add: %p\n"

L_.str.4:                               ## @.str.4
	.asciz	"after detect i is %d\n"


.subsections_via_symbols
