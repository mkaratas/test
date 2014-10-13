
test:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	insb   (%dx),%es:(%rdi)
  40023a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
  400241:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
  400246:	78 2d                	js     400275 <_init-0x11b>
  400248:	78 38                	js     400282 <_init-0x10e>
  40024a:	36                   	ss
  40024b:	2d 36 34 2e 73       	sub    $0x732e3436,%eax
  400250:	6f                   	outsl  %ds:(%rsi),(%dx)
  400251:	2e 32 00             	xor    %cs:(%rax),%al

Disassembly of section .note.ABI-tag:

0000000000400254 <.note.ABI-tag>:
  400254:	04 00                	add    $0x0,%al
  400256:	00 00                	add    %al,(%rax)
  400258:	10 00                	adc    %al,(%rax)
  40025a:	00 00                	add    %al,(%rax)
  40025c:	01 00                	add    %eax,(%rax)
  40025e:	00 00                	add    %al,(%rax)
  400260:	47                   	rex.RXB
  400261:	4e 55                	rex.WRX push %rbp
  400263:	00 00                	add    %al,(%rax)
  400265:	00 00                	add    %al,(%rax)
  400267:	00 02                	add    %al,(%rdx)
  400269:	00 00                	add    %al,(%rax)
  40026b:	00 06                	add    %al,(%rsi)
  40026d:	00 00                	add    %al,(%rax)
  40026f:	00 18                	add    %bl,(%rax)
  400271:	00 00                	add    %al,(%rax)
	...

Disassembly of section .note.gnu.build-id:

0000000000400274 <.note.gnu.build-id>:
  400274:	04 00                	add    $0x0,%al
  400276:	00 00                	add    %al,(%rax)
  400278:	14 00                	adc    $0x0,%al
  40027a:	00 00                	add    %al,(%rax)
  40027c:	03 00                	add    (%rax),%eax
  40027e:	00 00                	add    %al,(%rax)
  400280:	47                   	rex.RXB
  400281:	4e 55                	rex.WRX push %rbp
  400283:	00 fe                	add    %bh,%dh
  400285:	52                   	push   %rdx
  400286:	7c f4                	jl     40027c <_init-0x114>
  400288:	40 8c 99 17 f8 f7 1e 	rex mov %ds,0x1ef7f817(%rcx)
  40028f:	fe                   	(bad)  
  400290:	a3                   	.byte 0xa3
  400291:	f5                   	cmc    
  400292:	33 31                	xor    (%rcx),%esi
  400294:	c1                   	.byte 0xc1
  400295:	0c 0d                	or     $0xd,%al
  400297:	20                   	.byte 0x20

Disassembly of section .gnu.hash:

0000000000400298 <.gnu.hash>:
  400298:	01 00                	add    %eax,(%rax)
  40029a:	00 00                	add    %al,(%rax)
  40029c:	01 00                	add    %eax,(%rax)
  40029e:	00 00                	add    %al,(%rax)
  4002a0:	01 00                	add    %eax,(%rax)
	...

Disassembly of section .dynsym:

00000000004002b8 <.dynsym>:
	...
  4002d0:	1a 00                	sbb    (%rax),%al
  4002d2:	00 00                	add    %al,(%rax)
  4002d4:	12 00                	adc    (%rax),%al
	...
  4002e6:	00 00                	add    %al,(%rax)
  4002e8:	01 00                	add    %eax,(%rax)
  4002ea:	00 00                	add    %al,(%rax)
  4002ec:	20 00                	and    %al,(%rax)
	...

Disassembly of section .dynstr:

0000000000400300 <.dynstr>:
  400300:	00 5f 5f             	add    %bl,0x5f(%rdi)
  400303:	67 6d                	insl   (%dx),%es:(%edi)
  400305:	6f                   	outsl  %ds:(%rsi),(%dx)
  400306:	6e                   	outsb  %ds:(%rsi),(%dx)
  400307:	5f                   	pop    %rdi
  400308:	73 74                	jae    40037e <_init-0x12>
  40030a:	61                   	(bad)  
  40030b:	72 74                	jb     400381 <_init-0xf>
  40030d:	5f                   	pop    %rdi
  40030e:	5f                   	pop    %rdi
  40030f:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  400313:	63 2e                	movslq (%rsi),%ebp
  400315:	73 6f                	jae    400386 <_init-0xa>
  400317:	2e 36 00 5f 5f       	cs add %bl,%cs:%ss:0x5f(%rdi)
  40031c:	6c                   	insb   (%dx),%es:(%rdi)
  40031d:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
  400324:	72 74                	jb     40039a <_init+0xa>
  400326:	5f                   	pop    %rdi
  400327:	6d                   	insl   (%dx),%es:(%rdi)
  400328:	61                   	(bad)  
  400329:	69 6e 00 47 4c 49 42 	imul   $0x42494c47,0x0(%rsi),%ebp
  400330:	43 5f                	rex.XB pop %r15
  400332:	32 2e                	xor    (%rsi),%ch
  400334:	32 2e                	xor    (%rsi),%ch
  400336:	35                   	.byte 0x35
	...

