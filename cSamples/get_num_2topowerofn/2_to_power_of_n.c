/* written by ben6 2014 */
#include <stdio.h>

unsigned long get_num_max_two_power_of_n(unsigned long num)
{
    unsigned long op = num;
    unsigned long r = 1;
    if (op == 0) return 0;
    if (op == 1) return 2;

    while (r < op) {
        r *= 2;
    }

    return r; 
}

int test(unsigned long num, unsigned long expected)
{
    unsigned long v = get_num_max_two_power_of_n(num);

    if (expected != v) {
        printf("[fail  ] %lu ==> two to power of N value: %lu\n", num, v);
        return 1;
    }

    printf("[passed] %lu ==> two to power of N value: %lu\n", num, v);
    return 0;
}

struct tester {
    unsigned long input;
    unsigned long expected;
};

struct tester testers[] = {
    {0, 0},
    {1, 2},
    {1024, 1024},
    {4190, 8192}
};

int main(int argc, char **argv)
{
    int i = 0;
    int test_num = sizeof(testers)/sizeof(testers[0]);
    int fail_count = 0;
    for (i = 0; i < test_num; ++i) {
        struct tester *t = &testers[i];
        fail_count+=test(t->input, t->expected);
    }

    if (fail_count > 0) {
        printf("test result: passed => %d, failed => %d\n", test_num - fail_count, fail_count);
    } else {
        printf("test result: passed => %d\n", test_num);
    }

    return fail_count;
}
