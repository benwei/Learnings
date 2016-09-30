#ifndef __FILEMAP_H
#define __FILEMAP_H

struct fileaddr {
    int fd;
    char *map;
    int len;
};

#define MAX_DATA_SIZE 16

int open_addr_file(const char *filename, struct fileaddr **file_addr_handle);
void close_addr_file(struct fileaddr *fa);

#endif /* __FILEMAP_H */