Disassembly of section .gnu.version:

0000000000400338 <.gnu.version>:
  400338:	00 00                	add    %al,(%rax)
  40033a:	02 00                	add    (%rax),%al
	...

Disassembly of section .gnu.version_r:

0000000000400340 <.gnu.version_r>:
  400340:	01 00                	add    %eax,(%rax)
  400342:	01 00                	add    %eax,(%rax)
  400344:	10 00                	adc    %al,(%rax)
  400346:	00 00                	add    %al,(%rax)
  400348:	10 00                	adc    %al,(%rax)
  40034a:	00 00                	add    %al,(%rax)
  40034c:	00 00                	add    %al,(%rax)
  40034e:	00 00                	add    %al,(%rax)
  400350:	75 1a                	jne    40036c <_init-0x24>
  400352:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
  400358:	2c 00                	sub    $0x0,%al
  40035a:	00 00                	add    %al,(%rax)
  40035c:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

0000000000400360 <.rela.dyn>:
  400360:	e0 0f                	loopne 400371 <_init-0x1f>
  400362:	60                   	(bad)  
  400363:	00 00                	add    %al,(%rax)
  400365:	00 00                	add    %al,(%rax)
  400367:	00 06                	add    %al,(%rsi)
  400369:	00 00                	add    %al,(%rax)
  40036b:	00 02                	add    %al,(%rdx)
	...

Disassembly of section .rela.plt:

0000000000400378 <.rela.plt>:
  400378:	00 10                	add    %dl,(%rax)
  40037a:	60                   	(bad)  
  40037b:	00 00                	add    %al,(%rax)
  40037d:	00 00                	add    %al,(%rax)
  40037f:	00 07                	add    %al,(%rdi)
  400381:	00 00                	add    %al,(%rax)
  400383:	00 01                	add    %al,(%rcx)
	...

Disassembly of section .init:

0000000000400390 <_init>:
  400390:	48 83 ec 08          	sub    $0x8,%rsp
  400394:	e8 63 00 00 00       	callq  4003fc <call_gmon_start>
  400399:	e8 f2 00 00 00       	callq  400490 <frame_dummy>
  40039e:	e8 fd 01 00 00       	callq  4005a0 <__do_global_ctors_aux>
  4003a3:	48 83 c4 08          	add    $0x8,%rsp
  4003a7:	c3                   	retq   

Disassembly of section .plt:

00000000004003b0 <__libc_start_main@plt-0x10>:
  4003b0:	ff 35 3a 0c 20 00    	pushq  0x200c3a(%rip)        # 600ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
  4003b6:	ff 25 3c 0c 20 00    	jmpq   *0x200c3c(%rip)        # 600ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
  4003bc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004003c0 <__libc_start_main@plt>:
  4003c0:	ff 25 3a 0c 20 00    	jmpq   *0x200c3a(%rip)        # 601000 <_GLOBAL_OFFSET_TABLE_+0x18>
  4003c6:	68 00 00 00 00       	pushq  $0x0
  4003cb:	e9 e0 ff ff ff       	jmpq   4003b0 <_init+0x20>

Disassembly of section .text:

00000000004003d0 <_start>:
  4003d0:	31 ed                	xor    %ebp,%ebp
  4003d2:	49 89 d1             	mov    %rdx,%r9
  4003d5:	5e                   	pop    %rsi
  4003d6:	48 89 e2             	mov    %rsp,%rdx
  4003d9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4003dd:	50                   	push   %rax
  4003de:	54                   	push   %rsp
  4003df:	49 c7 c0 90 05 40 00 	mov    $0x400590,%r8
  4003e6:	48 c7 c1 00 05 40 00 	mov    $0x400500,%rcx
  4003ed:	48 c7 c7 d4 04 40 00 	mov    $0x4004d4,%rdi
  4003f4:	e8 c7 ff ff ff       	callq  4003c0 <__libc_start_main@plt>
  4003f9:	f4                   	hlt    
  4003fa:	90                   	nop
  4003fb:	90                   	nop

