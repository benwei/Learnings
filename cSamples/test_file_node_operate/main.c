/* base sample file node to read/write file
 * written by ben6 2014-06
 */

#include <stdio.h> /* printf, fopen, fclose, fwrite */
#include <stdlib.h> /* free */
#include <errno.h> /* errno */
#include <string.h> /* memset */
#include "bxnode.h"

int create_test_image(const char *image_name)
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

    if (root)
        add_locate_table_by_id(root->id);
    
    fi = fileinfo_new(TYPE_FILE, "goodbye.txt", "bye! bye!");
    root->right = node_new(fi);

    rc = node_to_file(image_name, root);

err_end:
    if (root && root->right) {
        node_free(root->right);
        root->right = NULL;
    }

    if (root && root->left) {
        node_free(root->left);
        root->left = NULL;
    }

    node_free(root);

    return rc;
}

int load_test_image(const char *image_name)
{
    struct node *root = NULL;
    printf("node_to_file(%s)\n", image_name);
    int rc = file_to_node(image_name, &root);
    if (rc != 0)
        return -1;

    printf("read root node(%d) -> %s\n", root->id, root->fi->name);
    return rc;
}

int main(int argc, char **argv)
{
    char *image_name = "./fsdisk.img";
    int rc = create_test_image(image_name);
    if (rc) {
        fprintf(stderr, "create test image failure (%d)\n", rc);
        return rc;
    }


    return load_test_image(image_name);
}
