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
        printf("write increased id %s to mapped address\n", buf);

        while (*buf != 0 && loc < MAX_BUF_SIZE) {
            *addr++ = buf[loc++];
        }
        return 0;
}

int main(int argc, char **argv)
{
    int r = 0;

    struct fileaddr *fa = NULL;
    r = open_addr_file("file01.txt", &fa);
    if (r == -1) {
        fprintf(stderr, "errno=%d\n", errno);
        return errno;
    }

    update_mapped_buf(fa->map);

    close_addr_file(fa);

    return r;
}
