
add.o:     file format pe-i386


Disassembly of section .text:

00000000 <_add>:
   0:	55                   	push   %ebp
   1:	89 e5                	mov    %esp,%ebp
   3:	8b 45 0c             	mov    0xc(%ebp),%eax
   6:	03 45 08             	add    0x8(%ebp),%eax
   9:	5d                   	pop    %ebp
   a:	c3                   	ret    
   b:	90                   	nop
