#include "minunit.h"
#include <stdio.h>

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

MU_TEST(test_swap)
{

#define S_B 50
#define S_C 99
    int b = S_B, c = S_C;
    swap(&b, &c);
    mu_check(b == S_C);
    mu_check(c == S_B);
}

MU_TEST(test_swap_algo)
{
#define ORIGIN_A 20
#define ORIGIN_B 30
    int a = ORIGIN_A, b = ORIGIN_B, tmp = 0;
    a ^= b;
    printf("a(%d) ^= b(%d) =>a %d\n", ORIGIN_A, b, a);
    printf("HEX a(%02X) ^= b(%02X) =>a %02X\n", ORIGIN_A, b, a);
    b ^= a;
    printf("b(%d) ^= a(%d) =>b %d\n", ORIGIN_B, a, b);
    printf("HEX b(%02X) ^= a(%02X) =>b %02X\n", ORIGIN_B, a, b);
    tmp = a;
    a ^= b;
    printf("a(%d) ^= b(%d) =>b %d\n", tmp, b, a);
    printf("HEX a(%02X) ^= b(%02X) =>b %02X\n", tmp, b, a);
    mu_check(a == 30);
    mu_check(b == 20);


}

MU_TEST(test_check) {
    int a = 1, b=2;

    mu_check(a != b);
    mu_check(b == a + 1);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_check);
    MU_RUN_TEST(test_swap_algo);
    MU_RUN_TEST(test_swap);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
