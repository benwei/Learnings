#include <stdio.h>
#include "test.h"
#include "socase.h"

static void dump_num_string(const char *buf, int n, char success) {
	printf("(%c) %-2d -> [%11s]\n", success, n, buf);
}

struct so_case {
    unsigned long num;
    int disp_len;
    int disp_shift;
    int match;
}; 

typedef struct so_case *so_case_t;

static struct so_case test_cases[] = {
    {12345,    6, 0, 6},
    {12345,    6, 1, 6},
    {12345789, 6, 0, 8},
    {1<<21,    6, 0, 7},
    {0,        0, 0, 0}
};

int main(int argc, char **argv)
{
	char buf[10] = {0};
	int n = 0;
    so_case_t c = test_cases;

    for (; c->num ; c++) {
	n = convert_num(c->num, c->disp_len, c->disp_shift, buf);
    dump_num_string(buf, n, SO_CASE_EQUAL(n, c->match));
    }
	return 0;
}
