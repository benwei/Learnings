
#include <stdio.h>

#define UBOUND 10
#define LBOUND 1

int foo(int r)
{
	if (r > UBOUND)
		return UBOUND;
	if (r < LBOUND)
		return LBOUND;
	
	printf("foo(%d) executed.", r);
	return r;
}

int say_hello(const char *buf)
{
	printf("Hello,%s", buf);
	return 0;
}

int get_version(char *rbuf, int size)
{	
	int i = 0;
	for(i = 0; i < size - 1 ; i++) {
		rbuf[i] = '0' + i % 10;
	}
	rbuf[i] = '\0';
	return 0;
}
