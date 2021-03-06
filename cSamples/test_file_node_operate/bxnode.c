/* base sample file node to read/write file
 * written by ben6 2014-06
 */

#include <stdio.h> /* printf, fopen, fclose, fwrite */
#include <stdlib.h> /* free */
#include <errno.h> /* errno */
#include <string.h> /* memset */

#include "bxnode.h"

struct fileinfo *fileinfo_new(unsigned char type, const char *name, const char *content)
{
    struct fileinfo *fi = (struct fileinfo *) malloc(sizeof(struct fileinfo));

    if (fi == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    memset(fi, 0, sizeof(struct fileinfo));

    fi->type = type;
    fi->filesize = sizeof(struct fileinfo);
    strncpy(fi->name, name, FILENAME_LEN);

    if (content && *content != 0) {
        int len = strlen(content);
        strncpy(fi->payload, content, MAX_PAYLOAD_SIZE - 1);
        fi->payload_len = (len > MAX_PAYLOAD_SIZE - 1) ? MAX_PAYLOAD_SIZE - 1: (unsigned char) len;
    }
        
    return fi;
}

#define MAX_NODE_NUM 16
static unsigned int locate_table[MAX_NODE_NUM] = {0};
int add_locate_table_by_id(unsigned int id)
{
    if (id >= MAX_NODE_NUM) {
        errno = ENOSPC;
        return -1;
    }

    if (id == 0)
        locate_table[0] = sizeof(locate_table);
    else 
        locate_table[id] = sizeof(locate_table) + sizeof(struct fileinfo);

    return 0;
}

static unsigned int node_id = 0;

struct node *node_new(struct fileinfo *fi)
{
    struct node *node = (struct node *) malloc(sizeof(struct node));
    if (node == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    node->id = node_id++;
    node->fi = fi;
    node->right = NULL;
    node->left = NULL;
    return node;
}

void node_free(struct node *node)
{
    if (!node) 
        return;
    if (node->fi)
        free(node->fi);
    free(node);
}

#define FILEOP_CHECK(ntimes, deftimes) if(ntimes != deftimes) { \
    errno = EINVAL ; rc=-1;  goto err_end; \
}

int node_to_file(const char *image_name, struct node *root)
{
    FILE *fp = NULL;
    int n = 0, rc = 0;

    if (root->left) {
        locate_table[1] = sizeof(locate_table) + sizeof(struct fileinfo);
    }

    fp = fopen(image_name, "wb");
    if (fp == NULL) {
        printf("file open failure");
        return -1;
    }

    n = fwrite(locate_table, sizeof(locate_table), 1, fp);
    FILEOP_CHECK(n, 1);
    n = fwrite(root->fi, sizeof(struct fileinfo), 1, fp);
    FILEOP_CHECK(n, 1);
    printf("write root node(%d)\n", root->id);
    n = fwrite(root->left->fi, sizeof(struct fileinfo), 1, fp);
    FILEOP_CHECK(n, 1);
    printf("write left node(%d)\n", root->left->id);
    n = fwrite(root->right->fi, sizeof(struct fileinfo), 1, fp);
    FILEOP_CHECK(n, 1);
    printf("write right node(%d)\n", root->right->id);

err_end:
    fclose(fp);

    return rc;
}

int file_to_node(const char *image_name, struct node **rroot)
{
    FILE *fp = NULL;
    int n = 0, i = 0, rc = 0;
    struct node *root = NULL;
    struct fileinfo *pfi = NULL;

    fp = fopen(image_name, "rb");
    if (fp == NULL) {
        printf("file open failure");
        return -1;
    }

    n = fread(&locate_table, sizeof(locate_table), 1, fp);
    FILEOP_CHECK(n, 1);

    root = (struct node *) malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;
    root->id = 0;

    pfi = (struct fileinfo *) malloc(sizeof(struct fileinfo));
    n = fread(pfi, sizeof(struct fileinfo), 1, fp);
    FILEOP_CHECK(n, 1);
    root->fi = pfi;

    // FIXME: error handling
    for (i = 1; i < sizeof(locate_table)/sizeof(locate_table[0]); ++i)
    {
        if (locate_table[i] != 0 && i < 3) {
            struct node *bxnode= (struct node *) malloc(sizeof(struct node));
            if (!bxnode) {
                rc = ENOMEM;
                goto err_end;
            }
            bxnode->id = i;
            bxnode->left = NULL;
            bxnode->right = NULL;
            bxnode->fi = NULL;
            if (!bxnode) {
                rc = ENOMEM;
                goto err_end;
            }

            pfi = (struct fileinfo *) malloc(sizeof(struct fileinfo));
            n = fread(pfi, sizeof(struct fileinfo), 1, fp);
            FILEOP_CHECK(n, 1);
            if (i == 1)
                root->left = bxnode;
            else if (i == 2)
                root->right = bxnode;
        }
    }
    *rroot = root;
err_end:
    fclose(fp);

    return rc;
}

