/* \brief hash table api
 * \note hash_table_add_node, hash_table_find_node
 * written by ben6 2014-05
 */

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcmp */
#include <errno.h>
#include "hash.h"

#ifdef DEBUG
# define BLOG(...) printf(__VA_ARGS__)
#else
# define BLOG(...)
#endif

typedef struct node {
    unsigned long hash;
    char *value;
    unsigned int index;
    unsigned int loc;
    struct node *next;
} hash_node;

#define HASH_TABLE_SIZE 13
static hash_node *hash_table[HASH_TABLE_SIZE] = {0};

static inline void hash_table_node_append(hash_node *root, hash_node *node)
{
    hash_node *p;
    unsigned int index = 1;
    for (p = root; p->next != NULL; p = p->next)
        index++;
    node->index = index;
    p->next = node;
}

static hash_node* hash_table_add_node(const char* value)
{
    unsigned location = 0;
    hash_node *root = NULL;
    hash_node *node = malloc(sizeof(hash_node));
    if (node == NULL)
        return NULL;
    node->hash = hash(value);
    node->value = (char *) strdup(value);
    if (node->value == NULL)
        goto err_end;

    node->next = NULL;
    location = node->hash % HASH_TABLE_SIZE;
    node->loc = location;
    if ((root = hash_table[location]) != NULL)
    {
        hash_table_node_append(root, node);
    } else {
        hash_table[location] = node;
        node->index = 0;
    }
    return node;

err_end:
    free(node);
    return NULL;
}

static hash_node* hash_table_find_node(const char *value) {
    unsigned long hash_value = hash(value);
    unsigned int location = hash_value % HASH_TABLE_SIZE;
    hash_node *root = hash_table[location];
    if (root == NULL)
        return NULL;

    for (hash_node *p = root; p != NULL; p = p->next) {
        if (strcmp(p->value, value) == 0) {
           return p; 
        }
    }

    return NULL; 
}

static inline void free_node(hash_node *node) {
    if (node->value)
        free(node->value);
    free(node);
}

static inline void free_node_list(hash_node *root)
{
    hash_node *p;
    for (p = root; p != NULL;) {
        p = root->next;
        // BLOG("free node %p\n", (void *)root);
        free_node(root);
        root = p;
    }
}

static void hash_table_free(void) {
    unsigned int i ;
    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        hash_node *root = hash_table[i];
        if (root != NULL) {
            free_node_list(root);
        }
    }
}

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
