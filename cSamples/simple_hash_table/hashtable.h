/* \brief hash table api
 * written by ben6 2014-05
 */
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

typedef struct node {
    unsigned long hash;
    char *value;
    unsigned int index;
    unsigned int loc;
    struct node *next;
} hash_node;

hash_node* hashtable_add(const char* value);
hash_node* hashtable_find(const char *value);
hash_node* hashtable_remove(const char *value);
void hashtable_delete(const char *value);
void hash_node_free(hash_node *node);

void hashtable_free(void);


#endif /* _HASHTABLE_H */
