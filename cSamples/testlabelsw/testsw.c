#include "testla.h"

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
            };

            n = (*++s) ? (s - h) % 3 : 3;

        } while(n != 3);
        return a;
}

