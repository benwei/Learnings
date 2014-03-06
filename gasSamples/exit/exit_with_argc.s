# refernce ProgrammingGroundUp 1.0 book
.section .data
.section .text
.globl _start
_start:
movl %esp,%ebp
subl $8,%ebp
mov 8(%ebp),%ebx # grep argc from int main(argc, **argv)
# ben6: modified code to use argument 1 as status number we will
# return to the operating system.
# Change this around and it will
# return different things to
# echo $?
movl $1, %eax # this is the linux kernel command
# number (system call) for exiting a program
int $0x80 # this wakes up the kernel to run
# the exit comma
