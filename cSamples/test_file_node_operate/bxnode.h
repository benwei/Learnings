/* base sample file node to read/write file
 * written by ben6 2014-06
 */

#ifndef _BXNODE_H
#define _BXNODE_H

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

struct fileinfo *fileinfo_new(unsigned char type, const char *name, const char *content);

int add_locate_table_by_id(unsigned int id);

struct node *node_new(struct fileinfo *fi);

void node_free(struct node *node);

int node_to_file(const char *image_name, struct node *root);
int file_to_node(const char *image_name, struct node **rroot);
#endif /* _BXNODE_H */

