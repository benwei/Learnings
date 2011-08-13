
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
