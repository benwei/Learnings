/* \brief http://stackoverflow.com/questions/2238107/how-to-write-a-hash-function-in-c
 * written by ben6 2014-05
 */

#include <stdio.h> /* printf */
#include "hash.h"

int main(int argc, char **argv)
{
    char data1[] = "data2 for hashing";
    char data2[] = "data2 for hashing2";
    unsigned long h1 = hash(data1);
    unsigned long h2 = hash(data2);
    printf("%08lx\n", h1);
    printf("%08lx\n", h2);
    return 0;
}
