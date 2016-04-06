#include <stdio.h>
#include "b8.h"
#define DATA 0x90
int main()
{
    bitop_t a = (bitop_t) (u8) DATA;
    a.b.b3 = 1;
    printf("%02X + b3(1)=%02X\n", DATA, a.v);
    return 0;
}
