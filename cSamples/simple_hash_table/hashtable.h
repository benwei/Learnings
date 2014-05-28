/* \brief hash table api
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

hash_node* hashtable_add(const char* value);
hash_node* hashtable_find(const char *value);
void hashtable_free(void);

#endif /* _HASHTABLE_H */
