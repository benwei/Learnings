#include <stdio.h>

/* reference DBG from http://blog.linux.org.tw/~jserv/archives/2012/01/c_1.html */
#define DEBUG_FLAG 1
#define DBG(...) if (DEBUG_FLAG) { __VA_ARGS__ ; }

int main(int argc, char **argv)
{
    int i = 0;
    char msg[32] = {0};
    int sum = 0;


    for (i = 0; i < 5 ; i++) {
        sum += i;
        switch(i)
        {
        case 0:
        DBG( case 1: snprintf(msg, sizeof(msg)-1, "debug add %d, sum=%d", i, sum); break; )
        DBG( case 2: snprintf(msg, sizeof(msg)-1, "debug add %d, sum=%d", i, sum); break; )
        DBG( case 3: snprintf(msg, sizeof(msg)-1, "debug add %d, sum=%d", i, sum); break; )
        DBG( default: snprintf(msg, sizeof(msg)-1, "should seee this, debug undefined"); break; )
        }
        if (i != 0)
            printf("%s\n", msg);
    }
    return 0;
}
