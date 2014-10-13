
test:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	insb   (%dx),%es:(%rdi)
  40023a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
  400241:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
  400246:	78 2d                	js     400275 <_init-0x153>
  400248:	78 38                	js     400282 <_init-0x146>
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
  400283:	00 91 49 e2 dd f3    	add    %dl,-0xc221db7(%rcx)
  400289:	3c 7e                	cmp    $0x7e,%al
  40028b:	6a 77                	pushq  $0x77
  40028d:	77 15                	ja     4002a4 <_init-0x124>
  40028f:	44 fe                	rex.R (bad) 
  400291:	56                   	push   %rsi
  400292:	c9                   	leaveq 
  400293:	5e                   	pop    %rsi
  400294:	32                   	.byte 0x32
  400295:	81                   	.byte 0x81
  400296:	21                   	.byte 0x21
  400297:	5c                   	pop    %rsp

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
  4002e8:	21 00                	and    %eax,(%rax)
  4002ea:	00 00                	add    %al,(%rax)
  4002ec:	12 00                	adc    (%rax),%al
	...
  4002fe:	00 00                	add    %al,(%rax)
  400300:	01 00                	add    %eax,(%rax)
  400302:	00 00                	add    %al,(%rax)
  400304:	20 00                	and    %al,(%rax)
	...

Disassembly of section .dynstr:

0000000000400318 <.dynstr>:
  400318:	00 5f 5f             	add    %bl,0x5f(%rdi)
  40031b:	67 6d                	insl   (%dx),%es:(%edi)
  40031d:	6f                   	outsl  %ds:(%rsi),(%dx)
  40031e:	6e                   	outsb  %ds:(%rsi),(%dx)
  40031f:	5f                   	pop    %rdi
  400320:	73 74                	jae    400396 <_init-0x32>
  400322:	61                   	(bad)  
  400323:	72 74                	jb     400399 <_init-0x2f>
  400325:	5f                   	pop    %rdi
  400326:	5f                   	pop    %rdi
  400327:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  40032b:	63 2e                	movslq (%rsi),%ebp
  40032d:	73 6f                	jae    40039e <_init-0x2a>
  40032f:	2e 36 00 70 72       	cs add %dh,%cs:%ss:0x72(%rax)
  400334:	69 6e 74 66 00 5f 5f 	imul   $0x5f5f0066,0x74(%rsi),%ebp
  40033b:	6c                   	insb   (%dx),%es:(%rdi)
  40033c:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
  400343:	72 74                	jb     4003b9 <_init-0xf>
  400345:	5f                   	pop    %rdi
  400346:	6d                   	insl   (%dx),%es:(%rdi)
  400347:	61                   	(bad)  
  400348:	69 6e 00 47 4c 49 42 	imul   $0x42494c47,0x0(%rsi),%ebp
  40034f:	43 5f                	rex.XB pop %r15
  400351:	32 2e                	xor    (%rsi),%ch
  400353:	32 2e                	xor    (%rsi),%ch
  400355:	35                   	.byte 0x35
	...

Disassembly of section .gnu.version:

0000000000400358 <.gnu.version>:
  400358:	00 00                	add    %al,(%rax)
  40035a:	02 00                	add    (%rax),%al
  40035c:	02 00                	add    (%rax),%al
	...

Disassembly of section .gnu.version_r:

0000000000400360 <.gnu.version_r>:
  400360:	01 00                	add    %eax,(%rax)
  400362:	01 00                	add    %eax,(%rax)
  400364:	10 00                	adc    %al,(%rax)
  400366:	00 00                	add    %al,(%rax)
  400368:	10 00                	adc    %al,(%rax)
  40036a:	00 00                	add    %al,(%rax)
  40036c:	00 00                	add    %al,(%rax)
  40036e:	00 00                	add    %al,(%rax)
  400370:	75 1a                	jne    40038c <_init-0x3c>
  400372:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
  400378:	33 00                	xor    (%rax),%eax
  40037a:	00 00                	add    %al,(%rax)
  40037c:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

0000000000400380 <.rela.dyn>:
  400380:	e0 0f                	loopne 400391 <_init-0x37>
  400382:	60                   	(bad)  
  400383:	00 00                	add    %al,(%rax)
  400385:	00 00                	add    %al,(%rax)
  400387:	00 06                	add    %al,(%rsi)
  400389:	00 00                	add    %al,(%rax)
  40038b:	00 03                	add    %al,(%rbx)
	...

Disassembly of section .rela.plt:

0000000000400398 <.rela.plt>:
  400398:	00 10                	add    %dl,(%rax)
  40039a:	60                   	(bad)  
  40039b:	00 00                	add    %al,(%rax)
  40039d:	00 00                	add    %al,(%rax)
  40039f:	00 07                	add    %al,(%rdi)
  4003a1:	00 00                	add    %al,(%rax)
  4003a3:	00 01                	add    %al,(%rcx)
	...
  4003ad:	00 00                	add    %al,(%rax)
  4003af:	00 08                	add    %cl,(%rax)
  4003b1:	10 60 00             	adc    %ah,0x0(%rax)
  4003b4:	00 00                	add    %al,(%rax)
  4003b6:	00 00                	add    %al,(%rax)
  4003b8:	07                   	(bad)  
  4003b9:	00 00                	add    %al,(%rax)
  4003bb:	00 02                	add    %al,(%rdx)
	...

Disassembly of section .init:

00000000004003c8 <_init>:
  4003c8:	48 83 ec 08          	sub    $0x8,%rsp
  4003cc:	e8 6b 00 00 00       	callq  40043c <call_gmon_start>
  4003d1:	e8 fa 00 00 00       	callq  4004d0 <frame_dummy>
  4003d6:	e8 25 02 00 00       	callq  400600 <__do_global_ctors_aux>
  4003db:	48 83 c4 08          	add    $0x8,%rsp
  4003df:	c3                   	retq   

Disassembly of section .plt:

00000000004003e0 <printf@plt-0x10>:
  4003e0:	ff 35 0a 0c 20 00    	pushq  0x200c0a(%rip)        # 600ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
  4003e6:	ff 25 0c 0c 20 00    	jmpq   *0x200c0c(%rip)        # 600ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
  4003ec:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004003f0 <printf@plt>:
  4003f0:	ff 25 0a 0c 20 00    	jmpq   *0x200c0a(%rip)        # 601000 <_GLOBAL_OFFSET_TABLE_+0x18>
  4003f6:	68 00 00 00 00       	pushq  $0x0
  4003fb:	e9 e0 ff ff ff       	jmpq   4003e0 <_init+0x18>

