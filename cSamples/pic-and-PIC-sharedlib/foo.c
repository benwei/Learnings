#include <stdio.h>

int foo1(int a)
{
    return a + 10;
}

int foo2(int b)
{
    return foo1(b) + 2;
}

int foo3(int c)
{
    return foo2(c) + 1;
}

void dump(int d)
{
    printf("-");
    printf("-");
    printf("->");
    printf("%d\n", d);
}

