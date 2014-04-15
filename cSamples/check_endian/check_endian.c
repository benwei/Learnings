/*
 * Written By Ben Wei ben@staros.mobi 2014
 **/

#include <stdio.h>
#include "check_endian.h"

bool is_big_endian_system_by_pointer(void)
{
    int n = 0x12345678;
    // little endian if true
    return (*(char *)&n == 0x12);
}

bool is_big_endian_system_by_union(void)
{
    union {
        int i;
        char c[sizeof(int)];
    } x;
    x.i = 0x12345678;
    return (x.c[0] == 0x12);
}
