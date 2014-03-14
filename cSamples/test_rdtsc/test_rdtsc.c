#include <stdio.h>
/* source http://stackoverflow.com/questions/8322782/rdtsc-too-many-cycles */

static inline unsigned long long tick()
{ 
    unsigned long long d;

        __asm__ __volatile__ ( 
            "rdtsc" 
            : "=A" (d)); 
    return d;
}

int main(int argc, char **argv)
{
    unsigned long long t1=1000, t2=2999;
    int x = 0;
    t1 = tick(); 
    printf("test1");
    t2 = tick(); 
    printf("time cost of printf: %llu\n", t2-t1);
 
    t1 = tick(); 
    x=x*x*x;
    t2 = tick(); 
    printf("time cost of x mul 3 times: %llu\n", t2-t1);
 
    return 0;
}
