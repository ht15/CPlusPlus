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
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -48(%rbp)
	cmpl	$2, %edi
	jne	LBB0_9
## %bb.1:
	movq	8(%rsi), %rdi
	callq	_atoi
	movq	%rsp, %r14
	movl	%eax, -116(%rbp)
	movl	_thread_num(%rip), %eax
	leaq	15(,%rax,8), %rax
	andq	$-16, %rax
	callq	____chkstk_darwin
	subq	%rax, %rsp
	movq	%rsp, %rbx
	leaq	-112(%rbp), %rdi
	callq	_pthread_attr_init
	cmpl	$0, _thread_num(%rip)
	jle	LBB0_7
## %bb.2:
	movq	%r14, -136(%rbp)        ## 8-byte Spill
	xorl	%r13d, %r13d
	leaq	__Z4funcPv(%rip), %r14
	leaq	-112(%rbp), %r15
	leaq	-116(%rbp), %r12
	movq	%rbx, -128(%rbp)        ## 8-byte Spill
	.p2align	4, 0x90
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	movq	%rbx, %rdi
	movq	%r15, %rsi
	movq	%r14, %rdx
	movq	%r12, %rcx
	callq	_pthread_create
	incq	%r13
	movslq	_thread_num(%rip), %rax
	addq	$8, %rbx
	cmpq	%rax, %r13
	jl	LBB0_3
## %bb.4:
	testl	%eax, %eax
	movq	-136(%rbp), %r14        ## 8-byte Reload
	movq	-128(%rbp), %r15        ## 8-byte Reload
	jle	LBB0_7
## %bb.5:
	xorl	%ebx, %ebx
	.p2align	4, 0x90
LBB0_6:                                 ## =>This Inner Loop Header: Depth=1
	movq	(%r15,%rbx,8), %rdi
	xorl	%esi, %esi
	callq	_pthread_join
	incq	%rbx
	movslq	_thread_num(%rip), %rax
	cmpq	%rax, %rbx
	jl	LBB0_6
LBB0_7:
	movl	_total_count(%rip), %esi
	leaq	L_.str.1(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	movq	%r14, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	cmpq	-48(%rbp), %rax
	jne	LBB0_10
## %bb.8:
	xorl	%eax, %eax
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
LBB0_10:
	callq	___stack_chk_fail
LBB0_9:
	movq	(%rsi), %rsi
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%edi, %edi
	callq	_exit
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
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	movq	%rdi, %rbx
	leaq	__ZZ4funcPvE4once(%rip), %rdi
	leaq	__ZL8init_semv(%rip), %rsi
	callq	_pthread_once
	movl	$4, (%rbx)
	addl	$4, _total_count(%rip)
	addq	$8, %rsp
	popq	%rbx
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
	popq	%rbp
	jmp	__ZL11rk_sem_waitP6rk_sem ## TAILCALL
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
	movq	(%rdi), %rdi
	movq	$-1, %rsi
	popq	%rbp
	jmp	_dispatch_semaphore_wait ## TAILCALL
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
	popq	%rbp
	jmp	__ZL11rk_sem_postP6rk_sem ## TAILCALL
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
	movq	(%rdi), %rdi
	popq	%rbp
	jmp	_dispatch_semaphore_signal ## TAILCALL
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
	popq	%rbp
	jmp	__ZL11rk_sem_initP6rk_semj ## TAILCALL
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
	movl	$1, %edi
	callq	_dispatch_semaphore_create
	movq	%rax, __ZL4sem1(%rip)
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