00000000004003fc <call_gmon_start>:
  4003fc:	48 83 ec 08          	sub    $0x8,%rsp
  400400:	48 8b 05 d9 0b 20 00 	mov    0x200bd9(%rip),%rax        # 600fe0 <_DYNAMIC+0x190>
  400407:	48 85 c0             	test   %rax,%rax
  40040a:	74 02                	je     40040e <call_gmon_start+0x12>
  40040c:	ff d0                	callq  *%rax
  40040e:	48 83 c4 08          	add    $0x8,%rsp
  400412:	c3                   	retq   
  400413:	90                   	nop
  400414:	90                   	nop
  400415:	90                   	nop
  400416:	90                   	nop
  400417:	90                   	nop
  400418:	90                   	nop
  400419:	90                   	nop
  40041a:	90                   	nop
  40041b:	90                   	nop
  40041c:	90                   	nop
  40041d:	90                   	nop
  40041e:	90                   	nop
  40041f:	90                   	nop

0000000000400420 <__do_global_dtors_aux>:
  400420:	55                   	push   %rbp
  400421:	48 89 e5             	mov    %rsp,%rbp
  400424:	53                   	push   %rbx
  400425:	48 83 ec 08          	sub    $0x8,%rsp
  400429:	80 3d e8 0b 20 00 00 	cmpb   $0x0,0x200be8(%rip)        # 601018 <__bss_start>
  400430:	75 4b                	jne    40047d <__do_global_dtors_aux+0x5d>
  400432:	bb 40 0e 60 00       	mov    $0x600e40,%ebx
  400437:	48 8b 05 e2 0b 20 00 	mov    0x200be2(%rip),%rax        # 601020 <dtor_idx.6533>
  40043e:	48 81 eb 38 0e 60 00 	sub    $0x600e38,%rbx
  400445:	48 c1 fb 03          	sar    $0x3,%rbx
  400449:	48 83 eb 01          	sub    $0x1,%rbx
  40044d:	48 39 d8             	cmp    %rbx,%rax
  400450:	73 24                	jae    400476 <__do_global_dtors_aux+0x56>
  400452:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  400458:	48 83 c0 01          	add    $0x1,%rax
  40045c:	48 89 05 bd 0b 20 00 	mov    %rax,0x200bbd(%rip)        # 601020 <dtor_idx.6533>
  400463:	ff 14 c5 38 0e 60 00 	callq  *0x600e38(,%rax,8)
  40046a:	48 8b 05 af 0b 20 00 	mov    0x200baf(%rip),%rax        # 601020 <dtor_idx.6533>
  400471:	48 39 d8             	cmp    %rbx,%rax
  400474:	72 e2                	jb     400458 <__do_global_dtors_aux+0x38>
  400476:	c6 05 9b 0b 20 00 01 	movb   $0x1,0x200b9b(%rip)        # 601018 <__bss_start>
  40047d:	48 83 c4 08          	add    $0x8,%rsp
  400481:	5b                   	pop    %rbx
  400482:	5d                   	pop    %rbp
  400483:	c3                   	retq   
  400484:	66 66 66 2e 0f 1f 84 	data32 data32 nopw %cs:0x0(%rax,%rax,1)
  40048b:	00 00 00 00 00 

0000000000400490 <frame_dummy>:
  400490:	48 83 3d b0 09 20 00 	cmpq   $0x0,0x2009b0(%rip)        # 600e48 <__JCR_END__>
  400497:	00 
  400498:	55                   	push   %rbp
  400499:	48 89 e5             	mov    %rsp,%rbp
  40049c:	74 12                	je     4004b0 <frame_dummy+0x20>
  40049e:	b8 00 00 00 00       	mov    $0x0,%eax
  4004a3:	48 85 c0             	test   %rax,%rax
  4004a6:	74 08                	je     4004b0 <frame_dummy+0x20>
  4004a8:	5d                   	pop    %rbp
  4004a9:	bf 48 0e 60 00       	mov    $0x600e48,%edi
  4004ae:	ff e0                	jmpq   *%rax
  4004b0:	5d                   	pop    %rbp
  4004b1:	c3                   	retq   
  4004b2:	90                   	nop
  4004b3:	90                   	nop

00000000004004b4 <funA>:
  4004b4:	55                   	push   %rbp
  4004b5:	48 89 e5             	mov    %rsp,%rbp
  4004b8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4004bc:	c7 00 14 00 00 00    	movl   $0x14,(%rax)
  4004c2:	5d                   	pop    %rbp
  4004c3:	c3                   	retq   

00000000004004c4 <funB>:
  4004c4:	55                   	push   %rbp
  4004c5:	48 89 e5             	mov    %rsp,%rbp
  4004c8:	b8 00 00 00 00       	mov    $0x0,%eax
  4004cd:	e8 e2 ff ff ff       	callq  4004b4 <funA>
  4004d2:	5d                   	pop    %rbp
  4004d3:	c3                   	retq   

