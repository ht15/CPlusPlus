	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
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
	subq	$176, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -76(%rbp)
	movl	%edi, -80(%rbp)
	movq	%rsi, -88(%rbp)
	cmpl	$2, -80(%rbp)
	je	LBB0_2
## %bb.1:
	movq	-88(%rbp), %rax
	movq	(%rax), %rsi
	leaq	L_.str(%rip), %rdi
	xorl	%ecx, %ecx
	movb	%cl, %dl
	movb	%dl, %al
	movl	%ecx, -124(%rbp)        ## 4-byte Spill
	callq	_printf
	movl	-124(%rbp), %edi        ## 4-byte Reload
	movl	%eax, -128(%rbp)        ## 4-byte Spill
	callq	_exit
LBB0_2:
	movq	-88(%rbp), %rax
	movq	8(%rax), %rdi
	callq	_atoi
	movl	%eax, -92(%rbp)
	movl	_thread_num(%rip), %eax
	movl	%eax, %edi
	movq	%rsp, %rcx
	movq	%rcx, -104(%rbp)
	leaq	15(,%rdi,8), %rcx
	andq	$-16, %rcx
	movq	%rcx, %rax
	movq	%rdi, -136(%rbp)        ## 8-byte Spill
	callq	____chkstk_darwin
	subq	%rax, %rsp
	movq	%rsp, %rax
	movq	-136(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -112(%rbp)
	leaq	-72(%rbp), %rdi
	movq	%rax, -144(%rbp)        ## 8-byte Spill
	callq	_pthread_attr_init
	movl	$0, -116(%rbp)
	movl	%eax, -148(%rbp)        ## 4-byte Spill
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	movl	-116(%rbp), %eax
	cmpl	_thread_num(%rip), %eax
	jge	LBB0_6
## %bb.4:                               ##   in Loop: Header=BB0_3 Depth=1
	movslq	-116(%rbp), %rax
	shlq	$3, %rax
	movq	-144(%rbp), %rcx        ## 8-byte Reload
	addq	%rax, %rcx
	leaq	-92(%rbp), %rax
	movq	%rcx, %rdi
	leaq	-72(%rbp), %rsi
	leaq	__Z4funcPv(%rip), %rdx
	movq	%rax, %rcx
	callq	_pthread_create
	movl	%eax, -152(%rbp)        ## 4-byte Spill
## %bb.5:                               ##   in Loop: Header=BB0_3 Depth=1
	movl	-116(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -116(%rbp)
	jmp	LBB0_3
LBB0_6:
	movl	$0, -120(%rbp)
LBB0_7:                                 ## =>This Inner Loop Header: Depth=1
	movl	-120(%rbp), %eax
	cmpl	_thread_num(%rip), %eax
	jge	LBB0_10
## %bb.8:                               ##   in Loop: Header=BB0_7 Depth=1
	xorl	%eax, %eax
	movl	%eax, %esi
	movslq	-120(%rbp), %rcx
	movq	-144(%rbp), %rdx        ## 8-byte Reload
	movq	(%rdx,%rcx,8), %rdi
	callq	_pthread_join
	movl	%eax, -156(%rbp)        ## 4-byte Spill
## %bb.9:                               ##   in Loop: Header=BB0_7 Depth=1
	movl	-120(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -120(%rbp)
	jmp	LBB0_7
LBB0_10:
	movl	_total_count(%rip), %esi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -76(%rbp)
	movq	-104(%rbp), %rdi
	movq	%rdi, %rsp
	movl	-76(%rbp), %esi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdi
	movq	(%rdi), %rdi
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rdi
	movl	%eax, -160(%rbp)        ## 4-byte Spill
	movl	%esi, -164(%rbp)        ## 4-byte Spill
	jne	LBB0_12
## %bb.11:
	movl	-164(%rbp), %eax        ## 4-byte Reload
	movq	%rbp, %rsp
	popq	%rbp
	retq
LBB0_12:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__Z4funcPv              ## -- Begin function _Z4funcPv
	.p2align	4, 0x90
__Z4funcPv:                             ## @_Z4funcPv
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	leaq	__ZZ4funcPvE4once(%rip), %rdi
	leaq	__ZL8init_semv(%rip), %rsi
	callq	_pthread_once
	movq	-16(%rbp), %rsi
	movl	$4, (%rsi)
	movq	-16(%rbp), %rsi
	movl	(%rsi), %ecx
	addl	_total_count(%rip), %ecx
	movl	%ecx, _total_count(%rip)
	movq	-8(%rbp), %rsi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movq	%rsi, %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z1PP6rk_sem           ## -- Begin function _Z1PP6rk_sem
	.p2align	4, 0x90
__Z1PP6rk_sem:                          ## @_Z1PP6rk_sem
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZL11rk_sem_waitP6rk_sem
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function _ZL11rk_sem_waitP6rk_sem
__ZL11rk_sem_waitP6rk_sem:              ## @_ZL11rk_sem_waitP6rk_sem
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	$-1, %rsi
	callq	_dispatch_semaphore_wait
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z1VP6rk_sem           ## -- Begin function _Z1VP6rk_sem
	.p2align	4, 0x90
__Z1VP6rk_sem:                          ## @_Z1VP6rk_sem
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZL11rk_sem_postP6rk_sem
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function _ZL11rk_sem_postP6rk_sem
__ZL11rk_sem_postP6rk_sem:              ## @_ZL11rk_sem_postP6rk_sem
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rdi
	callq	_dispatch_semaphore_signal
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function _ZL8init_semv
__ZL8init_semv:                         ## @_ZL8init_semv
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	__ZL4sem1(%rip), %rdi
	movl	$1, %esi
	callq	__ZL11rk_sem_initP6rk_semj
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function _ZL11rk_sem_initP6rk_semj
__ZL11rk_sem_initP6rk_semj:             ## @_ZL11rk_sem_initP6rk_semj
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rdi
	movq	%rdi, -24(%rbp)
	movl	-12(%rbp), %esi
	movl	%esi, %edi
	callq	_dispatch_semaphore_create
	movq	-24(%rbp), %rdi
	movq	%rax, (%rdi)
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_thread_num             ## @thread_num
	.p2align	2
_thread_num:
	.long	10                      ## 0xa

	.globl	_total_count            ## @total_count
.zerofill __DATA,__common,_total_count,4,2
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"use %s add_count\n"

L_.str.1:                               ## @.str.1
	.asciz	"total count is %d\n"

	.section	__DATA,__data
	.p2align	3               ## @_ZZ4funcPvE4once
__ZZ4funcPvE4once:
	.quad	816954554               ## 0x30b1bcba
	.space	8

.zerofill __DATA,__bss,__ZL4sem1,8,3    ## @_ZL4sem1

.subsections_via_symbols
