/* \brief binary search tree
 * written by ben6 2014-06
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct _bstree {
    bskey key;
    struct _bstree *l;
    struct _bstree *r;
};

void bst_node_dump(bstree *t);

int bst_search(bstree *t, bskey key, bstree *parent, bstree**p)
{
    if(!t) {
        *p=parent;
        return 0;
    } else if (key == t->key) {
        *p=t;
        return 1;
    } else if ( key < t->key ) {
        return bst_search(t->l, key, t, p);
    } 
    return bst_search(t->r, key, t, p);
}

int bst_insert(bstree**t, bskey key)
{
    bstree *p = NULL;
    bstree *s = NULL;

    if (t != NULL && bst_search(*t, key, NULL, &p) > 0) {
        return 0;
    }

    s = (bstree *) malloc(sizeof(bstree));
    if (s == NULL)
        return 0;

    s->key = key;
    s->l = s->r = NULL;
    if (!p)
        *t=s;
    else if (key < p->key)
        p->l=s;
    else if (key > p->key)
        p->r=s;

    return 1; 
}

void bst_node_dump(bstree *t)
{
    if (t == NULL)
        return;

    printf("%lu\n", t->key);
}

void bst_traverse(bstree *t, int level, bst_callback callback)
{
    if (t == NULL)
        return;
    bst_traverse(t->l, level+1, callback);
    callback(t->key, level);
    bst_traverse(t->r, level+1, callback);
}

