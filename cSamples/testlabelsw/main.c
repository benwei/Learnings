#include "testshared.h"

int verbose = 0;

int main(int argc, char **argv) {
        const char *s = "hello";
        const char *arg;
        long i;
        long max_loop = 250000000;
        int result = 0;
        if (argc >= 2 && argv[1][0] == '-') {
                arg = argv[1];
                while(*(++arg)) {
                        switch(*arg) {
                        case 's':
                                max_loop = 1;
                                break;
                        case 'v':
                                verbose++;
                                break;
                        case 'h': /* follow next */
                        default:
                                printf("syntax: [ -option ]\n"
                                       "\toption:\n"
                                       "\th - this help\n"
                                       "\tv - verbose\n"
                                       "\ts - only loop one\n");
                                return 0;
                        }
                }
        }

        for (i = 0 ; i < max_loop ; i++) {
                result = run(s);
        }
        printf("result:%d\n", result);
        return 0;
}

