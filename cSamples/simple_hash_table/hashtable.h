/* \brief hash table api
 * \note hash_table_add_node, hash_table_find_node
 * written by ben6 2014-05
 */
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

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

hash_node* hash_table_add_node(const char* value);
hash_node* hash_table_find_node(const char *value);
void hash_table_free(void);

#endif /* _HASHTABLE_H */
