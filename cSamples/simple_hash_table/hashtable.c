/* \brief hash table api
 * \note hash table features with add, find, remove, delete
 * written by ben6 2014-05
 */

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcmp */
#include <errno.h>
#include "hash.h"
#include "hashtable.h"

#define HASHTABLE_SIZE 13
#define HASH_LOCATION(hash_value) hash_value % HASHTABLE_SIZE
static hash_node *hashtable[HASHTABLE_SIZE] = {0};

static inline void hashtable_append(hash_node *root, hash_node *node)
{
    hash_node *p;
    unsigned int index = 1;
    for (p = root; p->next != NULL; p = p->next)
        index++;
    node->index = index;
    p->next = node;
}

hash_node* hashtable_add(const char* value)
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
    location = HASH_LOCATION(node->hash);
    node->loc = location;
    if ((root = hashtable[location]) != NULL)
    {
        hashtable_append(root, node);
    } else {
        hashtable[location] = node;
        node->index = 0;
    }
    return node;

err_end:
    free(node);
    return NULL;
}

hash_node* hashtable_find(const char *value)
{
    unsigned long hash_value = hash(value);
    unsigned int location = HASH_LOCATION(hash_value);
    hash_node *root = hashtable[location];
    if (root == NULL)
        return NULL;

    for (hash_node *p = root; p != NULL; p = p->next) {
        if (strcmp(p->value, value) == 0) {
           return p; 
        }
    }

    return NULL; 
}

hash_node* hashtable_remove(const char *value)
{
    unsigned long hash_value = hash(value);
    unsigned int location = HASH_LOCATION(hash_value);
    hash_node *p = NULL, *prev = NULL, *root = hashtable[location];
    if (root == NULL)
        return NULL;

    for (p = root; p != NULL; p = p->next) {
        if (strcmp(p->value, value) == 0) {
            break;
        }
        prev = p;
    }

    if (p == root) {
        if (root->next == NULL)
            hashtable[location] = NULL;
        else
            hashtable[location] = root->next;
        p->next = NULL;
    } else if (p) {
        prev->next = p->next;
        p->next = NULL;
    }

    return p;
}

void hash_node_free(hash_node *node)
{
    if (node->value)
        free(node->value);
    free(node);
}

void hashtable_delete(const char *value)
{
    hash_node *node = hashtable_remove(value);
    if (node) hash_node_free(node);
}

static inline void free_node_list(hash_node *root)
{
    hash_node *p;
    for (p = root; p != NULL;) {
        p = root->next;
        hash_node_free(root);
        root = p;
    }
}

void hashtable_free(void)
{
    unsigned int i;
    for (i = 0; i < HASHTABLE_SIZE; i++) {
        hash_node *root = hashtable[i];
        if (root != NULL) {
            free_node_list(root);
        }
    }
}
