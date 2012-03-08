#include <stdio.h>


void funca()
{
}

static void funcb()
{
}

static inline void funcc()
{
}

int main()
{
	funcb();
#if 0
	int a = 1; // 3 useless line will be removed by -O2 optimization
	int b = 1;
	a = b+1;
#endif
	// change puts() to __printf_chk() by -O2 optimization 
	printf("Hello World! gcc --save-temps\n");
	return 0;
}