0000000000400400 <__libc_start_main@plt>:
  400400:	ff 25 02 0c 20 00    	jmpq   *0x200c02(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x20>
  400406:	68 01 00 00 00       	pushq  $0x1
  40040b:	e9 d0 ff ff ff       	jmpq   4003e0 <_init+0x18>

Disassembly of section .text:

0000000000400410 <_start>:
  400410:	31 ed                	xor    %ebp,%ebp
  400412:	49 89 d1             	mov    %rdx,%r9
  400415:	5e                   	pop    %rsi
  400416:	48 89 e2             	mov    %rsp,%rdx
  400419:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40041d:	50                   	push   %rax
  40041e:	54                   	push   %rsp
  40041f:	49 c7 c0 f0 05 40 00 	mov    $0x4005f0,%r8
  400426:	48 c7 c1 60 05 40 00 	mov    $0x400560,%rcx
  40042d:	48 c7 c7 26 05 40 00 	mov    $0x400526,%rdi
  400434:	e8 c7 ff ff ff       	callq  400400 <__libc_start_main@plt>
  400439:	f4                   	hlt    
  40043a:	90                   	nop
  40043b:	90                   	nop

000000000040043c <call_gmon_start>:
  40043c:	48 83 ec 08          	sub    $0x8,%rsp
  400440:	48 8b 05 99 0b 20 00 	mov    0x200b99(%rip),%rax        # 600fe0 <_DYNAMIC+0x190>
  400447:	48 85 c0             	test   %rax,%rax
  40044a:	74 02                	je     40044e <call_gmon_start+0x12>
  40044c:	ff d0                	callq  *%rax
  40044e:	48 83 c4 08          	add    $0x8,%rsp
  400452:	c3                   	retq   
  400453:	90                   	nop
  400454:	90                   	nop
  400455:	90                   	nop
  400456:	90                   	nop
  400457:	90                   	nop
  400458:	90                   	nop
  400459:	90                   	nop
  40045a:	90                   	nop
  40045b:	90                   	nop
  40045c:	90                   	nop
  40045d:	90                   	nop
  40045e:	90                   	nop
  40045f:	90                   	nop

0000000000400460 <__do_global_dtors_aux>:
  400460:	55                   	push   %rbp
  400461:	48 89 e5             	mov    %rsp,%rbp
  400464:	53                   	push   %rbx
  400465:	48 83 ec 08          	sub    $0x8,%rsp
  400469:	80 3d b0 0b 20 00 00 	cmpb   $0x0,0x200bb0(%rip)        # 601020 <__bss_start>
  400470:	75 4b                	jne    4004bd <__do_global_dtors_aux+0x5d>
  400472:	bb 40 0e 60 00       	mov    $0x600e40,%ebx
  400477:	48 8b 05 aa 0b 20 00 	mov    0x200baa(%rip),%rax        # 601028 <dtor_idx.6533>
  40047e:	48 81 eb 38 0e 60 00 	sub    $0x600e38,%rbx
  400485:	48 c1 fb 03          	sar    $0x3,%rbx
  400489:	48 83 eb 01          	sub    $0x1,%rbx
  40048d:	48 39 d8             	cmp    %rbx,%rax
  400490:	73 24                	jae    4004b6 <__do_global_dtors_aux+0x56>
  400492:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  400498:	48 83 c0 01          	add    $0x1,%rax
  40049c:	48 89 05 85 0b 20 00 	mov    %rax,0x200b85(%rip)        # 601028 <dtor_idx.6533>
  4004a3:	ff 14 c5 38 0e 60 00 	callq  *0x600e38(,%rax,8)
  4004aa:	48 8b 05 77 0b 20 00 	mov    0x200b77(%rip),%rax        # 601028 <dtor_idx.6533>
  4004b1:	48 39 d8             	cmp    %rbx,%rax
  4004b4:	72 e2                	jb     400498 <__do_global_dtors_aux+0x38>
  4004b6:	c6 05 63 0b 20 00 01 	movb   $0x1,0x200b63(%rip)        # 601020 <__bss_start>
  4004bd:	48 83 c4 08          	add    $0x8,%rsp
  4004c1:	5b                   	pop    %rbx
  4004c2:	5d                   	pop    %rbp
  4004c3:	c3                   	retq   
  4004c4:	66 66 66 2e 0f 1f 84 	data32 data32 nopw %cs:0x0(%rax,%rax,1)
  4004cb:	00 00 00 00 00 

00000000004004d0 <frame_dummy>:
  4004d0:	48 83 3d 70 09 20 00 	cmpq   $0x0,0x200970(%rip)        # 600e48 <__JCR_END__>
  4004d7:	00 
  4004d8:	55                   	push   %rbp
  4004d9:	48 89 e5             	mov    %rsp,%rbp
  4004dc:	74 12                	je     4004f0 <frame_dummy+0x20>
  4004de:	b8 00 00 00 00       	mov    $0x0,%eax
  4004e3:	48 85 c0             	test   %rax,%rax
  4004e6:	74 08                	je     4004f0 <frame_dummy+0x20>
  4004e8:	5d                   	pop    %rbp
  4004e9:	bf 48 0e 60 00       	mov    $0x600e48,%edi
  4004ee:	ff e0                	jmpq   *%rax
  4004f0:	5d                   	pop    %rbp
  4004f1:	c3                   	retq   
  4004f2:	90                   	nop
  4004f3:	90                   	nop

00000000004004f4 <B>:
  4004f4:	55                   	push   %rbp
  4004f5:	48 89 e5             	mov    %rsp,%rbp
  4004f8:	89 7d ec             	mov    %edi,-0x14(%rbp)
  4004fb:	89 75 e8             	mov    %esi,-0x18(%rbp)
  4004fe:	8b 45 fc             	mov    -0x4(%rbp),%eax
  400501:	5d                   	pop    %rbp
  400502:	c3                   	retq   

0000000000400503 <A>:
  400503:	55                   	push   %rbp
  400504:	48 89 e5             	mov    %rsp,%rbp
  400507:	48 83 ec 08          	sub    $0x8,%rsp
  40050b:	89 fa                	mov    %edi,%edx
  40050d:	89 f0                	mov    %esi,%eax
  40050f:	88 55 fc             	mov    %dl,-0x4(%rbp)
  400512:	88 45 f8             	mov    %al,-0x8(%rbp)
  400515:	be 05 00 00 00       	mov    $0x5,%esi
  40051a:	bf 03 00 00 00       	mov    $0x3,%edi
  40051f:	e8 d0 ff ff ff       	callq  4004f4 <B>
  400524:	c9                   	leaveq 
  400525:	c3                   	retq   

0000000000400526 <main>:
  400526:	55                   	push   %rbp
  400527:	48 89 e5             	mov    %rsp,%rbp
  40052a:	48 83 ec 10          	sub    $0x10,%rsp
  40052e:	be 6a 00 00 00       	mov    $0x6a,%esi
  400533:	bf 63 00 00 00       	mov    $0x63,%edi
  400538:	e8 c6 ff ff ff       	callq  400503 <A>
  40053d:	89 45 fc             	mov    %eax,-0x4(%rbp)
  400540:	b8 4c 06 40 00       	mov    $0x40064c,%eax
  400545:	8b 55 fc             	mov    -0x4(%rbp),%edx
  400548:	89 d6                	mov    %edx,%esi
  40054a:	48 89 c7             	mov    %rax,%rdi
  40054d:	b8 00 00 00 00       	mov    $0x0,%eax
  400552:	e8 99 fe ff ff       	callq  4003f0 <printf@plt>
  400557:	b8 00 00 00 00       	mov    $0x0,%eax
  40055c:	c9                   	leaveq 
  40055d:	c3                   	retq   
  40055e:	90                   	nop
  40055f:	90                   	nop

0000000000400560 <__libc_csu_init>:
  400560:	48 89 6c 24 d8       	mov    %rbp,-0x28(%rsp)
  400565:	4c 89 64 24 e0       	mov    %r12,-0x20(%rsp)
  40056a:	48 8d 2d b3 08 20 00 	lea    0x2008b3(%rip),%rbp        # 600e24 <__init_array_end>
  400571:	4c 8d 25 ac 08 20 00 	lea    0x2008ac(%rip),%r12        # 600e24 <__init_array_end>
  400578:	4c 89 6c 24 e8       	mov    %r13,-0x18(%rsp)
  40057d:	4c 89 74 24 f0       	mov    %r14,-0x10(%rsp)
  400582:	4c 89 7c 24 f8       	mov    %r15,-0x8(%rsp)
  400587:	48 89 5c 24 d0       	mov    %rbx,-0x30(%rsp)
  40058c:	48 83 ec 38          	sub    $0x38,%rsp
  400590:	4c 29 e5             	sub    %r12,%rbp
  400593:	41 89 fd             	mov    %edi,%r13d
  400596:	49 89 f6             	mov    %rsi,%r14
  400599:	48 c1 fd 03          	sar    $0x3,%rbp
  40059d:	49 89 d7             	mov    %rdx,%r15
  4005a0:	e8 23 fe ff ff       	callq  4003c8 <_init>
  4005a5:	48 85 ed             	test   %rbp,%rbp
  4005a8:	74 1c                	je     4005c6 <__libc_csu_init+0x66>
  4005aa:	31 db                	xor    %ebx,%ebx
  4005ac:	0f 1f 40 00          	nopl   0x0(%rax)
  4005b0:	4c 89 fa             	mov    %r15,%rdx
  4005b3:	4c 89 f6             	mov    %r14,%rsi
  4005b6:	44 89 ef             	mov    %r13d,%edi
  4005b9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4005bd:	48 83 c3 01          	add    $0x1,%rbx
  4005c1:	48 39 eb             	cmp    %rbp,%rbx
  4005c4:	75 ea                	jne    4005b0 <__libc_csu_init+0x50>
  4005c6:	48 8b 5c 24 08       	mov    0x8(%rsp),%rbx
  4005cb:	48 8b 6c 24 10       	mov    0x10(%rsp),%rbp
  4005d0:	4c 8b 64 24 18       	mov    0x18(%rsp),%r12
  4005d5:	4c 8b 6c 24 20       	mov    0x20(%rsp),%r13
  4005da:	4c 8b 74 24 28       	mov    0x28(%rsp),%r14
  4005df:	4c 8b 7c 24 30       	mov    0x30(%rsp),%r15
  4005e4:	48 83 c4 38          	add    $0x38,%rsp
  4005e8:	c3                   	retq   
  4005e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004005f0 <__libc_csu_fini>:
  4005f0:	f3 c3                	repz retq 
  4005f2:	90                   	nop
  4005f3:	90                   	nop
  4005f4:	90                   	nop
  4005f5:	90                   	nop
  4005f6:	90                   	nop
  4005f7:	90                   	nop
  4005f8:	90                   	nop
  4005f9:	90                   	nop
  4005fa:	90                   	nop
  4005fb:	90                   	nop
  4005fc:	90                   	nop
  4005fd:	90                   	nop
  4005fe:	90                   	nop
  4005ff:	90                   	nop

0000000000400600 <__do_global_ctors_aux>:
  400600:	55                   	push   %rbp
  400601:	48 89 e5             	mov    %rsp,%rbp
  400604:	53                   	push   %rbx
  400605:	48 83 ec 08          	sub    $0x8,%rsp
  400609:	48 8b 05 18 08 20 00 	mov    0x200818(%rip),%rax        # 600e28 <__CTOR_LIST__>
  400610:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
  400614:	74 19                	je     40062f <__do_global_ctors_aux+0x2f>
  400616:	bb 28 0e 60 00       	mov    $0x600e28,%ebx
  40061b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400620:	48 83 eb 08          	sub    $0x8,%rbx
  400624:	ff d0                	callq  *%rax
  400626:	48 8b 03             	mov    (%rbx),%rax
  400629:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
  40062d:	75 f1                	jne    400620 <__do_global_ctors_aux+0x20>
  40062f:	48 83 c4 08          	add    $0x8,%rsp
  400633:	5b                   	pop    %rbx
  400634:	5d                   	pop    %rbp
  400635:	c3                   	retq   
  400636:	90                   	nop
  400637:	90                   	nop

Disassembly of section .fini:

0000000000400638 <_fini>:
  400638:	48 83 ec 08          	sub    $0x8,%rsp
  40063c:	e8 1f fe ff ff       	callq  400460 <__do_global_dtors_aux>
  400641:	48 83 c4 08          	add    $0x8,%rsp
  400645:	c3                   	retq   

Disassembly of section .rodata:

0000000000400648 <_IO_stdin_used>:
  400648:	01 00                	add    %eax,(%rax)
  40064a:	02 00                	add    (%rax),%al
  40064c:	61                   	(bad)  
  40064d:	20 3d 20 25 64 0a    	and    %bh,0xa642520(%rip)        # aa42b73 <_end+0xa441b43>
	...

Disassembly of section .eh_frame_hdr:

0000000000400654 <.eh_frame_hdr>:
  400654:	01 1b                	add    %ebx,(%rbx)
  400656:	03 3b                	add    (%rbx),%edi
  400658:	38 00                	cmp    %al,(%rax)
  40065a:	00 00                	add    %al,(%rax)
  40065c:	06                   	(bad)  
  40065d:	00 00                	add    %al,(%rax)
  40065f:	00 8c fd ff ff 54 00 	add    %cl,0x54ffff(%rbp,%rdi,8)
  400666:	00 00                	add    %al,(%rax)
  400668:	a0 fe ff ff 7c 00 00 	movabs 0xaf0000007cfffffe,%al
  40066f:	00 af 
  400671:	fe                   	(bad)  
  400672:	ff                   	(bad)  
  400673:	ff 9c 00 00 00 d2 fe 	lcallq *-0x12e0000(%rax,%rax,1)
  40067a:	ff                   	(bad)  
  40067b:	ff                   	(bad)  
  40067c:	bc 00 00 00 0c       	mov    $0xc000000,%esp
  400681:	ff                   	(bad)  
  400682:	ff                   	(bad)  
  400683:	ff dc                	lcallq *<internal disassembler error>
  400685:	00 00                	add    %al,(%rax)
  400687:	00 9c ff ff ff 04 01 	add    %bl,0x104ffff(%rdi,%rdi,8)
	...

Disassembly of section .eh_frame:

0000000000400690 <__FRAME_END__-0xe0>:
  400690:	14 00                	adc    $0x0,%al
  400692:	00 00                	add    %al,(%rax)
  400694:	00 00                	add    %al,(%rax)
  400696:	00 00                	add    %al,(%rax)
  400698:	01 7a 52             	add    %edi,0x52(%rdx)
  40069b:	00 01                	add    %al,(%rcx)
  40069d:	78 10                	js     4006af <_IO_stdin_used+0x67>
  40069f:	01 1b                	add    %ebx,(%rbx)
  4006a1:	0c 07                	or     $0x7,%al
  4006a3:	08 90 01 00 00 24    	or     %dl,0x24000001(%rax)
  4006a9:	00 00                	add    %al,(%rax)
  4006ab:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4006ae:	00 00                	add    %al,(%rax)
  4006b0:	30 fd                	xor    %bh,%ch
  4006b2:	ff                   	(bad)  
  4006b3:	ff 30                	pushq  (%rax)
  4006b5:	00 00                	add    %al,(%rax)
  4006b7:	00 00                	add    %al,(%rax)
  4006b9:	0e                   	(bad)  
  4006ba:	10 46 0e             	adc    %al,0xe(%rsi)
  4006bd:	18 4a 0f             	sbb    %cl,0xf(%rdx)
  4006c0:	0b 77 08             	or     0x8(%rdi),%esi
  4006c3:	80 00 3f             	addb   $0x3f,(%rax)
  4006c6:	1a 3b                	sbb    (%rbx),%bh
  4006c8:	2a 33                	sub    (%rbx),%dh
  4006ca:	24 22                	and    $0x22,%al
  4006cc:	00 00                	add    %al,(%rax)
  4006ce:	00 00                	add    %al,(%rax)
  4006d0:	1c 00                	sbb    $0x0,%al
  4006d2:	00 00                	add    %al,(%rax)
  4006d4:	44 00 00             	add    %r8b,(%rax)
  4006d7:	00 1c fe             	add    %bl,(%rsi,%rdi,8)
  4006da:	ff                   	(bad)  
  4006db:	ff 0f                	decl   (%rdi)
  4006dd:	00 00                	add    %al,(%rax)
  4006df:	00 00                	add    %al,(%rax)
  4006e1:	41 0e                	rex.B (bad) 
  4006e3:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  4006e9:	4a 0c 07             	rex.WX or $0x7,%al
  4006ec:	08 00                	or     %al,(%rax)
  4006ee:	00 00                	add    %al,(%rax)
  4006f0:	1c 00                	sbb    $0x0,%al
  4006f2:	00 00                	add    %al,(%rax)
  4006f4:	64 00 00             	add    %al,%fs:(%rax)
  4006f7:	00 0b                	add    %cl,(%rbx)
  4006f9:	fe                   	(bad)  
  4006fa:	ff                   	(bad)  
  4006fb:	ff 23                	jmpq   *(%rbx)
  4006fd:	00 00                	add    %al,(%rax)
  4006ff:	00 00                	add    %al,(%rax)
  400701:	41 0e                	rex.B (bad) 
  400703:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  400709:	5e                   	pop    %rsi
  40070a:	0c 07                	or     $0x7,%al
  40070c:	08 00                	or     %al,(%rax)
  40070e:	00 00                	add    %al,(%rax)
  400710:	1c 00                	sbb    $0x0,%al
  400712:	00 00                	add    %al,(%rax)
  400714:	84 00                	test   %al,(%rax)
  400716:	00 00                	add    %al,(%rax)
  400718:	0e                   	(bad)  
  400719:	fe                   	(bad)  
  40071a:	ff                   	(bad)  
  40071b:	ff                   	(bad)  
  40071c:	38 00                	cmp    %al,(%rax)
  40071e:	00 00                	add    %al,(%rax)
  400720:	00 41 0e             	add    %al,0xe(%rcx)
  400723:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  400729:	73 0c                	jae    400737 <_IO_stdin_used+0xef>
  40072b:	07                   	(bad)  
  40072c:	08 00                	or     %al,(%rax)
  40072e:	00 00                	add    %al,(%rax)
  400730:	24 00                	and    $0x0,%al
  400732:	00 00                	add    %al,(%rax)
  400734:	a4                   	movsb  %ds:(%rsi),%es:(%rdi)
  400735:	00 00                	add    %al,(%rax)
  400737:	00 28                	add    %ch,(%rax)
  400739:	fe                   	(bad)  
  40073a:	ff                   	(bad)  
  40073b:	ff 89 00 00 00 00    	decl   0x0(%rcx)
  400741:	51                   	push   %rcx
  400742:	8c 05 86 06 5f 0e    	mov    %es,0xe5f0686(%rip)        # e9f0dce <_end+0xe3efd9e>
  400748:	40 83 07 8f          	rex addl $0xffffff8f,(%rdi)
  40074c:	02 8e 03 8d 04 02    	add    0x2048d03(%rsi),%cl
  400752:	58                   	pop    %rax
  400753:	0e                   	(bad)  
  400754:	08 00                	or     %al,(%rax)
  400756:	00 00                	add    %al,(%rax)
  400758:	14 00                	adc    $0x0,%al
  40075a:	00 00                	add    %al,(%rax)
  40075c:	cc                   	int3   
  40075d:	00 00                	add    %al,(%rax)
  40075f:	00 90 fe ff ff 02    	add    %dl,0x2fffffe(%rax)
	...

0000000000400770 <__FRAME_END__>:
  400770:	00 00                	add    %al,(%rax)
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
  600e68:	c8 03 40 00          	enterq $0x4003,$0x0
  600e6c:	00 00                	add    %al,(%rax)
  600e6e:	00 00                	add    %al,(%rax)
  600e70:	0d 00 00 00 00       	or     $0x0,%eax
  600e75:	00 00                	add    %al,(%rax)
  600e77:	00 38                	add    %bh,(%rax)
  600e79:	06                   	(bad)  
  600e7a:	40 00 00             	add    %al,(%rax)
  600e7d:	00 00                	add    %al,(%rax)
  600e7f:	00 f5                	add    %dh,%ch
  600e81:	fe                   	(bad)  
  600e82:	ff 6f 00             	ljmpq  *0x0(%rdi)
  600e85:	00 00                	add    %al,(%rax)
  600e87:	00 98 02 40 00 00    	add    %bl,0x4002(%rax)
  600e8d:	00 00                	add    %al,(%rax)
  600e8f:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 600e95 <_DYNAMIC+0x45>
  600e95:	00 00                	add    %al,(%rax)
  600e97:	00 18                	add    %bl,(%rax)
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
  600eb7:	00 3f                	add    %bh,(%rdi)
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
  600ef8:	30 00                	xor    %al,(%rax)
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
  600f17:	00 98 03 40 00 00    	add    %bl,0x4003(%rax)
  600f1d:	00 00                	add    %al,(%rax)
  600f1f:	00 07                	add    %al,(%rdi)
  600f21:	00 00                	add    %al,(%rax)
  600f23:	00 00                	add    %al,(%rax)
  600f25:	00 00                	add    %al,(%rax)
  600f27:	00 80 03 40 00 00    	add    %al,0x4003(%rax)
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
  600f57:	00 60 03             	add    %ah,0x3(%rax)
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
  600f77:	00 58 03             	add    %bl,0x3(%rax)
  600f7a:	40 00 00             	add    %al,(%rax)
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
  600fff:	00 f6                	add    %dh,%dh
  601001:	03 40 00             	add    0x0(%rax),%eax
  601004:	00 00                	add    %al,(%rax)
  601006:	00 00                	add    %al,(%rax)
  601008:	06                   	(bad)  
  601009:	04 40                	add    $0x40,%al
  60100b:	00 00                	add    %al,(%rax)
  60100d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .data:

0000000000601010 <__data_start>:
	...

0000000000601018 <__dso_handle>:
	...

Disassembly of section .bss:

0000000000601020 <completed.6531>:
	...

0000000000601028 <dtor_idx.6533>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <_init-0x400350>
   a:	74 75                	je     81 <_init-0x400347>
   c:	2f                   	(bad)  
   d:	4c 69 6e 61 72 6f 20 	imul   $0x34206f72,0x61(%rsi),%r13
  14:	34 
  15:	2e 36 2e 33 2d 31 75 	cs ss xor %cs:%ss:0x75627531(%rip),%ebp        # 7562754f <_end+0x7502651f>
  1c:	62 75 
  1e:	6e                   	outsb  %ds:(%rsi),(%dx)
  1f:	74 75                	je     96 <_init-0x400332>
  21:	35 29 20 34 2e       	xor    $0x2e342029,%eax
  26:	36 2e 33 00          	ss xor %cs:%ss:(%rax),%eax

Disassembly of section .debug_aranges:

0000000000000000 <.debug_aranges>:
   0:	2c 00                	sub    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	02 00                	add    (%rax),%al
   6:	00 00                	add    %al,(%rax)
   8:	00 00                	add    %al,(%rax)
   a:	08 00                	or     %al,(%rax)
   c:	00 00                	add    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	f4                   	hlt    
  11:	04 40                	add    $0x40,%al
  13:	00 00                	add    %al,(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	00 6a 00             	add    %ch,0x0(%rdx)
	...

Disassembly of section .debug_info:

0000000000000000 <.debug_info>:
   0:	1a 01                	sbb    (%rcx),%al
   2:	00 00                	add    %al,(%rax)
   4:	02 00                	add    (%rax),%al
   6:	00 00                	add    %al,(%rax)
   8:	00 00                	add    %al,(%rax)
   a:	08 01                	or     %al,(%rcx)
   c:	48 00 00             	rex.W add %al,(%rax)
   f:	00 01                	add    %al,(%rcx)
  11:	38 00                	cmp    %al,(%rax)
  13:	00 00                	add    %al,(%rax)
  15:	54                   	push   %rsp
  16:	00 00                	add    %al,(%rax)
  18:	00 f4                	add    %dh,%ah
  1a:	04 40                	add    $0x40,%al
  1c:	00 00                	add    %al,(%rax)
  1e:	00 00                	add    %al,(%rax)
  20:	00 5e 05             	add    %bl,0x5(%rsi)
  23:	40 00 00             	add    %al,(%rax)
  26:	00 00                	add    %al,(%rax)
  28:	00 00                	add    %al,(%rax)
  2a:	00 00                	add    %al,(%rax)
  2c:	00 02                	add    %al,(%rdx)
  2e:	08 07                	or     %al,(%rdi)
  30:	13 00                	adc    (%rax),%eax
  32:	00 00                	add    %al,(%rax)
  34:	02 01                	add    (%rcx),%al
  36:	08 25 00 00 00 02    	or     %ah,0x2000000(%rip)        # 200003c <_end+0x19ff00c>
  3c:	02 07                	add    (%rdi),%al
  3e:	00 00                	add    %al,(%rax)
  40:	00 00                	add    %al,(%rax)
  42:	02 04 07             	add    (%rdi,%rax,1),%al
  45:	18 00                	sbb    %al,(%rax)
  47:	00 00                	add    %al,(%rax)
  49:	02 01                	add    (%rcx),%al
  4b:	06                   	(bad)  
  4c:	27                   	(bad)  
  4d:	00 00                	add    %al,(%rax)
  4f:	00 02                	add    %al,(%rdx)
  51:	02 05 7e 00 00 00    	add    0x7e(%rip),%al        # d5 <_init-0x4002f3>
  57:	03 04 05 69 6e 74 00 	add    0x746e69(,%rax,1),%eax
  5e:	02 08                	add    (%rax),%cl
  60:	05 3f 00 00 00       	add    $0x3f,%eax
  65:	02 01                	add    (%rcx),%al
  67:	06                   	(bad)  
  68:	2e 00 00             	add    %al,%cs:(%rax)
  6b:	00 04 01             	add    %al,(%rcx,%rax,1)
  6e:	42 00 01             	rex.X add %al,(%rcx)
  71:	03 01                	add    (%rcx),%eax
  73:	57                   	push   %rdi
  74:	00 00                	add    %al,(%rax)
  76:	00 f4                	add    %dh,%ah
  78:	04 40                	add    $0x40,%al
  7a:	00 00                	add    %al,(%rax)
  7c:	00 00                	add    %al,(%rax)
  7e:	00 03                	add    %al,(%rbx)
  80:	05 40 00 00 00       	add    $0x40,%eax
  85:	00 00                	add    %al,(%rax)
  87:	00 00                	add    %al,(%rax)
  89:	00 00                	add    %al,(%rax)
  8b:	b4 00                	mov    $0x0,%ah
  8d:	00 00                	add    %al,(%rax)
  8f:	05 61 00 01 03       	add    $0x3010061,%eax
  94:	57                   	push   %rdi
  95:	00 00                	add    %al,(%rax)
  97:	00 02                	add    %al,(%rdx)
  99:	91                   	xchg   %eax,%ecx
  9a:	5c                   	pop    %rsp
  9b:	05 62 00 01 03       	add    $0x3010062,%eax
  a0:	57                   	push   %rdi
  a1:	00 00                	add    %al,(%rax)
  a3:	00 02                	add    %al,(%rdx)
  a5:	91                   	xchg   %eax,%ecx
  a6:	58                   	pop    %rax
  a7:	06                   	(bad)  
  a8:	63 00                	movslq (%rax),%eax
  aa:	01 05 57 00 00 00    	add    %eax,0x57(%rip)        # 107 <_init-0x4002c1>
  b0:	02 91 6c 00 04 01    	add    0x104006c(%rcx),%dl
  b6:	41 00 01             	add    %al,(%r9)
  b9:	0a 01                	or     (%rcx),%al
  bb:	57                   	push   %rdi
  bc:	00 00                	add    %al,(%rax)
  be:	00 03                	add    %al,(%rbx)
  c0:	05 40 00 00 00       	add    $0x40,%eax
  c5:	00 00                	add    %al,(%rax)
  c7:	26                   	es
  c8:	05 40 00 00 00       	add    $0x40,%eax
  cd:	00 00                	add    %al,(%rax)
  cf:	60                   	(bad)  
  d0:	00 00                	add    %al,(%rax)
  d2:	00 f0                	add    %dh,%al
  d4:	00 00                	add    %al,(%rax)
  d6:	00 05 61 00 01 0a    	add    %al,0xa010061(%rip)        # a01013d <_end+0x9a0f10d>
  dc:	65 00 00             	add    %al,%gs:(%rax)
  df:	00 02                	add    %al,(%rdx)
  e1:	91                   	xchg   %eax,%ecx
  e2:	6c                   	insb   (%dx),%es:(%rdi)
  e3:	05 62 00 01 0a       	add    $0xa010062,%eax
  e8:	65 00 00             	add    %al,%gs:(%rax)
  eb:	00 02                	add    %al,(%rdx)
  ed:	91                   	xchg   %eax,%ecx
  ee:	68 00 07 01 33       	pushq  $0x33010700
  f3:	00 00                	add    %al,(%rax)
  f5:	00 01                	add    %al,(%rcx)
  f7:	0f 57 00             	xorps  (%rax),%xmm0
  fa:	00 00                	add    %al,(%rax)
  fc:	26                   	es
  fd:	05 40 00 00 00       	add    $0x40,%eax
 102:	00 00                	add    %al,(%rax)
 104:	5e                   	pop    %rsi
 105:	05 40 00 00 00       	add    $0x40,%eax
 10a:	00 00                	add    %al,(%rax)
 10c:	c0 00 00             	rolb   $0x0,(%rax)
 10f:	00 06                	add    %al,(%rsi)
 111:	61                   	(bad)  
 112:	00 01                	add    %al,(%rcx)
 114:	11 57 00             	adc    %edx,0x0(%rdi)
 117:	00 00                	add    %al,(%rax)
 119:	02                   	.byte 0x2
 11a:	91                   	xchg   %eax,%ecx
 11b:	6c                   	insb   (%dx),%es:(%rdi)
	...

Disassembly of section .debug_abbrev:

0000000000000000 <.debug_abbrev>:
   0:	01 11                	add    %edx,(%rcx)
   2:	01 25 0e 13 0b 03    	add    %esp,0x30b130e(%rip)        # 30b1316 <_end+0x2ab02e6>
   8:	0e                   	(bad)  
   9:	1b 0e                	sbb    (%rsi),%ecx
   b:	11 01                	adc    %eax,(%rcx)
   d:	12 01                	adc    (%rcx),%al
   f:	10 06                	adc    %al,(%rsi)
  11:	00 00                	add    %al,(%rax)
  13:	02 24 00             	add    (%rax,%rax,1),%ah
  16:	0b 0b                	or     (%rbx),%ecx
  18:	3e 0b 03             	or     %ds:(%rbx),%eax
  1b:	0e                   	(bad)  
  1c:	00 00                	add    %al,(%rax)
  1e:	03 24 00             	add    (%rax,%rax,1),%esp
  21:	0b 0b                	or     (%rbx),%ecx
  23:	3e 0b 03             	or     %ds:(%rbx),%eax
  26:	08 00                	or     %al,(%rax)
  28:	00 04 2e             	add    %al,(%rsi,%rbp,1)
  2b:	01 3f                	add    %edi,(%rdi)
  2d:	0c 03                	or     $0x3,%al
  2f:	08 3a                	or     %bh,(%rdx)
  31:	0b 3b                	or     (%rbx),%edi
  33:	0b 27                	or     (%rdi),%esp
  35:	0c 49                	or     $0x49,%al
  37:	13 11                	adc    (%rcx),%edx
  39:	01 12                	add    %edx,(%rdx)
  3b:	01 40 06             	add    %eax,0x6(%rax)
  3e:	01 13                	add    %edx,(%rbx)
  40:	00 00                	add    %al,(%rax)
  42:	05 05 00 03 08       	add    $0x8030005,%eax
  47:	3a 0b                	cmp    (%rbx),%cl
  49:	3b 0b                	cmp    (%rbx),%ecx
  4b:	49 13 02             	adc    (%r10),%rax
  4e:	0a 00                	or     (%rax),%al
  50:	00 06                	add    %al,(%rsi)
  52:	34 00                	xor    $0x0,%al
  54:	03 08                	add    (%rax),%ecx
  56:	3a 0b                	cmp    (%rbx),%cl
  58:	3b 0b                	cmp    (%rbx),%ecx
  5a:	49 13 02             	adc    (%r10),%rax
  5d:	0a 00                	or     (%rax),%al
  5f:	00 07                	add    %al,(%rdi)
  61:	2e 01 3f             	add    %edi,%cs:(%rdi)
  64:	0c 03                	or     $0x3,%al
  66:	0e                   	(bad)  
  67:	3a 0b                	cmp    (%rbx),%cl
  69:	3b 0b                	cmp    (%rbx),%ecx
  6b:	49 13 11             	adc    (%r9),%rdx
  6e:	01 12                	add    %edx,(%rdx)
  70:	01 40 06             	add    %eax,0x6(%rax)
  73:	00 00                	add    %al,(%rax)
	...

Disassembly of section .debug_line:

0000000000000000 <.debug_line>:
   0:	41 00 00             	add    %al,(%r8)
   3:	00 02                	add    %al,(%rdx)
   5:	00 1d 00 00 00 01    	add    %bl,0x1000000(%rip)        # 100000b <_end+0x9fefdb>
   b:	01 fb                	add    %edi,%ebx
   d:	0e                   	(bad)  
   e:	0d 00 01 01 01       	or     $0x1010100,%eax
  13:	01 00                	add    %eax,(%rax)
  15:	00 00                	add    %al,(%rax)
  17:	01 00                	add    %eax,(%rax)
  19:	00 01                	add    %al,(%rcx)
  1b:	00 74 65 73          	add    %dh,0x73(%rbp,%riz,2)
  1f:	74 2e                	je     4f <_init-0x400379>
  21:	63 00                	movslq (%rax),%eax
  23:	00 00                	add    %al,(%rax)
  25:	00 00                	add    %al,(%rax)
  27:	00 09                	add    %cl,(%rcx)
  29:	02 f4                	add    %ah,%dh
  2b:	04 40                	add    $0x40,%al
  2d:	00 00                	add    %al,(%rax)
  2f:	00 00                	add    %al,(%rax)
  31:	00 15 a1 3d 31 08    	add    %dl,0x8313da1(%rip)        # 8313dd8 <_end+0x7d12da8>
  37:	21 e5                	and    %esp,%ebp
  39:	31 84 08 21 08 68 59 	xor    %eax,0x59680821(%rax,%rcx,1)
  40:	02 02                	add    (%rdx),%al
  42:	00 01                	add    %al,(%rcx)
  44:	01                   	.byte 0x1

Disassembly of section .debug_str:

0000000000000000 <.debug_str>:
   0:	73 68                	jae    6a <_init-0x40035e>
   2:	6f                   	outsl  %ds:(%rsi),(%dx)
   3:	72 74                	jb     79 <_init-0x40034f>
   5:	20 75 6e             	and    %dh,0x6e(%rbp)
   8:	73 69                	jae    73 <_init-0x400355>
   a:	67 6e                	outsb  %ds:(%esi),(%dx)
   c:	65 64 20 69 6e       	gs and %ch,%fs:%gs:0x6e(%rcx)
  11:	74 00                	je     13 <_init-0x4003b5>
  13:	6c                   	insb   (%dx),%es:(%rdi)
  14:	6f                   	outsl  %ds:(%rsi),(%dx)
  15:	6e                   	outsb  %ds:(%rsi),(%dx)
  16:	67 20 75 6e          	and    %dh,0x6e(%ebp)
  1a:	73 69                	jae    85 <_init-0x400343>
  1c:	67 6e                	outsb  %ds:(%esi),(%dx)
  1e:	65 64 20 69 6e       	gs and %ch,%fs:%gs:0x6e(%rcx)
  23:	74 00                	je     25 <_init-0x4003a3>
  25:	75 6e                	jne    95 <_init-0x400333>
  27:	73 69                	jae    92 <_init-0x400336>
  29:	67 6e                	outsb  %ds:(%esi),(%dx)
  2b:	65 64 20 63 68       	gs and %ah,%fs:%gs:0x68(%rbx)
  30:	61                   	(bad)  
  31:	72 00                	jb     33 <_init-0x400395>
  33:	6d                   	insl   (%dx),%es:(%rdi)
  34:	61                   	(bad)  
  35:	69 6e 00 74 65 73 74 	imul   $0x74736574,0x0(%rsi),%ebp
  3c:	2e 63 00             	movslq %cs:(%rax),%eax
  3f:	6c                   	insb   (%dx),%es:(%rdi)
  40:	6f                   	outsl  %ds:(%rsi),(%dx)
  41:	6e                   	outsb  %ds:(%rsi),(%dx)
  42:	67 20 69 6e          	and    %ch,0x6e(%ecx)
  46:	74 00                	je     48 <_init-0x400380>
  48:	47                   	rex.RXB
  49:	4e 55                	rex.WRX push %rbp
  4b:	20 43 20             	and    %al,0x20(%rbx)
  4e:	34 2e                	xor    $0x2e,%al
  50:	36 2e 33 00          	ss xor %cs:%ss:(%rax),%eax
  54:	2f                   	(bad)  
  55:	68 6f 6d 65 2f       	pushq  $0x2f656d6f
  5a:	43                   	rex.XB
  5b:	4f 52                	rex.WRXB push %r10
  5d:	50                   	push   %rax
  5e:	55                   	push   %rbp
  5f:	53                   	push   %rbx
  60:	45 52                	rex.RB push %r10
  62:	53                   	push   %rbx
  63:	2f                   	(bad)  
  64:	78 70                	js     d6 <_init-0x4002f2>
  66:	30 31                	xor    %dh,(%rcx)
  68:	34 37                	xor    $0x37,%al
  6a:	32 31                	xor    (%rcx),%dh
  6c:	2f                   	(bad)  
  6d:	44                   	rex.R
  6e:	65                   	gs
  6f:	73 6b                	jae    dc <_init-0x4002ec>
  71:	74 6f                	je     e2 <_init-0x4002e6>
  73:	70 2f                	jo     a4 <_init-0x400324>
  75:	74 65                	je     dc <_init-0x4002ec>
  77:	73 74                	jae    ed <_init-0x4002db>
  79:	2f                   	(bad)  
  7a:	61                   	(bad)  
  7b:	73 6d                	jae    ea <_init-0x4002de>
  7d:	00 73 68             	add    %dh,0x68(%rbx)
  80:	6f                   	outsl  %ds:(%rsi),(%dx)
  81:	72 74                	jb     f7 <_init-0x4002d1>
  83:	20 69 6e             	and    %ch,0x6e(%rcx)
  86:	74 00                	je     88 <_init-0x400340>

Disassembly of section .debug_loc:

0000000000000000 <.debug_loc>:
	...
   8:	01 00                	add    %eax,(%rax)
   a:	00 00                	add    %al,(%rax)
   c:	00 00                	add    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	02 00                	add    (%rax),%al
  12:	77 08                	ja     1c <_init-0x4003ac>
  14:	01 00                	add    %eax,(%rax)
  16:	00 00                	add    %al,(%rax)
  18:	00 00                	add    %al,(%rax)
  1a:	00 00                	add    %al,(%rax)
  1c:	04 00                	add    $0x0,%al
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	02 00                	add    (%rax),%al
  26:	77 10                	ja     38 <_init-0x400390>
  28:	04 00                	add    $0x0,%al
  2a:	00 00                	add    %al,(%rax)
  2c:	00 00                	add    %al,(%rax)
  2e:	00 00                	add    %al,(%rax)
  30:	0e                   	(bad)  
  31:	00 00                	add    %al,(%rax)
  33:	00 00                	add    %al,(%rax)
  35:	00 00                	add    %al,(%rax)
  37:	00 02                	add    %al,(%rdx)
  39:	00 76 10             	add    %dh,0x10(%rsi)
  3c:	0e                   	(bad)  
  3d:	00 00                	add    %al,(%rax)
  3f:	00 00                	add    %al,(%rax)
  41:	00 00                	add    %al,(%rax)
  43:	00 0f                	add    %cl,(%rdi)
  45:	00 00                	add    %al,(%rax)
  47:	00 00                	add    %al,(%rax)
  49:	00 00                	add    %al,(%rax)
  4b:	00 02                	add    %al,(%rdx)
  4d:	00 77 08             	add    %dh,0x8(%rdi)
	...
  60:	0f 00 00             	sldt   (%rax)
  63:	00 00                	add    %al,(%rax)
  65:	00 00                	add    %al,(%rax)
  67:	00 10                	add    %dl,(%rax)
  69:	00 00                	add    %al,(%rax)
  6b:	00 00                	add    %al,(%rax)
  6d:	00 00                	add    %al,(%rax)
  6f:	00 02                	add    %al,(%rdx)
  71:	00 77 08             	add    %dh,0x8(%rdi)
  74:	10 00                	adc    %al,(%rax)
  76:	00 00                	add    %al,(%rax)
  78:	00 00                	add    %al,(%rax)
  7a:	00 00                	add    %al,(%rax)
  7c:	13 00                	adc    (%rax),%eax
  7e:	00 00                	add    %al,(%rax)
  80:	00 00                	add    %al,(%rax)
  82:	00 00                	add    %al,(%rax)
  84:	02 00                	add    (%rax),%al
  86:	77 10                	ja     98 <_init-0x400330>
  88:	13 00                	adc    (%rax),%eax
  8a:	00 00                	add    %al,(%rax)
  8c:	00 00                	add    %al,(%rax)
  8e:	00 00                	add    %al,(%rax)
  90:	31 00                	xor    %eax,(%rax)
  92:	00 00                	add    %al,(%rax)
  94:	00 00                	add    %al,(%rax)
  96:	00 00                	add    %al,(%rax)
  98:	02 00                	add    (%rax),%al
  9a:	76 10                	jbe    ac <_init-0x40031c>
  9c:	31 00                	xor    %eax,(%rax)
  9e:	00 00                	add    %al,(%rax)
  a0:	00 00                	add    %al,(%rax)
  a2:	00 00                	add    %al,(%rax)
  a4:	32 00                	xor    (%rax),%al
  a6:	00 00                	add    %al,(%rax)
  a8:	00 00                	add    %al,(%rax)
  aa:	00 00                	add    %al,(%rax)
  ac:	02 00                	add    (%rax),%al
  ae:	77 08                	ja     b8 <_init-0x400310>
	...
  c0:	32 00                	xor    (%rax),%al
  c2:	00 00                	add    %al,(%rax)
  c4:	00 00                	add    %al,(%rax)
  c6:	00 00                	add    %al,(%rax)
  c8:	33 00                	xor    (%rax),%eax
  ca:	00 00                	add    %al,(%rax)
  cc:	00 00                	add    %al,(%rax)
  ce:	00 00                	add    %al,(%rax)
  d0:	02 00                	add    (%rax),%al
  d2:	77 08                	ja     dc <_init-0x4002ec>
  d4:	33 00                	xor    (%rax),%eax
  d6:	00 00                	add    %al,(%rax)
  d8:	00 00                	add    %al,(%rax)
  da:	00 00                	add    %al,(%rax)
  dc:	36 00 00             	add    %al,%ss:(%rax)
  df:	00 00                	add    %al,(%rax)
  e1:	00 00                	add    %al,(%rax)
  e3:	00 02                	add    %al,(%rdx)
  e5:	00 77 10             	add    %dh,0x10(%rdi)
  e8:	36 00 00             	add    %al,%ss:(%rax)
  eb:	00 00                	add    %al,(%rax)
  ed:	00 00                	add    %al,(%rax)
  ef:	00 69 00             	add    %ch,0x0(%rcx)
  f2:	00 00                	add    %al,(%rax)
  f4:	00 00                	add    %al,(%rax)
  f6:	00 00                	add    %al,(%rax)
  f8:	02 00                	add    (%rax),%al
  fa:	76 10                	jbe    10c <_init-0x4002bc>
  fc:	69 00 00 00 00 00    	imul   $0x0,(%rax),%eax
 102:	00 00                	add    %al,(%rax)
 104:	6a 00                	pushq  $0x0
 106:	00 00                	add    %al,(%rax)
 108:	00 00                	add    %al,(%rax)
 10a:	00 00                	add    %al,(%rax)
 10c:	02 00                	add    (%rax),%al
 10e:	77 08                	ja     118 <_init-0x4002b0>
	...
