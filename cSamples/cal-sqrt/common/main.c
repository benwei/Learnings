#include <stdio.h> /* printf */
#include "test.h"

int main(int argc, char **argv)
{
    float n = 65535;
    float precision = 0.000001;
    float result = testcase_sqrt(n, precision);

    printf("%s:sqr(%lf,%lf)=> %lf:\n", *argv, n, precision, result);
    return 0;
}
