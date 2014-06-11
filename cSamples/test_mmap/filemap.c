/* \brief using mmap to read/write file
 * \note
 *  tested
 *  - OSX 10.9.3 with Mach-O 64-bit executable x86_64 by
 *   Apple LLVM version 5.1 (clang-503.0.40) (based on LLVM 3.4svn)
 *   Target: x86_64-apple-darwin13.2.0 Thread model: posix
 * written by ben6 2014-06
 */

#include <sys/stat.h> /* umask */
#include <unistd.h> /* close */
#include <fcntl.h> /* open */
#include <stdio.h> /* printf */
#include <stdlib.h> /* atol */
#include <string.h> /* memset */
#include <sys/types.h>
#include <sys/mman.h> /* mmap */
#include <errno.h>
#include "filemap.h"

int open_addr_file(const char *filename, struct fileaddr **file_addr_handle)
{
    int r = 0;
    int pagesize = 0;
    void *addr = 0;
    struct fileaddr *fa = (struct fileaddr *) malloc(sizeof(struct fileaddr));
    if (fa == NULL) {
        errno = ENOMEM;
        return -1;
    }

    int new_created = 0;
    if (access(filename, W_OK) == -1) {
        fa->fd = open(filename, O_CREAT | O_RDWR);
        new_created = 1;
    } else
        fa->fd = open(filename, O_RDWR);

    if (fa->fd == -1) {
        perror("open");
        r = -1;
        goto err_end;
    }

    int size = 16;
    if (new_created == 1) {
        fchmod(fa->fd, 0777);
        char *msg = (char *) malloc(size);
        if (msg == NULL) {
            r = ENOMEM;
            goto err_end;
        }

        memset(msg, 32, size-1);
        msg[size-1] = '\0';
        {
            int n = write(fa->fd, msg, size);
            if (n == -1) {
                r = errno;
                goto err_end;
            }
        }
        free(msg);
    }

    pagesize = getpagesize();

    /* Using MAP_SHARED makes the contents of file synchronized 
     * with data changes via mapped address
     **/
    fa->map = (char *) mmap(addr, pagesize, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED, fa->fd, 0);
    if (fa->map == (void *) -1) {
        r = -1;
        goto err_end;
    }
    close(fa->fd);

    *file_addr_handle = fa;
    return 0;
err_end:
    if (fa->fd != -1)
        close(fa->fd);

    free(fa);
    return r;
}

void close_addr_file(struct fileaddr *fa)
{
    if (fa == NULL)
        return;

    munmap(fa->map, fa->len);
    free(fa);
}

