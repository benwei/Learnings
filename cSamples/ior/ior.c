#include <stdio.h>
typedef unsigned char u8;
typedef union {
    u8 v;
    struct {
       u8 b7:1;
       u8 b6:1;
       u8 b5:1;
       u8 b4:1;
       u8 b3:1;
       u8 b2:1;
       u8 b1:1;
       u8 b0:1;
    }u;
} bitop_t;

void dump_8bit_binary(unsigned char d)
{
    bitop_t a = (bitop_t) d;
    printf("%02X\n", d);
    printf("%01d%01d%01d%01d"
           "%01d%01d%01d%01d\n",
	   a.u.b0, a.u.b1, a.u.b2, a.u.b3,
	   a.u.b4, a.u.b5, a.u.b6, a.u.b7
	   );
}

int main() {
    unsigned short a = 0x5555;      // pattern 0101 ...
    unsigned short b = 0xAAAA;      // pattern 1010 ...

   

    printf("%04x | %04x = %04x\n", a, b, a|b);

    dump_8bit_binary(a);
    dump_8bit_binary(b);
    return  0;
}
