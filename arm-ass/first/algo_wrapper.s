	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	__Z7add_intii                   ; -- Begin function _Z7add_intii
	.p2align	2
__Z7add_intii:                          ; @_Z7add_intii
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32 # sp -= 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill # store pair: frame pointer(x29) 链接寄存器（返回地址）x30 
	add	x29, sp, #16 # fp = sp + 16
	.cfi_def_cfa w29, 16 # debugging info
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	w0, [x29, #-4]  # store unscaled，#-4不用乘以4，这里是将 是add_int的第一个参数的值赋给实参a ，实参a的地址是 [fp - 4]
	str	w1, [sp, #8] # 实参 b ,地址为 sp + 8
	ldur	w0, [x29, #-4] # 准备 call 函数 add，准备调用参数a
	ldr	w1, [sp, #8] #调用参数b
	bl	__Z3addii # 函数调用
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload 准备返回，恢复 fp, x30
	add	sp, sp, #32 #恢复 sp
	ret #返回x30所指地址
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
