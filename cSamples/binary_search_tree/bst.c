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


int bst_node_getkey(bstree *node)
{
    if (node == NULL)
        return -1;

    return node->key;
}

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

bstree *bst_new_node(bskey key)
{
    bstree *node = (bstree *) malloc(sizeof(bstree));
    if (node == NULL)
        return NULL;

    node->key = key;
    node->l = node->r = NULL;
    return node;
}

void bst_node_set(bstree *node, bstree *left, bstree *right)
{
    if (node == NULL) return;

    node->l = left;
    node->r = right;
}

int bst_insert(bstree**t, bskey key)
{
    bstree *p = NULL;
    bstree *s = NULL;

    if (t != NULL && bst_search(*t, key, NULL, &p) > 0) {
        return 0;
    }

    s = bst_new_node(key);
    if (s == NULL)
        return 0;

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

void bst_node_dump(bstree *node)
{
    if (node == NULL)
        return;

    printf("%lu\n", node->key);
}

void bst_traverse_recursive(bstree *t, int level, bst_callback callback)
{
    if (t == NULL)
        return;
    bst_traverse_recursive(t->l, level+1, callback);
    callback(t->key, level);
    bst_traverse_recursive(t->r, level+1, callback);
}

void bst_traverse_morris(bstree *t, bst_callback callback)
{
    bstree *current = t, *morris = NULL;
    if (t == NULL)
        return;

    while (current != NULL)
    {
        if (current->l == NULL)
        {
            callback(current->key, 0);
            current = current->r;
        } else {
            morris = current->l;

            while(morris->r != NULL && morris->r != current)
                morris = morris->r;

            if (morris->r == NULL) {
                morris->r = current;
                current = current->l;
            } else {
                morris->r = NULL;
                callback(current->key, 0);
                current = current->r;
            }
        }
    }
}

int bst_findmin(bstree *t, bstree **p)
{
    bstree *current = t;
    while (current != NULL)
    {
        *p=current;
        if (current->l == NULL)
            return 1;
        current = current->l;
    }
    return 0;
}

int bst_findmax(bstree *t, bstree **p)
{
    bstree *current = t;
    while (current != NULL)
    {
        *p=current;
        if (current->r == NULL)
            return 1;
        current = current->r;
    }
    return 0;
}
