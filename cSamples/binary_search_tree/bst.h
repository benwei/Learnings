/* \brief binary search tree
 * written by ben6 2014-06
 */
#ifndef _BSTREE_H
#define _BSTREE_H

typedef unsigned long bskey; 

struct _bstree ;

typedef struct _bstree bstree;

void bst_node_set(bstree *node, bstree *left, bstree *right);

bstree *bst_new_node(bskey);

void bst_node_dump(bstree *node);

int bst_node_getkey(bstree *node);

int bst_search(bstree *t, bskey key, bstree *parent, bstree **result);
int bst_insert(bstree **t, bskey key);

typedef void (*bst_callback)(bskey key, int level);

void bst_traverse_recursive(bstree *t,int level, bst_callback callback);
void bst_traverse_morris(bstree *t, bst_callback callback);

int bst_findmin(bstree *t, bstree **result);
int bst_findmax(bstree *t, bstree **result);

#endif /* _BSTREE_H */

