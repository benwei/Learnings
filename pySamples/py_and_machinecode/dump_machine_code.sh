echo "int add(int a, int b) { return a + b; }" > add.c
gcc -Os -c add.c
objdump -d add.o
