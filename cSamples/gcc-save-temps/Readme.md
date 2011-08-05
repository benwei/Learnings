# -save-temps option 

 To generate more information during preprocessing and comipling period
 - .i  the source code after preprocessor procceed
 - .s  the assembly code gcc created

 Both of them is useful while you want to know what the assembly code is from C functions.<br/>
 You can clear know what the preprocessor and optimazation does by comparing .s files
 from code appending flags -O2 or without -O option.<br/>
 you can leverage the information to reverse the binary file to assembly and then assembly to c files.<br/>

## hello.s and helloO2.s camparison
<pre>
--- hello.s	2011-08-05 13:20:50.913132199 +0800
+++ helloO2.s	2011-08-05 13:22:51.009132077 +0800
@@ -1,23 +1,21 @@
-	.file	"hello.c"
-	.section	.rodata
+	.file	"helloO2.c"
+	.section	.rodata.str1.4,"aMS",@progbits,1
+	.align 4
 .LC0:
-	.string	"Hello World! gcc --save-temps"
+	.string	"Hello World! gcc --save-temps\n"
 	.text
+	.p2align 4,,15
 .globl main
 	.type	main, @function
 main:
 	pushl	%ebp
 	movl	%esp, %ebp
 	andl	$-16, %esp
-	subl	$32, %esp
-	movl	$1, 28(%esp)
-	movl	$1, 24(%esp)
-	movl	24(%esp), %eax
-	addl	$1, %eax
-	movl	%eax, 28(%esp)
-	movl	$.LC0, (%esp)
-	call	puts
-	movl	$0, %eax
+	subl	$16, %esp
+	movl	$.LC0, 4(%esp)
+	movl	$1, (%esp)
+	call	__printf_chk
+	xorl	%eax, %eax
 	leave
 	ret
 	.size	main, .-main
</pre>
