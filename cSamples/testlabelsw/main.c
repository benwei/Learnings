#include "testshared.h"

int main(int argc, char **argv) {
        const char *s = "hello";
        long i;
        for (i = 0 ; i < 250000000; i++) {
                run(s);
        }
        return 0;
}