00000000004004d4 <main>:
  4004d4:	55                   	push   %rbp
  4004d5:	48 89 e5             	mov    %rsp,%rbp
  4004d8:	48 83 ec 08          	sub    $0x8,%rsp
  4004dc:	89 7d fc             	mov    %edi,-0x4(%rbp)
  4004df:	89 f0                	mov    %esi,%eax
  4004e1:	88 45 f8             	mov    %al,-0x8(%rbp)
  4004e4:	b8 00 00 00 00       	mov    $0x0,%eax
  4004e9:	e8 d6 ff ff ff       	callq  4004c4 <funB>
  4004ee:	b8 00 00 00 00       	mov    $0x0,%eax
  4004f3:	c9                   	leaveq 
  4004f4:	c3                   	retq   
  4004f5:	90                   	nop
  4004f6:	90                   	nop
  4004f7:	90                   	nop
  4004f8:	90                   	nop
  4004f9:	90                   	nop
  4004fa:	90                   	nop
  4004fb:	90                   	nop
  4004fc:	90                   	nop
  4004fd:	90                   	nop
  4004fe:	90                   	nop
  4004ff:	90                   	nop

0000000000400500 <__libc_csu_init>:
  400500:	48 89 6c 24 d8       	mov    %rbp,-0x28(%rsp)
  400505:	4c 89 64 24 e0       	mov    %r12,-0x20(%rsp)
  40050a:	48 8d 2d 13 09 20 00 	lea    0x200913(%rip),%rbp        # 600e24 <__init_array_end>
  400511:	4c 8d 25 0c 09 20 00 	lea    0x20090c(%rip),%r12        # 600e24 <__init_array_end>
  400518:	4c 89 6c 24 e8       	mov    %r13,-0x18(%rsp)
  40051d:	4c 89 74 24 f0       	mov    %r14,-0x10(%rsp)
  400522:	4c 89 7c 24 f8       	mov    %r15,-0x8(%rsp)
  400527:	48 89 5c 24 d0       	mov    %rbx,-0x30(%rsp)
  40052c:	48 83 ec 38          	sub    $0x38,%rsp
  400530:	4c 29 e5             	sub    %r12,%rbp
  400533:	41 89 fd             	mov    %edi,%r13d
  400536:	49 89 f6             	mov    %rsi,%r14
  400539:	48 c1 fd 03          	sar    $0x3,%rbp
  40053d:	49 89 d7             	mov    %rdx,%r15
  400540:	e8 4b fe ff ff       	callq  400390 <_init>
  400545:	48 85 ed             	test   %rbp,%rbp
  400548:	74 1c                	je     400566 <__libc_csu_init+0x66>
  40054a:	31 db                	xor    %ebx,%ebx
  40054c:	0f 1f 40 00          	nopl   0x0(%rax)
  400550:	4c 89 fa             	mov    %r15,%rdx
  400553:	4c 89 f6             	mov    %r14,%rsi
  400556:	44 89 ef             	mov    %r13d,%edi
  400559:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40055d:	48 83 c3 01          	add    $0x1,%rbx
  400561:	48 39 eb             	cmp    %rbp,%rbx
  400564:	75 ea                	jne    400550 <__libc_csu_init+0x50>
  400566:	48 8b 5c 24 08       	mov    0x8(%rsp),%rbx
  40056b:	48 8b 6c 24 10       	mov    0x10(%rsp),%rbp
  400570:	4c 8b 64 24 18       	mov    0x18(%rsp),%r12
  400575:	4c 8b 6c 24 20       	mov    0x20(%rsp),%r13
  40057a:	4c 8b 74 24 28       	mov    0x28(%rsp),%r14
  40057f:	4c 8b 7c 24 30       	mov    0x30(%rsp),%r15
  400584:	48 83 c4 38          	add    $0x38,%rsp
  400588:	c3                   	retq   
  400589:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400590 <__libc_csu_fini>:
  400590:	f3 c3                	repz retq 
  400592:	90                   	nop
  400593:	90                   	nop
  400594:	90                   	nop
  400595:	90                   	nop
  400596:	90                   	nop
  400597:	90                   	nop
  400598:	90                   	nop
  400599:	90                   	nop
  40059a:	90                   	nop
  40059b:	90                   	nop
  40059c:	90                   	nop
  40059d:	90                   	nop
  40059e:	90                   	nop
  40059f:	90                   	nop

