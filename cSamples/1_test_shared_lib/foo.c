#include <stdio.h>
#include "foo.h"

int foo_max(int a, int b)
{
    return (a > b) ? a : b;
}

int foo_min(int a, int b)
{
    return (a < b) ? a : b;
}

void foo_banner(void)
{
    printf("foo testing: %s\n", HELLO_MSG);
}
