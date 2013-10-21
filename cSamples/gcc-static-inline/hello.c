#include <stdio.h>


void funca(int a)
{
    return a+1;
}

static void funcb(int b)
{
    return b+2;
}

static inline void funcc(int c)
{
    return c+3;
}

int main()
{
	funcb(1);
#if 1
	int a = 1; // 3 useless line will be removed by -O2 optimization
	volatile int b = 1;
	a = b+1;
    printf("a=%d\n", a);
#endif
	// change puts() to __printf_chk() by -O2 optimization 
	printf("Hello World! gcc --save-temps\n");
	return 0;
}
