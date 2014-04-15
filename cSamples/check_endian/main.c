#include <stdio.h>
#include "check_endian.h"
#include "socase.h"

int main(int argc, char **argv)
{
    bool big_endian_system[2] = {};
 
    big_endian_system[0] = is_big_endian_system_by_pointer();
    printf("is_big_endian_system_by_pointer => %s\n", SO_ASCII_BOOL(big_endian_system[0]));

    big_endian_system[1] = is_big_endian_system_by_union();
    printf("is_big_endian_system_by_union => %s\n", SO_ASCII_BOOL(big_endian_system[1]));

    if (big_endian_system[0])
        printf("big-endian\n");
    else
        printf("little-endian\n");

	return 0;
}
