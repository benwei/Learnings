/* reference the sample from 
http://en.wikibooks.org/wiki/X86_Assembly/GAS_Syntax */

.section .data
output:
  .ascii "Hello World!\0"

.section .text
.global _main, _puts
_main: 

/* int main(void) */
	pushl %ebp
	movl %esp, %ebp
	subl $8, %esp

/* and %esp with 0xFFFFFFF0, mingw's source code reveals (SIMD?), if NO SIMD, this line is unnecessary. */
	addl $-16, %esp 

/* temporary space we reserved on the stack at the beginning of the procedure */
	movl $0, %eax
	movl %eax, -4(%ebp)

/* setup c library: __alloca and ___main */
	call __alloca 
	call ___main 

/* print message */
	movl $output, (%esp)
	call _puts

/* return value (0) after main() exit */
	movl $0, %eax 

/* restore esp and ebp */
	leave 

/* returns control to the calling procedure by poping the saved instruction pointer from the stack */
	ret
