/* \brief binary search tree
 * written by ben6 2014-06
 */
#include <stdio.h> /* printf */
#include "bst.h"

void dump_value(bskey key, int level)
{
    printf("l=%d, %lu\n", level, (unsigned long) key);
}

#define TEST_FAILED 1

int test_find_min(void *targ)
{
    bstree *tree = (bstree *) targ, *result = NULL;
    int key = -1, r;

    r = bst_findmin(tree, &result);
    if (r == 0) {
        printf("failed: should find minimal node\n");
        return TEST_FAILED;
    }

    key = bst_node_getkey(result);
    if (key != 0)
        return TEST_FAILED;

    printf("find min result: %u\n", key);
    
    return 0;
}

int test_find_max(void *targ)
{
    bstree *tree = (bstree *) targ, *result = NULL;
    int key = -1, r;

    r = bst_findmax(tree, &result);
    if (r == 0) {
        printf("failed: should find maximum node\n");
        return TEST_FAILED;
    }
    
    key = bst_node_getkey(result);
    if (key != 9)
        return TEST_FAILED;

    printf("find maximum result: %u\n", key);
    return 0;
}

typedef int (*pfrun)(void *);

struct _ctest {
    char *desc;
    pfrun run;
};

typedef struct _ctest ctest;

static ctest tests[] = {
    {"find min", test_find_min},
    {"find max", test_find_max},
    {NULL, NULL},
};

int test_traverse_morris(void)
{
    bstree *root = bst_new_node(4);
    bstree *layer1_left = bst_new_node(2);
    bstree *layer1_right = bst_new_node(5);
    bst_node_set(root, layer1_left, layer1_right);
    bst_node_set(layer1_left, bst_new_node(1), bst_new_node(3));
    bst_node_set(layer1_right, bst_new_node(6), bst_new_node(7));
    bst_traverse_morris(root, dump_value);
    return 0;    
}

int main(int argc, char **argv)
{
    bstree *tree = NULL;
    int i, r = 0;
    for (i = 0; i < 10 ; ++i) {
        r = bst_insert(&tree, i);
        printf("insert %d - result=%d\n", i, r);
    }

    bst_traverse_recursive(tree, 0, dump_value);
    r = 0;

    for (ctest *t = &tests[0]; t->desc != NULL; t++) {
        int retcode = t->run(tree);
        printf("[%s] %s\n", retcode ? "fail": "pass", t->desc);
        r += retcode;
    }

    test_traverse_morris();

    return r;
}
