/* 2014-07 written by Ben Wei 
 * License: Attribution-NonCommercial-NoDerivs CC BY-NC-ND
 * example code for single linking list
 **/

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <errno.h>

typedef void (*free_data_handler)(void *data, int len);

struct slnode{
    void *data; 
    int data_len;
    struct slnode *next;
};

typedef struct slnode *slnode_t;

struct slist {
    int count;
    slnode_t head;
    slnode_t tail;
    free_data_handler pf_free_data;
};

typedef struct slist *slist_t;

typedef int (*pf_compare)(void *data, int len, void *user_data);

static slnode_t slnode_create(void *data, int len)
{
    slnode_t node = (slnode_t ) malloc(sizeof(struct slnode));
    if (node == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    node->data = data;
    node->data_len = len;
    node->next = NULL;

    return node;
}

static void free_slnode(slnode_t node, free_data_handler pf_free_data)
{
    if (node == NULL)
        return ;

    if (pf_free_data && node->data) {
        pf_free_data(node->data, node->data_len);
    }
    
    free(node);
}

slist_t slist_create(free_data_handler pf_free_data)
{
    slist_t slist = (slist_t ) malloc(sizeof(struct slist));
    if (slist == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    slist->count = 0;
    slist->head = slist->tail = 0;
    slist->pf_free_data = pf_free_data;
    return slist;
}

int slist_add(slist_t slist, slnode_t node)
{
    if (slist->head == NULL) {
        slist->head = slist->tail = node;
    } else {
        slist->tail->next = node;
        slist->tail = node;
    }
    slist->count++;
    return 0; 
}

int slist_count(slist_t slist)
{
    if (slist)
        return -1;

    return slist->count;
}

slnode_t slist_find(slist_t slist, pf_compare compare, void *user_data)
{
    slnode_t found, prev;
    found = prev = slist->head;
    for (; found != NULL ; found = found->next)
    {
        if (compare(found->data, found->data_len, user_data)) 
            return found;
    }
    return NULL;
}

int slist_del(slist_t slist, slnode_t node)
{
    slnode_t found, prev;
    found = prev = slist->head;
    for (; found != NULL ; found = found->next)
    {
        if (found == node) 
            break;
        prev = found;
    }

    if (found) {
        if (found == prev) {
            slist->head = found->next;
        }
        if (found == slist->tail) {
                slist->tail = prev;
                prev->next = NULL;
        }
        free_slnode(found, slist->pf_free_data);
        slist->count--;
    }

    return 0;
}

void slist_free(slist_t slist)
{
    if (slist == NULL) 
        return ;

    while (slist->head)
    {
        slnode_t node = slist->head;
        if (node == NULL) 
            break;

        slist->head = node->next;
        free_slnode(node, slist->pf_free_data);
    }

    free(slist);
}

static void free_mydata(void *data, int len)
{
    if (data) free(data);
}

static int my_compare(void *data, int len, void *user_data)
{
    printf("%d vs %d\n", *(int *)data, (int) user_data);
    if (*(int *)data == (int) user_data) {
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int num_size = sizeof(int);
    slnode_t node = NULL; 
    slist_t numbers = slist_create(free_mydata);
    if (numbers == NULL)
        return errno;

    for (int i = 0; i < 10; ++i)
    {
        int *num = num = (int *) malloc(num_size);
        if (num == NULL) {
            errno = ENOMEM;
            break;
        }
        *num = i;
        node = slnode_create(num, num_size); 
        if (node == NULL) {
            break;
        }
        slist_add(numbers, node); 
    }

    if ((node = slist_find(numbers, my_compare, (void *) 8)) != NULL) {
         printf("number %d was found.\n", *((int *)node->data));
    }

    slist_free(numbers);
    return 0;
}
