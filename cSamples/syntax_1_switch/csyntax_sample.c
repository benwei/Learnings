/* sample c project for switch syntax
 * written by ben6 2014-06
 * - syntax by mixing switch case and if else
 */

#include <stdio.h> /* printf */

/*
 * reference: https://groups.google.com/forum/#!topic/alt.os.development/-fP1ZLxGgFk%5B126-150-false%5D
 */
static void syntax_switch(int c, int mux)
{
    switch(c) {
        default:
        if (mux == 0) {
            case 0: case 1: case 2:
                printf("mux%d: %d\n", mux, c);
                break;
        } else if (mux ==  1)
            case 3: case 4: case 5:
                printf("mux%d: %d\n", mux, c);
                break;
    };
}

int main(int argc, char **argv)
{
    printf("This is a mixing switch-case and if-else sample\n");
    syntax_switch(2, 0);
    syntax_switch(6, 1);
    return 0;
}
