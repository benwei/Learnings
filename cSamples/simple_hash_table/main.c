/* \brief hash table api
 * \note hashtable_add_node, hashtable_find_node
 * written by ben6 2014-05
 */

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcmp */
#include <errno.h>
#include "blog.h"
#include "hashtable.h"

void dump_node(const char *caption, hash_node *node)
{
    printf("%s %p->[%u][%u]=%s\n", caption,
            (void *)node, node->loc, node->index, node->value);
}

int main(int argc, char **argv)
{
    char data1[] = "1data2 for hashing";
    char data2[] = "2data2 for hashing2";
    hash_node *node, *removed_node;
    for (int i = 0; i < 15; i++) {
        data1[0] = i+'0';
        node = hashtable_add(data1);
        BLOG("add %p->[%u][%u]=%s\n", (void *)node, node->loc, node->index, node->value);
        data2[0] = i+'0';
        node = hashtable_add(data2);
        BLOG("add %p->[%u][%u]=%s\n", (void *)node, node->loc, node->index, node->value);
    }

    node = hashtable_find(data1);
    dump_node("found", node);

    removed_node = hashtable_remove(data1);
    dump_node("removed", removed_node);
    if (removed_node)
        hash_node_free(removed_node);

    node = hashtable_find(data1);
    if (node == NULL)
        printf("[passed] hash node(%s) remove testing\n", data1);
    else
        printf("[failed] hash node(%s) remove testing\n", data1);

    hashtable_delete("2data2 for hashing");

    node = hashtable_find("3data2 for hashing2");
    dump_node("found", node);

    node = hashtable_find(data2);
    dump_node("found", node);
    if (node->loc == 5 && node->index ==3)
        printf("[passed] hash node(%s) find testing after removal\n", data1);
    else
        printf("[failed] hash node(%s) find testing after remove\n", data1);

    hashtable_free();
    return 0;
}
