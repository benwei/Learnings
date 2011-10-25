#include <stdio.h>

void foo(void)
{
   int a = 41;
   a = a++;
   printf("%d\n", a);
}

int main(void)
{
  foo();
  return 0;
}
