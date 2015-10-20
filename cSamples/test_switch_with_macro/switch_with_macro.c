#include <stdio.h>

/* reference DBG from http://blog.linux.org.tw/~jserv/archives/2012/01/c_1.html */
#define DEBUG_FLAG 1

/* if DEBUG_FLAG is equal to 1, no append break;
   if DEBUG_FLAG is equal to 0 => break; case 1: ... ; break; 
 appendix:
     if (0) { label: ... }
 ``` "it is skipped in the normal flow of execution and is only reached via the goto label, reintegrating with the normal flow of execution and the end of the if (0) statement. It solves a situation where one would usually need to duplicate code or create a state variable holding the information if the additional code block should be called." ```
 */
#define DBG(...) if (DEBUG_FLAG) { __VA_ARGS__ ; }
#define MSG_BUF_SIZE 64
int main(int argc, char **argv)
{
    int i = 0;
    char msg[MSG_BUF_SIZE] = {0};
    int sum = 0;

    for (i = 0; i < 5 ; i++) {
        sum += i;
        switch(i)
        {
        case 0:
        DBG( case 1: snprintf(msg, sizeof(msg)-1, "debug add %d, sum=%d", i, sum); )
        DBG( case 2: snprintf(msg, sizeof(msg)-1, "debug add %d, sum=%d", i, sum); )
        DBG( case 3: snprintf(msg, sizeof(msg)-1, "debug add %d, sum=%d", i, sum); )
        DBG( default: snprintf(msg, sizeof(msg)-1, "debug undefined\n"); )
        }
        if (i != 0)
            printf("%s\n", msg);
    }
    return 0;
}
