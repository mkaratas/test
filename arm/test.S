
test.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <hello>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e24dd008 	sub	sp, sp, #8
   c:	e50b0008 	str	r0, [fp, #-8]
  10:	e50b100c 	str	r1, [fp, #-12]
  14:	e3a00003 	mov	r0, #3
  18:	e3a01005 	mov	r1, #5
  1c:	ebfffffe 	bl	30 <good>
  20:	e3a03000 	mov	r3, #0
  24:	e1a00003 	mov	r0, r3
  28:	e24bd004 	sub	sp, fp, #4
  2c:	e8bd8800 	pop	{fp, pc}

00000030 <good>:
  30:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  34:	e28db000 	add	fp, sp, #0
  38:	e24dd01c 	sub	sp, sp, #28
  3c:	e50b0018 	str	r0, [fp, #-24]
  40:	e50b101c 	str	r1, [fp, #-28]
  44:	e59f301c 	ldr	r3, [pc, #28]	; 68 <good+0x38>
  48:	e50b3010 	str	r3, [fp, #-16]
  4c:	e3a03000 	mov	r3, #0
  50:	e50b300c 	str	r3, [fp, #-12]
  54:	e3a03000 	mov	r3, #0
  58:	e14b30b8 	strh	r3, [fp, #-8]
  5c:	e28bd000 	add	sp, fp, #0
  60:	e8bd0800 	ldmfd	sp!, {fp}
  64:	e12fff1e 	bx	lr
  68:	007a6a63 	rsbseq	r6, sl, r3, ror #20

0000006c <main>:
  6c:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  70:	e28db000 	add	fp, sp, #0
  74:	e3a03000 	mov	r3, #0
  78:	e1a00003 	mov	r0, r3
  7c:	e28bd000 	add	sp, fp, #0
  80:	e8bd0800 	ldmfd	sp!, {fp}
  84:	e12fff1e 	bx	lr

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	00372e34 	eorseq	r2, r7, r4, lsr lr

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002a41 	andeq	r2, r0, r1, asr #20
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000020 	andeq	r0, r0, r0, lsr #32
  10:	45543505 	ldrbmi	r3, [r4, #-1285]	; 0x505
  14:	08040600 	stmdaeq	r4, {r9, sl}
  18:	12010901 	andne	r0, r1, #16384	; 0x4000
  1c:	15011404 	strne	r1, [r1, #-1028]	; 0x404
  20:	18031701 	stmdane	r3, {r0, r8, r9, sl, ip}
  24:	1a011901 	bne	46430 <main+0x463c4>
  28:	Address 0x0000000000000028 is out of bounds.

