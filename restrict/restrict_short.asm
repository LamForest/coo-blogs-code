
restrict_short:	file format mach-o arm64

Disassembly of section __TEXT,__text:

0000000100003938 <__Z4add1PsS_>:
100003938: 48 01 80 52 	mov	w8, #10
10000393c: 08 00 00 79 	strh	w8, [x0]
100003940: 88 01 80 52 	mov	w8, #12
100003944: 28 00 00 79 	strh	w8, [x1]
100003948: 08 00 40 79 	ldrh	w8, [x0]
10000394c: 08 31 00 11 	add	w8, w8, #12
100003950: 00 3d 00 13 	sxth	w0, w8
100003954: c0 03 5f d6 	ret

0000000100003958 <__Z4add2PsS_>:
100003958: 48 01 80 52 	mov	w8, #10
10000395c: 08 00 00 79 	strh	w8, [x0]
100003960: 88 01 80 52 	mov	w8, #12
100003964: 28 00 00 79 	strh	w8, [x1]
100003968: 08 00 40 79 	ldrh	w8, [x0]
10000396c: 08 31 00 11 	add	w8, w8, #12
100003970: 00 3d 00 13 	sxth	w0, w8
100003974: c0 03 5f d6 	ret

0000000100003978 <_main>:
100003978: ff c3 00 d1 	sub	sp, sp, #48
10000397c: f4 4f 01 a9 	stp	x20, x19, [sp, #16]
100003980: fd 7b 02 a9 	stp	x29, x30, [sp, #32]
100003984: fd 83 00 91 	add	x29, sp, #32
100003988: 31 01 00 94 	bl	0x100003e4c <_memset+0x100003e4c>
10000398c: f3 03 00 aa 	mov	x19, x0
100003990: 2f 01 00 94 	bl	0x100003e4c <_memset+0x100003e4c>
100003994: f4 03 00 aa 	mov	x20, x0
100003998: 1f 20 03 d5 	nop
10000399c: 20 35 00 58 	ldr	x0, 0x100004040 <_memset+0x100004040>
1000039a0: 41 2e 00 10 	adr	x1, #1480
1000039a4: 1f 20 03 d5 	nop
1000039a8: 42 02 80 52 	mov	w2, #18
1000039ac: 53 00 00 94 	bl	0x100003af8 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m>
1000039b0: 81 02 13 cb 	sub	x1, x20, x19
1000039b4: 23 01 00 94 	bl	0x100003e40 <_memset+0x100003e40>
1000039b8: 01 2e 00 70 	adr	x1, #1475
1000039bc: 1f 20 03 d5 	nop
1000039c0: 82 00 80 52 	mov	w2, #4
1000039c4: 4d 00 00 94 	bl	0x100003af8 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m>
1000039c8: f3 03 00 aa 	mov	x19, x0
1000039cc: 08 00 40 f9 	ldr	x8, [x0]
1000039d0: 08 81 5e f8 	ldur	x8, [x8, #-24]
1000039d4: 00 00 08 8b 	add	x0, x0, x8
1000039d8: e8 23 00 91 	add	x8, sp, #8
1000039dc: 0a 01 00 94 	bl	0x100003e04 <_memset+0x100003e04>
1000039e0: 1f 20 03 d5 	nop
1000039e4: 21 33 00 58 	ldr	x1, 0x100004048 <_memset+0x100004048>
1000039e8: e0 23 00 91 	add	x0, sp, #8
1000039ec: 03 01 00 94 	bl	0x100003df8 <_memset+0x100003df8>
1000039f0: 08 00 40 f9 	ldr	x8, [x0]
1000039f4: 08 1d 40 f9 	ldr	x8, [x8, #56]
1000039f8: 41 01 80 52 	mov	w1, #10
1000039fc: 00 01 3f d6 	blr	x8
100003a00: f4 03 00 aa 	mov	x20, x0
100003a04: e0 23 00 91 	add	x0, sp, #8
100003a08: 14 01 00 94 	bl	0x100003e58 <_memset+0x100003e58>
100003a0c: e0 03 13 aa 	mov	x0, x19
100003a10: e1 03 14 aa 	mov	x1, x20
100003a14: ff 00 00 94 	bl	0x100003e10 <_memset+0x100003e10>
100003a18: e0 03 13 aa 	mov	x0, x19
100003a1c: 00 01 00 94 	bl	0x100003e1c <_memset+0x100003e1c>
100003a20: 0b 01 00 94 	bl	0x100003e4c <_memset+0x100003e4c>
100003a24: f3 03 00 aa 	mov	x19, x0
100003a28: 09 01 00 94 	bl	0x100003e4c <_memset+0x100003e4c>
100003a2c: f4 03 00 aa 	mov	x20, x0
100003a30: 1f 20 03 d5 	nop
100003a34: 60 30 00 58 	ldr	x0, 0x100004040 <_memset+0x100004040>
100003a38: 81 29 00 10 	adr	x1, #1328
100003a3c: 1f 20 03 d5 	nop
100003a40: 42 02 80 52 	mov	w2, #18
100003a44: 2d 00 00 94 	bl	0x100003af8 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m>
100003a48: 81 02 13 cb 	sub	x1, x20, x19
100003a4c: fd 00 00 94 	bl	0x100003e40 <_memset+0x100003e40>
100003a50: 41 29 00 70 	adr	x1, #1323
100003a54: 1f 20 03 d5 	nop
100003a58: 82 00 80 52 	mov	w2, #4
100003a5c: 27 00 00 94 	bl	0x100003af8 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m>
100003a60: f3 03 00 aa 	mov	x19, x0
100003a64: 08 00 40 f9 	ldr	x8, [x0]
100003a68: 08 81 5e f8 	ldur	x8, [x8, #-24]
100003a6c: 00 00 08 8b 	add	x0, x0, x8
100003a70: e8 23 00 91 	add	x8, sp, #8
100003a74: e4 00 00 94 	bl	0x100003e04 <_memset+0x100003e04>
100003a78: 1f 20 03 d5 	nop
100003a7c: 61 2e 00 58 	ldr	x1, 0x100004048 <_memset+0x100004048>
100003a80: e0 23 00 91 	add	x0, sp, #8
100003a84: dd 00 00 94 	bl	0x100003df8 <_memset+0x100003df8>
100003a88: 08 00 40 f9 	ldr	x8, [x0]
100003a8c: 08 1d 40 f9 	ldr	x8, [x8, #56]
100003a90: 41 01 80 52 	mov	w1, #10
100003a94: 00 01 3f d6 	blr	x8
100003a98: f4 03 00 aa 	mov	x20, x0
100003a9c: e0 23 00 91 	add	x0, sp, #8
100003aa0: ee 00 00 94 	bl	0x100003e58 <_memset+0x100003e58>
100003aa4: e0 03 13 aa 	mov	x0, x19
100003aa8: e1 03 14 aa 	mov	x1, x20
100003aac: d9 00 00 94 	bl	0x100003e10 <_memset+0x100003e10>
100003ab0: e0 03 13 aa 	mov	x0, x19
100003ab4: da 00 00 94 	bl	0x100003e1c <_memset+0x100003e1c>
100003ab8: 00 00 80 52 	mov	w0, #0
100003abc: fd 7b 42 a9 	ldp	x29, x30, [sp, #32]
100003ac0: f4 4f 41 a9 	ldp	x20, x19, [sp, #16]
100003ac4: ff c3 00 91 	add	sp, sp, #48
100003ac8: c0 03 5f d6 	ret
100003acc: f3 03 00 aa 	mov	x19, x0
100003ad0: e0 23 00 91 	add	x0, sp, #8
100003ad4: e1 00 00 94 	bl	0x100003e58 <_memset+0x100003e58>
100003ad8: 05 00 00 14 	b	0x100003aec <_main+0x174>
100003adc: c1 00 00 94 	bl	0x100003de0 <___clang_call_terminate>
100003ae0: f3 03 00 aa 	mov	x19, x0
100003ae4: e0 23 00 91 	add	x0, sp, #8
100003ae8: dc 00 00 94 	bl	0x100003e58 <_memset+0x100003e58>
100003aec: e0 03 13 aa 	mov	x0, x19
100003af0: bf 00 00 94 	bl	0x100003dec <_memset+0x100003dec>
100003af4: bb 00 00 94 	bl	0x100003de0 <___clang_call_terminate>

0000000100003af8 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m>:
100003af8: ff c3 01 d1 	sub	sp, sp, #112
100003afc: fa 67 02 a9 	stp	x26, x25, [sp, #32]
100003b00: f8 5f 03 a9 	stp	x24, x23, [sp, #48]
100003b04: f6 57 04 a9 	stp	x22, x21, [sp, #64]
100003b08: f4 4f 05 a9 	stp	x20, x19, [sp, #80]
100003b0c: fd 7b 06 a9 	stp	x29, x30, [sp, #96]
100003b10: fd 83 01 91 	add	x29, sp, #96
100003b14: f5 03 02 aa 	mov	x21, x2
100003b18: f4 03 01 aa 	mov	x20, x1
100003b1c: f3 03 00 aa 	mov	x19, x0
100003b20: e0 23 00 91 	add	x0, sp, #8
100003b24: e1 03 13 aa 	mov	x1, x19
100003b28: c0 00 00 94 	bl	0x100003e28 <_memset+0x100003e28>
100003b2c: e8 23 40 39 	ldrb	w8, [sp, #8]
100003b30: 48 05 00 34 	cbz	w8, 0x100003bd8 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xe0>
100003b34: 68 02 40 f9 	ldr	x8, [x19]
100003b38: 08 81 5e f8 	ldur	x8, [x8, #-24]
100003b3c: 76 02 08 8b 	add	x22, x19, x8
100003b40: d7 16 40 f9 	ldr	x23, [x22, #40]
100003b44: d9 0a 40 b9 	ldr	w25, [x22, #8]
100003b48: d8 92 40 b9 	ldr	w24, [x22, #144]
100003b4c: 1f 07 00 31 	cmn	w24, #1
100003b50: 01 02 00 54 	b.ne	0x100003b90 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x98>
100003b54: e8 63 00 91 	add	x8, sp, #24
100003b58: e0 03 16 aa 	mov	x0, x22
100003b5c: aa 00 00 94 	bl	0x100003e04 <_memset+0x100003e04>
100003b60: 1f 20 03 d5 	nop
100003b64: 21 27 00 58 	ldr	x1, 0x100004048 <_memset+0x100004048>
100003b68: e0 63 00 91 	add	x0, sp, #24
100003b6c: a3 00 00 94 	bl	0x100003df8 <_memset+0x100003df8>
100003b70: 08 00 40 f9 	ldr	x8, [x0]
100003b74: 08 1d 40 f9 	ldr	x8, [x8, #56]
100003b78: 01 04 80 52 	mov	w1, #32
100003b7c: 00 01 3f d6 	blr	x8
100003b80: f8 03 00 aa 	mov	x24, x0
100003b84: e0 63 00 91 	add	x0, sp, #24
100003b88: b4 00 00 94 	bl	0x100003e58 <_memset+0x100003e58>
100003b8c: d8 92 00 b9 	str	w24, [x22, #144]
100003b90: 83 02 15 8b 	add	x3, x20, x21
100003b94: 08 16 80 52 	mov	w8, #176
100003b98: 28 03 08 0a 	and	w8, w25, w8
100003b9c: 1f 81 00 71 	cmp	w8, #32
100003ba0: 62 00 94 9a 	csel	x2, x3, x20, eq
100003ba4: 05 1f 00 13 	sxtb	w5, w24
100003ba8: e0 03 17 aa 	mov	x0, x23
100003bac: e1 03 14 aa 	mov	x1, x20
100003bb0: e4 03 16 aa 	mov	x4, x22
100003bb4: 2b 00 00 94 	bl	0x100003c60 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_>
100003bb8: 00 01 00 b5 	cbnz	x0, 0x100003bd8 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xe0>
100003bbc: 68 02 40 f9 	ldr	x8, [x19]
100003bc0: 08 81 5e f8 	ldur	x8, [x8, #-24]
100003bc4: 60 02 08 8b 	add	x0, x19, x8
100003bc8: 08 20 40 b9 	ldr	w8, [x0, #32]
100003bcc: a9 00 80 52 	mov	w9, #5
100003bd0: 01 01 09 2a 	orr	w1, w8, w9
100003bd4: a7 00 00 94 	bl	0x100003e70 <_memset+0x100003e70>
100003bd8: e0 23 00 91 	add	x0, sp, #8
100003bdc: 96 00 00 94 	bl	0x100003e34 <_memset+0x100003e34>
100003be0: e0 03 13 aa 	mov	x0, x19
100003be4: fd 7b 46 a9 	ldp	x29, x30, [sp, #96]
100003be8: f4 4f 45 a9 	ldp	x20, x19, [sp, #80]
100003bec: f6 57 44 a9 	ldp	x22, x21, [sp, #64]
100003bf0: f8 5f 43 a9 	ldp	x24, x23, [sp, #48]
100003bf4: fa 67 42 a9 	ldp	x26, x25, [sp, #32]
100003bf8: ff c3 01 91 	add	sp, sp, #112
100003bfc: c0 03 5f d6 	ret
100003c00: 06 00 00 14 	b	0x100003c18 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x120>
100003c04: f4 03 00 aa 	mov	x20, x0
100003c08: e0 63 00 91 	add	x0, sp, #24
100003c0c: 93 00 00 94 	bl	0x100003e58 <_memset+0x100003e58>
100003c10: 03 00 00 14 	b	0x100003c1c <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x124>
100003c14: 73 00 00 94 	bl	0x100003de0 <___clang_call_terminate>
100003c18: f4 03 00 aa 	mov	x20, x0
100003c1c: e0 23 00 91 	add	x0, sp, #8
100003c20: 85 00 00 94 	bl	0x100003e34 <_memset+0x100003e34>
100003c24: 02 00 00 14 	b	0x100003c2c <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x134>
100003c28: f4 03 00 aa 	mov	x20, x0
100003c2c: e0 03 14 aa 	mov	x0, x20
100003c30: 9c 00 00 94 	bl	0x100003ea0 <_memset+0x100003ea0>
100003c34: 68 02 40 f9 	ldr	x8, [x19]
100003c38: 08 81 5e f8 	ldur	x8, [x8, #-24]
100003c3c: 60 02 08 8b 	add	x0, x19, x8
100003c40: 89 00 00 94 	bl	0x100003e64 <_memset+0x100003e64>
100003c44: 9a 00 00 94 	bl	0x100003eac <_memset+0x100003eac>
100003c48: e6 ff ff 17 	b	0x100003be0 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xe8>
100003c4c: f3 03 00 aa 	mov	x19, x0
100003c50: 97 00 00 94 	bl	0x100003eac <_memset+0x100003eac>
100003c54: e0 03 13 aa 	mov	x0, x19
100003c58: 65 00 00 94 	bl	0x100003dec <_memset+0x100003dec>
100003c5c: 61 00 00 94 	bl	0x100003de0 <___clang_call_terminate>

0000000100003c60 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_>:
100003c60: ff c3 01 d1 	sub	sp, sp, #112
100003c64: fa 67 02 a9 	stp	x26, x25, [sp, #32]
100003c68: f8 5f 03 a9 	stp	x24, x23, [sp, #48]
100003c6c: f6 57 04 a9 	stp	x22, x21, [sp, #64]
100003c70: f4 4f 05 a9 	stp	x20, x19, [sp, #80]
100003c74: fd 7b 06 a9 	stp	x29, x30, [sp, #96]
100003c78: fd 83 01 91 	add	x29, sp, #96
100003c7c: f3 03 00 aa 	mov	x19, x0
100003c80: 20 09 00 b4 	cbz	x0, 0x100003da4 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x144>
100003c84: f8 03 05 aa 	mov	x24, x5
100003c88: f4 03 04 aa 	mov	x20, x4
100003c8c: f6 03 03 aa 	mov	x22, x3
100003c90: f5 03 02 aa 	mov	x21, x2
100003c94: 88 0c 40 f9 	ldr	x8, [x4, #24]
100003c98: 69 00 01 cb 	sub	x9, x3, x1
100003c9c: 08 01 09 eb 	subs	x8, x8, x9
100003ca0: 17 c1 9f 9a 	csel	x23, x8, xzr, gt
100003ca4: 59 00 01 cb 	sub	x25, x2, x1
100003ca8: 3f 07 00 f1 	cmp	x25, #1
100003cac: 0b 01 00 54 	b.lt	0x100003ccc <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x6c>
100003cb0: 68 02 40 f9 	ldr	x8, [x19]
100003cb4: 08 31 40 f9 	ldr	x8, [x8, #96]
100003cb8: e0 03 13 aa 	mov	x0, x19
100003cbc: e2 03 19 aa 	mov	x2, x25
100003cc0: 00 01 3f d6 	blr	x8
100003cc4: 1f 00 19 eb 	cmp	x0, x25
100003cc8: c1 06 00 54 	b.ne	0x100003da0 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x140>
100003ccc: ff 06 00 f1 	cmp	x23, #1
100003cd0: eb 04 00 54 	b.lt	0x100003d6c <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x10c>
100003cd4: ff 5e 00 f1 	cmp	x23, #23
100003cd8: 82 00 00 54 	b.hs	0x100003ce8 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x88>
100003cdc: f9 23 00 91 	add	x25, sp, #8
100003ce0: f7 7f 00 39 	strb	w23, [sp, #31]
100003ce4: 09 00 00 14 	b	0x100003d08 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xa8>
100003ce8: e8 42 00 91 	add	x8, x23, #16
100003cec: 1a ed 7c 92 	and	x26, x8, #0xfffffffffffffff0
100003cf0: e0 03 1a aa 	mov	x0, x26
100003cf4: 68 00 00 94 	bl	0x100003e94 <_memset+0x100003e94>
100003cf8: f9 03 00 aa 	mov	x25, x0
100003cfc: 48 03 41 b2 	orr	x8, x26, #0x8000000000000000
100003d00: f7 23 01 a9 	stp	x23, x8, [sp, #16]
100003d04: e0 07 00 f9 	str	x0, [sp, #8]
100003d08: e0 03 19 aa 	mov	x0, x25
100003d0c: e1 03 18 aa 	mov	x1, x24
100003d10: e2 03 17 aa 	mov	x2, x23
100003d14: 69 00 00 94 	bl	0x100003eb8 <_memset+0x100003eb8>
100003d18: 3f 6b 37 38 	strb	wzr, [x25, x23]
100003d1c: e8 7f c0 39 	ldrsb	w8, [sp, #31]
100003d20: e9 07 40 f9 	ldr	x9, [sp, #8]
100003d24: 1f 01 00 71 	cmp	w8, #0
100003d28: e8 23 00 91 	add	x8, sp, #8
100003d2c: 21 b1 88 9a 	csel	x1, x9, x8, lt
100003d30: 68 02 40 f9 	ldr	x8, [x19]
100003d34: 08 31 40 f9 	ldr	x8, [x8, #96]
100003d38: e0 03 13 aa 	mov	x0, x19
100003d3c: e2 03 17 aa 	mov	x2, x23
100003d40: 00 01 3f d6 	blr	x8
100003d44: f8 03 00 aa 	mov	x24, x0
100003d48: e8 7f c0 39 	ldrsb	w8, [sp, #31]
100003d4c: 88 00 f8 37 	tbnz	w8, #31, 0x100003d5c <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xfc>
100003d50: 1f 03 17 eb 	cmp	x24, x23
100003d54: 61 02 00 54 	b.ne	0x100003da0 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x140>
100003d58: 05 00 00 14 	b	0x100003d6c <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x10c>
100003d5c: e0 07 40 f9 	ldr	x0, [sp, #8]
100003d60: 4a 00 00 94 	bl	0x100003e88 <_memset+0x100003e88>
100003d64: 1f 03 17 eb 	cmp	x24, x23
100003d68: c1 01 00 54 	b.ne	0x100003da0 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x140>
100003d6c: d6 02 15 cb 	sub	x22, x22, x21
100003d70: df 06 00 f1 	cmp	x22, #1
100003d74: 2b 01 00 54 	b.lt	0x100003d98 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x138>
100003d78: 68 02 40 f9 	ldr	x8, [x19]
100003d7c: 08 31 40 f9 	ldr	x8, [x8, #96]
100003d80: e0 03 13 aa 	mov	x0, x19
100003d84: e1 03 15 aa 	mov	x1, x21
100003d88: e2 03 16 aa 	mov	x2, x22
100003d8c: 00 01 3f d6 	blr	x8
100003d90: 1f 00 16 eb 	cmp	x0, x22
100003d94: 61 00 00 54 	b.ne	0x100003da0 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x140>
100003d98: 9f 0e 00 f9 	str	xzr, [x20, #24]
100003d9c: 02 00 00 14 	b	0x100003da4 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x144>
100003da0: 13 00 80 d2 	mov	x19, #0
100003da4: e0 03 13 aa 	mov	x0, x19
100003da8: fd 7b 46 a9 	ldp	x29, x30, [sp, #96]
100003dac: f4 4f 45 a9 	ldp	x20, x19, [sp, #80]
100003db0: f6 57 44 a9 	ldp	x22, x21, [sp, #64]
100003db4: f8 5f 43 a9 	ldp	x24, x23, [sp, #48]
100003db8: fa 67 42 a9 	ldp	x26, x25, [sp, #32]
100003dbc: ff c3 01 91 	add	sp, sp, #112
100003dc0: c0 03 5f d6 	ret
100003dc4: f3 03 00 aa 	mov	x19, x0
100003dc8: e8 7f c0 39 	ldrsb	w8, [sp, #31]
100003dcc: 68 00 f8 36 	tbz	w8, #31, 0x100003dd8 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x178>
100003dd0: e0 07 40 f9 	ldr	x0, [sp, #8]
100003dd4: 2d 00 00 94 	bl	0x100003e88 <_memset+0x100003e88>
100003dd8: e0 03 13 aa 	mov	x0, x19
100003ddc: 04 00 00 94 	bl	0x100003dec <_memset+0x100003dec>

0000000100003de0 <___clang_call_terminate>:
100003de0: fd 7b bf a9 	stp	x29, x30, [sp, #-16]!
100003de4: 2f 00 00 94 	bl	0x100003ea0 <_memset+0x100003ea0>
100003de8: 25 00 00 94 	bl	0x100003e7c <_memset+0x100003e7c>

Disassembly of section __TEXT,__stubs:

0000000100003dec <__stubs>:
100003dec: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x4>
100003df0: 10 02 40 f9 	ldr	x16, [x16]
100003df4: 00 02 1f d6 	br	x16
100003df8: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x10>
100003dfc: 10 06 40 f9 	ldr	x16, [x16, #8]
100003e00: 00 02 1f d6 	br	x16
100003e04: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x1c>
100003e08: 10 0a 40 f9 	ldr	x16, [x16, #16]
100003e0c: 00 02 1f d6 	br	x16
100003e10: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x28>
100003e14: 10 0e 40 f9 	ldr	x16, [x16, #24]
100003e18: 00 02 1f d6 	br	x16
100003e1c: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x34>
100003e20: 10 12 40 f9 	ldr	x16, [x16, #32]
100003e24: 00 02 1f d6 	br	x16
100003e28: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x40>
100003e2c: 10 16 40 f9 	ldr	x16, [x16, #40]
100003e30: 00 02 1f d6 	br	x16
100003e34: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x4c>
100003e38: 10 1a 40 f9 	ldr	x16, [x16, #48]
100003e3c: 00 02 1f d6 	br	x16
100003e40: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x58>
100003e44: 10 1e 40 f9 	ldr	x16, [x16, #56]
100003e48: 00 02 1f d6 	br	x16
100003e4c: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x64>
100003e50: 10 2a 40 f9 	ldr	x16, [x16, #80]
100003e54: 00 02 1f d6 	br	x16
100003e58: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x70>
100003e5c: 10 2e 40 f9 	ldr	x16, [x16, #88]
100003e60: 00 02 1f d6 	br	x16
100003e64: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x7c>
100003e68: 10 32 40 f9 	ldr	x16, [x16, #96]
100003e6c: 00 02 1f d6 	br	x16
100003e70: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x88>
100003e74: 10 36 40 f9 	ldr	x16, [x16, #104]
100003e78: 00 02 1f d6 	br	x16
100003e7c: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x94>
100003e80: 10 3a 40 f9 	ldr	x16, [x16, #112]
100003e84: 00 02 1f d6 	br	x16
100003e88: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0xa0>
100003e8c: 10 3e 40 f9 	ldr	x16, [x16, #120]
100003e90: 00 02 1f d6 	br	x16
100003e94: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0xac>
100003e98: 10 42 40 f9 	ldr	x16, [x16, #128]
100003e9c: 00 02 1f d6 	br	x16
100003ea0: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0xb8>
100003ea4: 10 46 40 f9 	ldr	x16, [x16, #136]
100003ea8: 00 02 1f d6 	br	x16
100003eac: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0xc4>
100003eb0: 10 4a 40 f9 	ldr	x16, [x16, #144]
100003eb4: 00 02 1f d6 	br	x16
100003eb8: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0xd0>
100003ebc: 10 52 40 f9 	ldr	x16, [x16, #160]
100003ec0: 00 02 1f d6 	br	x16
