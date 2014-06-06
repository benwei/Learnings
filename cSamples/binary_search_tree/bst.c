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
    bstree *current;
    if(!t) {
        *p=parent;
        return 0;
    }

    current = t;
    while (current != NULL)
    {
        *p=current;
        if (key == current->key) {
            return 1;
        } else if (key < current->key) {
            current = current->l;
        } else {
            current = current->r;
        }
    }
    return 0;
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

int bst_delete(bstree **t, bskey key)
{
    bstree *p = NULL;
    if (t == NULL && bst_search(*t, key, NULL, &p) == 0) {
        return 1;
    }


    return 0; 
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