00000000004005a0 <__do_global_ctors_aux>:
  4005a0:	55                   	push   %rbp
  4005a1:	48 89 e5             	mov    %rsp,%rbp
  4005a4:	53                   	push   %rbx
  4005a5:	48 83 ec 08          	sub    $0x8,%rsp
  4005a9:	48 8b 05 78 08 20 00 	mov    0x200878(%rip),%rax        # 600e28 <__CTOR_LIST__>
  4005b0:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
  4005b4:	74 19                	je     4005cf <__do_global_ctors_aux+0x2f>
  4005b6:	bb 28 0e 60 00       	mov    $0x600e28,%ebx
  4005bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4005c0:	48 83 eb 08          	sub    $0x8,%rbx
  4005c4:	ff d0                	callq  *%rax
  4005c6:	48 8b 03             	mov    (%rbx),%rax
  4005c9:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
  4005cd:	75 f1                	jne    4005c0 <__do_global_ctors_aux+0x20>
  4005cf:	48 83 c4 08          	add    $0x8,%rsp
  4005d3:	5b                   	pop    %rbx
  4005d4:	5d                   	pop    %rbp
  4005d5:	c3                   	retq   
  4005d6:	90                   	nop
  4005d7:	90                   	nop

Disassembly of section .fini:

00000000004005d8 <_fini>:
  4005d8:	48 83 ec 08          	sub    $0x8,%rsp
  4005dc:	e8 3f fe ff ff       	callq  400420 <__do_global_dtors_aux>
  4005e1:	48 83 c4 08          	add    $0x8,%rsp
  4005e5:	c3                   	retq   

Disassembly of section .rodata:

00000000004005e8 <_IO_stdin_used>:
  4005e8:	01 00                	add    %eax,(%rax)
  4005ea:	02 00                	add    (%rax),%al

Disassembly of section .eh_frame_hdr:

00000000004005ec <.eh_frame_hdr>:
  4005ec:	01 1b                	add    %ebx,(%rbx)
  4005ee:	03 3b                	add    (%rbx),%edi
  4005f0:	38 00                	cmp    %al,(%rax)
  4005f2:	00 00                	add    %al,(%rax)
  4005f4:	06                   	(bad)  
  4005f5:	00 00                	add    %al,(%rax)
  4005f7:	00 c4                	add    %al,%ah
  4005f9:	fd                   	std    
  4005fa:	ff                   	(bad)  
  4005fb:	ff 54 00 00          	callq  *0x0(%rax,%rax,1)
  4005ff:	00 c8                	add    %cl,%al
  400601:	fe                   	(bad)  
  400602:	ff                   	(bad)  
  400603:	ff                   	(bad)  
  400604:	7c 00                	jl     400606 <_IO_stdin_used+0x1e>
  400606:	00 00                	add    %al,(%rax)
  400608:	d8 fe                	fdivr  %st(6),%st
  40060a:	ff                   	(bad)  
  40060b:	ff 9c 00 00 00 e8 fe 	lcallq *-0x1180000(%rax,%rax,1)
  400612:	ff                   	(bad)  
  400613:	ff                   	(bad)  
  400614:	bc 00 00 00 14       	mov    $0x14000000,%esp
  400619:	ff                   	(bad)  
  40061a:	ff                   	(bad)  
  40061b:	ff dc                	lcallq *<internal disassembler error>
  40061d:	00 00                	add    %al,(%rax)
  40061f:	00 a4 ff ff ff 04 01 	add    %ah,0x104ffff(%rdi,%rdi,8)
	...

Disassembly of section .eh_frame:

