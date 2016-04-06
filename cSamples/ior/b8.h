#ifndef B8_H
#define B8_H 1

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

#define BIT0 (1)
#define BIT1 (1<<1)
#define BIT2 (1<<2)
#define BIT3 (1<<3)
#define BIT4 (1<<4)
#define BIT5 (1<<5)
#define BIT6 (1<<6)
#define BIT7 (1<<7)


#endif /* B8_H */
