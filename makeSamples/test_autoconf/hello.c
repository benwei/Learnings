#include <stdio.h>
#include "config.h"
#include "foo.h"
#ifndef INDEX
#define INDEX 1
#endif

int main(void)
{
	printf("hello %d\n", mymin(INDEX, 10));
	return 0;
}