0000000000400628 <__FRAME_END__-0xe0>:
  400628:	14 00                	adc    $0x0,%al
  40062a:	00 00                	add    %al,(%rax)
  40062c:	00 00                	add    %al,(%rax)
  40062e:	00 00                	add    %al,(%rax)
  400630:	01 7a 52             	add    %edi,0x52(%rdx)
  400633:	00 01                	add    %al,(%rcx)
  400635:	78 10                	js     400647 <_IO_stdin_used+0x5f>
  400637:	01 1b                	add    %ebx,(%rbx)
  400639:	0c 07                	or     $0x7,%al
  40063b:	08 90 01 00 00 24    	or     %dl,0x24000001(%rax)
  400641:	00 00                	add    %al,(%rax)
  400643:	00 1c 00             	add    %bl,(%rax,%rax,1)
  400646:	00 00                	add    %al,(%rax)
  400648:	68 fd ff ff 20       	pushq  $0x20fffffd
  40064d:	00 00                	add    %al,(%rax)
  40064f:	00 00                	add    %al,(%rax)
  400651:	0e                   	(bad)  
  400652:	10 46 0e             	adc    %al,0xe(%rsi)
  400655:	18 4a 0f             	sbb    %cl,0xf(%rdx)
  400658:	0b 77 08             	or     0x8(%rdi),%esi
  40065b:	80 00 3f             	addb   $0x3f,(%rax)
  40065e:	1a 3b                	sbb    (%rbx),%bh
  400660:	2a 33                	sub    (%rbx),%dh
  400662:	24 22                	and    $0x22,%al
  400664:	00 00                	add    %al,(%rax)
  400666:	00 00                	add    %al,(%rax)
  400668:	1c 00                	sbb    $0x0,%al
  40066a:	00 00                	add    %al,(%rax)
  40066c:	44 00 00             	add    %r8b,(%rax)
  40066f:	00 44 fe ff          	add    %al,-0x1(%rsi,%rdi,8)
  400673:	ff 10                	callq  *(%rax)
  400675:	00 00                	add    %al,(%rax)
  400677:	00 00                	add    %al,(%rax)
  400679:	41 0e                	rex.B (bad) 
  40067b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  400681:	4b 0c 07             	rex.WXB or $0x7,%al
  400684:	08 00                	or     %al,(%rax)
  400686:	00 00                	add    %al,(%rax)
  400688:	1c 00                	sbb    $0x0,%al
  40068a:	00 00                	add    %al,(%rax)
  40068c:	64 00 00             	add    %al,%fs:(%rax)
  40068f:	00 34 fe             	add    %dh,(%rsi,%rdi,8)
  400692:	ff                   	(bad)  
  400693:	ff 10                	callq  *(%rax)
  400695:	00 00                	add    %al,(%rax)
  400697:	00 00                	add    %al,(%rax)
  400699:	41 0e                	rex.B (bad) 
  40069b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  4006a1:	4b 0c 07             	rex.WXB or $0x7,%al
  4006a4:	08 00                	or     %al,(%rax)
  4006a6:	00 00                	add    %al,(%rax)
  4006a8:	1c 00                	sbb    $0x0,%al
  4006aa:	00 00                	add    %al,(%rax)
  4006ac:	84 00                	test   %al,(%rax)
  4006ae:	00 00                	add    %al,(%rax)
  4006b0:	24 fe                	and    $0xfe,%al
  4006b2:	ff                   	(bad)  
  4006b3:	ff 21                	jmpq   *(%rcx)
  4006b5:	00 00                	add    %al,(%rax)
  4006b7:	00 00                	add    %al,(%rax)
  4006b9:	41 0e                	rex.B (bad) 
  4006bb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  4006c1:	5c                   	pop    %rsp
  4006c2:	0c 07                	or     $0x7,%al
  4006c4:	08 00                	or     %al,(%rax)
  4006c6:	00 00                	add    %al,(%rax)
  4006c8:	24 00                	and    $0x0,%al
  4006ca:	00 00                	add    %al,(%rax)
  4006cc:	a4                   	movsb  %ds:(%rsi),%es:(%rdi)
  4006cd:	00 00                	add    %al,(%rax)
  4006cf:	00 30                	add    %dh,(%rax)
  4006d1:	fe                   	(bad)  
  4006d2:	ff                   	(bad)  
  4006d3:	ff 89 00 00 00 00    	decl   0x0(%rcx)
  4006d9:	51                   	push   %rcx
  4006da:	8c 05 86 06 5f 0e    	mov    %es,0xe5f0686(%rip)        # e9f0d66 <_end+0xe3efd3e>
  4006e0:	40 83 07 8f          	rex addl $0xffffff8f,(%rdi)
  4006e4:	02 8e 03 8d 04 02    	add    0x2048d03(%rsi),%cl
  4006ea:	58                   	pop    %rax
  4006eb:	0e                   	(bad)  
  4006ec:	08 00                	or     %al,(%rax)
  4006ee:	00 00                	add    %al,(%rax)
  4006f0:	14 00                	adc    $0x0,%al
  4006f2:	00 00                	add    %al,(%rax)
  4006f4:	cc                   	int3   
  4006f5:	00 00                	add    %al,(%rax)
  4006f7:	00 98 fe ff ff 02    	add    %bl,0x2fffffe(%rax)
	...

0000000000400708 <__FRAME_END__>:
  400708:	00 00                	add    %al,(%rax)
	...

Disassembly of section .ctors:

0000000000600e28 <__CTOR_LIST__>:
  600e28:	ff                   	(bad)  
  600e29:	ff                   	(bad)  
  600e2a:	ff                   	(bad)  
  600e2b:	ff                   	(bad)  
  600e2c:	ff                   	(bad)  
  600e2d:	ff                   	(bad)  
  600e2e:	ff                   	(bad)  
  600e2f:	ff 00                	incl   (%rax)

0000000000600e30 <__CTOR_END__>:
	...

Disassembly of section .dtors:

0000000000600e38 <__DTOR_LIST__>:
  600e38:	ff                   	(bad)  
  600e39:	ff                   	(bad)  
  600e3a:	ff                   	(bad)  
  600e3b:	ff                   	(bad)  
  600e3c:	ff                   	(bad)  
  600e3d:	ff                   	(bad)  
  600e3e:	ff                   	(bad)  
  600e3f:	ff 00                	incl   (%rax)

