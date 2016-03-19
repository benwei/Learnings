#include <stdio.h>
typedef unsigned char u8;

typedef struct {
       u8 b7:1;
       u8 b6:1;
       u8 b5:1;
       u8 b4:1;
       u8 b3:1;
       u8 b2:1;
       u8 b1:1;
       u8 b0:1;
} b8_t;

typedef union {
    u8 v;
    b8_t b;
} bitop_t;

void dump_8bit_binary(void *d)
{
    bitop_t *a = (bitop_t *) d;
    printf("0x%02X\n", (u8) a->v);
    printf("%01d%01d%01d%01d"
           "%01d%01d%01d%01d\n",
	   a->b.b0, a->b.b1, a->b.b2, a->b.b3,
	   a->b.b4, a->b.b5, a->b.b6, a->b.b7
	   );
}

#define BIT0 (1)
#define BIT1 (1<<1)
#define BIT2 (1<<2)
#define BIT3 (1<<3)
#define BIT4 (1<<4)
#define BIT5 (1<<5)
#define BIT6 (1<<6)
#define BIT7 (1<<7)

int bit_set_testing(void)
{
    int e = 0;
    bitop_t a = (bitop_t) (u8) 0x90;
    printf("sizeof(bitop_t))=%ld\n", sizeof(a));

    /* not effect with bit set ?? */
    a.b.b3 = 1;
    a.b.b0 = 1;

    /* note: the following line with compile */
    /* error: invalid application of 'sizeof' to bit-field */
    /* printf("sizeof 1 bit\n", sizeof(a.b3)); */

    dump_8bit_binary(&a);

    if (a.v != 0x90) {
	printf("[fail] not effect bit set\n");
	e++;
    }

    a.v |= BIT3;
    if (a.b.b3 != 1) {
	printf("[fail] bit3 OR operates\n");
	e++;
    }
    dump_8bit_binary(&a);

    return e;
}

int main() {
    int r = 0;
    unsigned short a = 0x5555;      // pattern 0101 ...
    unsigned short b = 0xAAAA;      // pattern 1010 ...

    printf("%04x | %04x = %04x\n", a, b, a|b);
    dump_8bit_binary(&a);
    dump_8bit_binary(&b);
    r = bit_set_testing();
    return r;
}
