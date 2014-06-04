/* \brief binary search tree
 * written by ben6 2014-06
 */
#include <stdio.h> /* printf */
#include "bst.h"

void dump_value(bskey key, int level)
{
    printf("l=%d, %lu\n", level, (unsigned long) key);
}

int main(int argc, char **argv)
{
    bstree *p = NULL;
    for (int i = 0; i < 10 ; ++i) {
        int r = bst_insert(&p, i);
        printf("insert %d - result=%d\n", i, r);
    }

    bst_traverse(p, 0, dump_value);
    return 0;
}