0000000000600e40 <__DTOR_END__>:
	...

Disassembly of section .jcr:

0000000000600e48 <__JCR_END__>:
	...

Disassembly of section .dynamic:

0000000000600e50 <_DYNAMIC>:
  600e50:	01 00                	add    %eax,(%rax)
  600e52:	00 00                	add    %al,(%rax)
  600e54:	00 00                	add    %al,(%rax)
  600e56:	00 00                	add    %al,(%rax)
  600e58:	10 00                	adc    %al,(%rax)
  600e5a:	00 00                	add    %al,(%rax)
  600e5c:	00 00                	add    %al,(%rax)
  600e5e:	00 00                	add    %al,(%rax)
  600e60:	0c 00                	or     $0x0,%al
  600e62:	00 00                	add    %al,(%rax)
  600e64:	00 00                	add    %al,(%rax)
  600e66:	00 00                	add    %al,(%rax)
  600e68:	90                   	nop
  600e69:	03 40 00             	add    0x0(%rax),%eax
  600e6c:	00 00                	add    %al,(%rax)
  600e6e:	00 00                	add    %al,(%rax)
  600e70:	0d 00 00 00 00       	or     $0x0,%eax
  600e75:	00 00                	add    %al,(%rax)
  600e77:	00 d8                	add    %bl,%al
  600e79:	05 40 00 00 00       	add    $0x40,%eax
  600e7e:	00 00                	add    %al,(%rax)
  600e80:	f5                   	cmc    
  600e81:	fe                   	(bad)  
  600e82:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600e85:	00 00                	add    %al,(%rax)
  600e87:	00 98 02 40 00 00    	add    %bl,0x4002(%rax)
  600e8d:	00 00                	add    %al,(%rax)
  600e8f:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 600e95 <_DYNAMIC+0x45>
  600e95:	00 00                	add    %al,(%rax)
  600e97:	00 00                	add    %al,(%rax)
  600e99:	03 40 00             	add    0x0(%rax),%eax
  600e9c:	00 00                	add    %al,(%rax)
  600e9e:	00 00                	add    %al,(%rax)
  600ea0:	06                   	(bad)  
  600ea1:	00 00                	add    %al,(%rax)
  600ea3:	00 00                	add    %al,(%rax)
  600ea5:	00 00                	add    %al,(%rax)
  600ea7:	00 b8 02 40 00 00    	add    %bh,0x4002(%rax)
  600ead:	00 00                	add    %al,(%rax)
  600eaf:	00 0a                	add    %cl,(%rdx)
  600eb1:	00 00                	add    %al,(%rax)
  600eb3:	00 00                	add    %al,(%rax)
  600eb5:	00 00                	add    %al,(%rax)
  600eb7:	00 38                	add    %bh,(%rax)
  600eb9:	00 00                	add    %al,(%rax)
  600ebb:	00 00                	add    %al,(%rax)
  600ebd:	00 00                	add    %al,(%rax)
  600ebf:	00 0b                	add    %cl,(%rbx)
  600ec1:	00 00                	add    %al,(%rax)
  600ec3:	00 00                	add    %al,(%rax)
  600ec5:	00 00                	add    %al,(%rax)
  600ec7:	00 18                	add    %bl,(%rax)
  600ec9:	00 00                	add    %al,(%rax)
  600ecb:	00 00                	add    %al,(%rax)
  600ecd:	00 00                	add    %al,(%rax)
  600ecf:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 600ed5 <_DYNAMIC+0x85>
	...
  600edd:	00 00                	add    %al,(%rax)
  600edf:	00 03                	add    %al,(%rbx)
  600ee1:	00 00                	add    %al,(%rax)
  600ee3:	00 00                	add    %al,(%rax)
  600ee5:	00 00                	add    %al,(%rax)
  600ee7:	00 e8                	add    %ch,%al
  600ee9:	0f 60 00             	punpcklbw (%rax),%mm0
  600eec:	00 00                	add    %al,(%rax)
  600eee:	00 00                	add    %al,(%rax)
  600ef0:	02 00                	add    (%rax),%al
  600ef2:	00 00                	add    %al,(%rax)
  600ef4:	00 00                	add    %al,(%rax)
  600ef6:	00 00                	add    %al,(%rax)
  600ef8:	18 00                	sbb    %al,(%rax)
  600efa:	00 00                	add    %al,(%rax)
  600efc:	00 00                	add    %al,(%rax)
  600efe:	00 00                	add    %al,(%rax)
  600f00:	14 00                	adc    $0x0,%al
  600f02:	00 00                	add    %al,(%rax)
  600f04:	00 00                	add    %al,(%rax)
  600f06:	00 00                	add    %al,(%rax)
  600f08:	07                   	(bad)  
  600f09:	00 00                	add    %al,(%rax)
  600f0b:	00 00                	add    %al,(%rax)
  600f0d:	00 00                	add    %al,(%rax)
  600f0f:	00 17                	add    %dl,(%rdi)
  600f11:	00 00                	add    %al,(%rax)
  600f13:	00 00                	add    %al,(%rax)
  600f15:	00 00                	add    %al,(%rax)
  600f17:	00 78 03             	add    %bh,0x3(%rax)
  600f1a:	40 00 00             	add    %al,(%rax)
  600f1d:	00 00                	add    %al,(%rax)
  600f1f:	00 07                	add    %al,(%rdi)
  600f21:	00 00                	add    %al,(%rax)
  600f23:	00 00                	add    %al,(%rax)
  600f25:	00 00                	add    %al,(%rax)
  600f27:	00 60 03             	add    %ah,0x3(%rax)
  600f2a:	40 00 00             	add    %al,(%rax)
  600f2d:	00 00                	add    %al,(%rax)
  600f2f:	00 08                	add    %cl,(%rax)
  600f31:	00 00                	add    %al,(%rax)
  600f33:	00 00                	add    %al,(%rax)
  600f35:	00 00                	add    %al,(%rax)
  600f37:	00 18                	add    %bl,(%rax)
  600f39:	00 00                	add    %al,(%rax)
  600f3b:	00 00                	add    %al,(%rax)
  600f3d:	00 00                	add    %al,(%rax)
  600f3f:	00 09                	add    %cl,(%rcx)
  600f41:	00 00                	add    %al,(%rax)
  600f43:	00 00                	add    %al,(%rax)
  600f45:	00 00                	add    %al,(%rax)
  600f47:	00 18                	add    %bl,(%rax)
  600f49:	00 00                	add    %al,(%rax)
  600f4b:	00 00                	add    %al,(%rax)
  600f4d:	00 00                	add    %al,(%rax)
  600f4f:	00 fe                	add    %bh,%dh
  600f51:	ff                   	(bad)  
  600f52:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600f55:	00 00                	add    %al,(%rax)
  600f57:	00 40 03             	add    %al,0x3(%rax)
  600f5a:	40 00 00             	add    %al,(%rax)
  600f5d:	00 00                	add    %al,(%rax)
  600f5f:	00 ff                	add    %bh,%bh
  600f61:	ff                   	(bad)  
  600f62:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600f65:	00 00                	add    %al,(%rax)
  600f67:	00 01                	add    %al,(%rcx)
  600f69:	00 00                	add    %al,(%rax)
  600f6b:	00 00                	add    %al,(%rax)
  600f6d:	00 00                	add    %al,(%rax)
  600f6f:	00 f0                	add    %dh,%al
  600f71:	ff                   	(bad)  
  600f72:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600f75:	00 00                	add    %al,(%rax)
  600f77:	00 38                	add    %bh,(%rax)
  600f79:	03 40 00             	add    0x0(%rax),%eax
	...

