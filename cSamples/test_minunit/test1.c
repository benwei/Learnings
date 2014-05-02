#include "minunit.h"

MU_TEST(test_check) {
    int a = 1, b=2;

    mu_check(a != b);
    mu_check(b == a + 1);
}
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_check);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
