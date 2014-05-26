/* \brief hash table api
 * \note hash_table_add_node, hash_table_find_node
 * written by ben6 2014-05
 */

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcmp */
#include <errno.h>
#include "hash.h"
#include "hashtable.h"

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

hash_node* hash_table_add_node(const char* value)
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

hash_node* hash_table_find_node(const char *value)
{
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

static inline void free_node(hash_node *node)
{
    if (node->value)
        free(node->value);
    free(node);
}

static inline void free_node_list(hash_node *root)
{
    hash_node *p;
    for (p = root; p != NULL;) {
        p = root->next;
        free_node(root);
        root = p;
    }
}

void hash_table_free(void)
{
    unsigned int i;
    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        hash_node *root = hash_table[i];
        if (root != NULL) {
            free_node_list(root);
        }
    }
}