Disassembly of section .got:

0000000000600fe0 <.got>:
	...

Disassembly of section .got.plt:

0000000000600fe8 <_GLOBAL_OFFSET_TABLE_>:
  600fe8:	50                   	push   %rax
  600fe9:	0e                   	(bad)  
  600fea:	60                   	(bad)  
	...
  600fff:	00 c6                	add    %al,%dh
  601001:	03 40 00             	add    0x0(%rax),%eax
  601004:	00 00                	add    %al,(%rax)
	...

Disassembly of section .data:

0000000000601008 <__data_start>:
	...

0000000000601010 <__dso_handle>:
	...

Disassembly of section .bss:

0000000000601018 <completed.6531>:
	...

0000000000601020 <dtor_idx.6533>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <_init-0x400318>
   a:	74 75                	je     81 <_init-0x40030f>
   c:	2f                   	(bad)  
   d:	4c 69 6e 61 72 6f 20 	imul   $0x34206f72,0x61(%rsi),%r13
  14:	34 
  15:	2e 36 2e 33 2d 31 75 	cs ss xor %cs:%ss:0x75627531(%rip),%ebp        # 7562754f <_end+0x75026527>
  1c:	62 75 
  1e:	6e                   	outsb  %ds:(%rsi),(%dx)
  1f:	74 75                	je     96 <_init-0x4002fa>
  21:	35 29 20 34 2e       	xor    $0x2e342029,%eax
  26:	36 2e 33 00          	ss xor %cs:%ss:(%rax),%eax
