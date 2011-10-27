#include <stdio.h>

void foo(void)
{
   int a = 41;
   /* OSX 10.6.8 gcc 4.2.1
      a = a++; warning: operation on ‘a’ may be undefined */
   a = a++;
   printf("%d\n", a);
}

int main(void)
{
  foo();
  return 0;
}
