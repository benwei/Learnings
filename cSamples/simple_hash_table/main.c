/* \brief hash table api
 * \note hash_table_add_node, hash_table_find_node
 * written by ben6 2014-05
 */

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcmp */
#include <errno.h>
#include "hashtable.h"

int main(int argc, char **argv)
{
    char data1[] = "1data2 for hashing";
    char data2[] = "2data2 for hashing2";
    hash_node *node ;
    for (int i = 0; i < 10; i++) {
        data1[0] = i+'0';
        node = hash_table_add_node(data1);
        BLOG("add %p->[%u][%u]=%s\n", (void *)node, node->loc, node->index, node->value);
        data2[0] = i+'0';
        node = hash_table_add_node(data2);
        BLOG("add %p->[%u][%u]=%s\n", (void *)node, node->loc, node->index, node->value);
    }

    node = hash_table_find_node(data1);
    printf("found %p->[%u][%u]=%s\n", (void *)node, node->loc, node->index, node->value);
    node = hash_table_find_node(data2);
    printf("found %p->[%u][%u]=%s\n", (void *)node, node->loc, node->index, node->value);
    hash_table_free();
    return 0;
}
