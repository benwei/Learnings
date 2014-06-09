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
#include "soio.h"

#define TEST_FAILED 1
#define MAX_BUF_SIZE 16

int update_mapped_buf(char *addr)
{
        long loc = 0;
        long l = atol(addr);
        char buf[MAX_BUF_SIZE] = {0};

        printf("%ld\n", l);

        l++; 
        while (l>0) {
            buf[loc++] = (l % 9) + '0';
            l/=10;
        }

        loc = 0;

        while (*buf != 0 && loc < MAX_BUF_SIZE) {
            *addr++ = buf[loc++];
        }
        return 0;
}

int main(int argc, char **argv)
{
    int r = 0;
    int pagesize = 0;
    caddr_t addr = 0;
    int fd;
    int new_created = 0;
    char *file = "file01.txt";
    if (access(file, W_OK) == -1) {
        fd = open(file, O_CREAT | O_RDWR);
        new_created = 1;
    } else
        fd = open(file, O_RDWR);

    if (fd == -1) {
        perror("open");
        r = TEST_FAILED;
        goto err_end;
    }

    int size = 16;
    if (new_created == 1) {
        fchmod(fd, 0777);
        char *msg = (char *) malloc(size);
        if (msg == NULL) {
            r = ENOMEM;
            goto err_end;
        }

        memset(msg, 32, size-1);
        msg[size-1] = '\0';
        {
            int n = write(fd, msg, size);
            if (n == -1) {
                r = errno;
                goto err_end;
            }
        }
    }

    pagesize = getpagesize();
    char *map = (char *) mmap(addr, pagesize, MAP_PRIVATE, PROT_READ | PROT_WRITE | PROT_EXEC, fd, 0);
    if (map == NULL) {
        r = errno;
        goto err_end;
    }

    update_mapped_buf(map);

    munmap(map, pagesize);
err_end:
    if (fd != -1)
        close(fd);

    return r;
}
