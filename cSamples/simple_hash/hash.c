/* \brief http://stackoverflow.com/questions/2238107/how-to-write-a-hash-function-in-c
 * written by ben6 2014-05
 */

#include "hash.h"

unsigned long hash(char const *input)
{
    const unsigned long hval_size = 32;
    unsigned long hval = 0x777777;
    const unsigned long per_char = 13;

    while (*input)
    {
        hval ^= *input++;
        hval = ((hval << per_char) | (hval >> (hval_size - per_char)));
    }
    return hval;
}
