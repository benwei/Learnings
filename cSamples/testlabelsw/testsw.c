#include "testshared.h"

#define  MAX_SW_NUM 5

int run(const char *s)
{
        const char *h = s;
        int n = 0;
        int a = 1;
        do {

            switch(n) {
            case 0:
                   dmsg("a:%c\n", *s);
                   a++;
                    break;
            case 1:
                   dmsg("b:%c\n", *s);
                   a++;
                   break;
            case 2:
                   a-=2;
                   dmsg("c:%c\n", *s);
                   break;
            case 3:
                   a+=3;
                   dmsg("d:%c\n", *s);
                   break;
            case 4:
                   a-=2;
                   dmsg("e:%c\n", *s);
                   break;
            };

            n = (*++s) ? (s - h) % MAX_SW_NUM : MAX_SW_NUM;

        } while(n != MAX_SW_NUM);
        return a;
}

