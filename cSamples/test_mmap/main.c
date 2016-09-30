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
#include <stdio.h> /* DMSG */
#include <stdlib.h> /* atol */
#include <string.h> /* memset */
#include <sys/types.h>
#include <sys/mman.h> /* mmap */
#include <errno.h>
#include "filemap.h"
#include <arpa/inet.h>

static int verbose = 0;

#define MAX_BUF_SIZE 16
typedef struct _args {
    const char *filename;
    int mode;
    int num;
    int monitor;
} args_t;

#define FM_E_INVALID_PARAM 1

#define MP_RELEASE_MAP     1
#define MP_READ_NUM        2
#define MP_SET_NUM         3

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvariadic-macros"

#define DMSG(fmt, args ...) {if (verbose){ printf(fmt, ##args); }}
#define DERR(fmt, args ...) {if (verbose){ fprintf(stderr, fmt, ##args); }}

#pragma GCC diagnostic pop

long get_num_from_buf(char *addr)
{
    return ntohl(*(unsigned long*)addr);
}

#define MAX_NUM_LENGTH 16

int update_mapped_buf(char *addr, int num)
{
    long l = get_num_from_buf(addr);
    long m = 0;
    if (num <= 0) {
        num = 1;
    }
    DMSG("%ld->%ld\n", l, l+num);
    l+=num;
    m = htonl(l);

    DMSG("write increased [%lu] to mapped address\n", l);
    memcpy(addr, &m, sizeof(m));

    return 0;
}

#define FAIL_IF(x, r) do { if (x) { \
    rc = r; \
    break; }} while(0);

void syntax(char **argv)
{
    DMSG("%s syntax: -f <map file> | -u | -r | -s <num>\n", argv[0]);
}

int parse_args(int argc, char **argv, args_t *pa)
{
    int i = 1;
    int rc = 1;
    if (argc == 1)
        syntax(argv);

    for (; i < argc ; i++) {
        char first = argv[i][0];
        if (first != '-') {
            continue;
        }

        switch(argv[i][1])
        {
            case 'm': /* monitor mode */
                pa->monitor = 1;
                break;
            case 'f': /* filename */
                FAIL_IF(++i > argc, FM_E_INVALID_PARAM);
                pa->filename = argv[i];
                break;
            case 'u': /* release map*/
                pa->mode = MP_RELEASE_MAP;
                break;
            case 'r': /* release map*/
                pa->mode = MP_READ_NUM;
                rc = 0;
                break;
            case 's':
                pa->mode = MP_SET_NUM;
                if (i+1 <= argc && argv[i+1][0]!='-') {
                    int v = atoi(argv[++i]);
                    pa->num = v;
                } else {
                    pa->num = -1;
                }
                rc = 0;
                break;
            default:
                syntax(argv);
                return FM_E_INVALID_PARAM;
        };
    }
    return rc;
}

int do_action(args_t *pa, struct fileaddr *fa)
{
    int rc = 0;

    switch(pa->mode) {
        case MP_RELEASE_MAP:
            break;
        case MP_READ_NUM:
            do {
                long l = get_num_from_buf(fa->map);
                printf("%ld\n", l);
            } while(pa->monitor);
            break;
        case MP_SET_NUM:
            rc = update_mapped_buf(fa->map, pa->num);
            break;
    }

    return rc;
}

int main(int argc, char **argv)
{
    int rc = 0;
    args_t args = {0};
    struct fileaddr *fa = NULL;

    args.num = -1;

    if ((rc = parse_args(argc, argv, &args)) != 0) {
        return rc;
    }

    rc = open_addr_file(args.filename, &fa);
    if (rc == -1) {
        DERR("errno=%d\n", errno);
        return errno;
    }

    rc = do_action(&args, fa);

    close_addr_file(fa);

    return rc;
}
