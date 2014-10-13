
test.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <B>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	89 7d ec             	mov    %edi,-0x14(%rbp)
   7:	89 75 e8             	mov    %esi,-0x18(%rbp)
   a:	8b 45 fc             	mov    -0x4(%rbp),%eax
   d:	5d                   	pop    %rbp
   e:	c3                   	retq   

000000000000000f <A>:
   f:	55                   	push   %rbp
  10:	48 89 e5             	mov    %rsp,%rbp
  13:	48 83 ec 08          	sub    $0x8,%rsp
  17:	89 fa                	mov    %edi,%edx
  19:	89 f0                	mov    %esi,%eax
  1b:	88 55 fc             	mov    %dl,-0x4(%rbp)
  1e:	88 45 f8             	mov    %al,-0x8(%rbp)
  21:	be 05 00 00 00       	mov    $0x5,%esi
  26:	bf 03 00 00 00       	mov    $0x3,%edi
  2b:	e8 00 00 00 00       	callq  30 <A+0x21>
  30:	c9                   	leaveq 
  31:	c3                   	retq   

0000000000000032 <main>:
  32:	55                   	push   %rbp
  33:	48 89 e5             	mov    %rsp,%rbp
  36:	48 83 ec 10          	sub    $0x10,%rsp
  3a:	be 6a 00 00 00       	mov    $0x6a,%esi
  3f:	bf 63 00 00 00       	mov    $0x63,%edi
  44:	e8 00 00 00 00       	callq  49 <main+0x17>
  49:	89 45 fc             	mov    %eax,-0x4(%rbp)
  4c:	b8 00 00 00 00       	mov    $0x0,%eax
  51:	8b 55 fc             	mov    -0x4(%rbp),%edx
  54:	89 d6                	mov    %edx,%esi
  56:	48 89 c7             	mov    %rax,%rdi
  59:	b8 00 00 00 00       	mov    $0x0,%eax
  5e:	e8 00 00 00 00       	callq  63 <main+0x31>
  63:	b8 00 00 00 00       	mov    $0x0,%eax
  68:	c9                   	leaveq 
  69:	c3                   	retq   

Disassembly of section .rodata:

0000000000000000 <.rodata>:
   0:	61                   	(bad)  
   1:	20 3d 20 25 64 0a    	and    %bh,0xa642520(%rip)        # a642527 <main+0xa6424f5>
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    %al,0x43(%rdi)
   3:	43 3a 20             	rex.XB cmp (%r8),%spl
   6:	28 55 62             	sub    %dl,0x62(%rbp)
   9:	75 6e                	jne    79 <main+0x47>
   b:	74 75                	je     82 <main+0x50>
   d:	2f                   	(bad)  
   e:	4c 69 6e 61 72 6f 20 	imul   $0x34206f72,0x61(%rsi),%r13
  15:	34 
  16:	2e 36 2e 33 2d 31 75 	cs ss xor %cs:%ss:0x75627531(%rip),%ebp        # 75627550 <main+0x7562751e>
  1d:	62 75 
  1f:	6e                   	outsb  %ds:(%rsi),(%dx)
  20:	74 75                	je     97 <main+0x65>
  22:	35 29 20 34 2e       	xor    $0x2e342029,%eax
  27:	36 2e 33 00          	ss xor %cs:%ss:(%rax),%eax

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
   0:	14 00                	adc    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	00 00                	add    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	01 7a 52             	add    %edi,0x52(%rdx)
   b:	00 01                	add    %al,(%rcx)
   d:	78 10                	js     1f <.eh_frame+0x1f>
   f:	01 1b                	add    %ebx,(%rbx)
  11:	0c 07                	or     $0x7,%al
  13:	08 90 01 00 00 1c    	or     %dl,0x1c000001(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	0f 00 00             	sldt   (%rax)
  27:	00 00                	add    %al,(%rax)
  29:	41 0e                	rex.B (bad) 
  2b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  31:	4a 0c 07             	rex.WX or $0x7,%al
  34:	08 00                	or     %al,(%rax)
  36:	00 00                	add    %al,(%rax)
  38:	1c 00                	sbb    $0x0,%al
  3a:	00 00                	add    %al,(%rax)
  3c:	3c 00                	cmp    $0x0,%al
  3e:	00 00                	add    %al,(%rax)
  40:	00 00                	add    %al,(%rax)
  42:	00 00                	add    %al,(%rax)
  44:	23 00                	and    (%rax),%eax
  46:	00 00                	add    %al,(%rax)
  48:	00 41 0e             	add    %al,0xe(%rcx)
  4b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  51:	5e                   	pop    %rsi
  52:	0c 07                	or     $0x7,%al
  54:	08 00                	or     %al,(%rax)
  56:	00 00                	add    %al,(%rax)
  58:	1c 00                	sbb    $0x0,%al
  5a:	00 00                	add    %al,(%rax)
  5c:	5c                   	pop    %rsp
  5d:	00 00                	add    %al,(%rax)
  5f:	00 00                	add    %al,(%rax)
  61:	00 00                	add    %al,(%rax)
  63:	00 38                	add    %bh,(%rax)
  65:	00 00                	add    %al,(%rax)
  67:	00 00                	add    %al,(%rax)
  69:	41 0e                	rex.B (bad) 
  6b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  71:	73 0c                	jae    7f <main+0x4d>
  73:	07                   	(bad)  
  74:	08 00                	or     %al,(%rax)
	...
