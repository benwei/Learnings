#include "testla.h"

int main(int argc, char **argv) {
        const char *s = "hello";
        long i;
        for (i = 0 ; i < 200000000; i++) {
                run(s);
        }
        return 0;
}

/*
switch(a){
 0:
        lll
        break;
 1:
        sss
        break;
}
*/
