/* base sample file node to read/write file
 * written by ben6 2014-06
 */

#include <stdio.h> /* printf, fopen, fclose, fwrite */
#include <stdlib.h> /* free */
#include <errno.h> /* errno */
#include <string.h> /* memset */

#define CONTENT_LEN 255
#define FILENAME_LEN 12
#define TYPE_DIR  1
#define TYPE_FILE 2

#define MAX_PAYLOAD_SIZE 127

struct fileinfo {
    unsigned char type;
    unsigned long filesize;
    unsigned long diskaddr;
    unsigned long payload_len;
    char name[FILENAME_LEN+1];
    char payload[MAX_PAYLOAD_SIZE];
};

struct node {
    unsigned int id;
    struct fileinfo *fi;
    struct node *left;
    struct node *right;
};


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
static unsigned int nodemap[MAX_NODE_NUM] = {0};
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

int main(int argc, char **argv)
{
    int rc = 0;
    struct node *root  = NULL;
    struct fileinfo *fi = fileinfo_new(TYPE_DIR, "/", NULL);
    if (fi == NULL) {
        rc = ENOMEM;
        goto err_end;
    }

    root = node_new(fi);
    if (root == NULL) {
        rc = ENOMEM;
        goto err_end;
    }

    fi = fileinfo_new(TYPE_FILE, "hello.txt", "hello-world");
    root->left = node_new(fi);

    if (root) {
        nodemap[0] = sizeof(nodemap);
    }

    if (root->left)
        nodemap[1] = sizeof(nodemap) + sizeof(struct fileinfo);

    {
        FILE *fp = fopen("./fsdisk.img", "wb");
        int n = 0;
        if (fp == NULL) {
            printf("file open failure");
            return errno;
        }

        n = fwrite(nodemap, sizeof(nodemap), 1, fp);
        n = fwrite(root->fi, sizeof(struct fileinfo), 1, fp);
        printf("write root node(%d)\n", root->id);
        n = fwrite(root->left->fi, sizeof(struct fileinfo), 1, fp);
        printf("write node(%d)\n", root->left->id);

        fclose(fp);
    }

err_end:
    if (root && root->left)
        node_free(root->left);

    node_free(root);

    return 0;
}
