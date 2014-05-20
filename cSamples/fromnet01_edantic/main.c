/* reference: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=616634
 * ben6 2014-05
 * test on: osx 10.9.2
 * Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
 * Apple LLVM version 5.1 (clang-503.0.40) (based on LLVM 3.4svn)
 * Target: x86_64-apple-darwin13.1.0
 * Thread model: posix
 *
 Using -Werror with -pedantic to catch constructs the standard does not
permit
 
 **/

#include <stdio.h>  /* printf */
#include <stdlib.h> /* calloc, free*/
#include <errno.h>

#if 0
exec gcc -c -std=c89 -pedantic "$0" "$@"
#else
typedef struct foo {
    int dummy;
    int flex_size;
    char flex[];
} foo;
#endif

int main()
{
    char flex[] = "flexible array";
    int myflex_size = sizeof(foo) + sizeof(flex);
    foo *myflex = calloc(myflex_size, 1);
    if (myflex == NULL)
        return ENOMEM;
    memcpy (myflex, &(foo const){.dummy=89,.flex_size=myflex_size}, sizeof(foo));
    memcpy (myflex->flex, flex, sizeof(flex));
    printf("mytest.dummy=%d, .flex=%s\n", myflex->dummy, myflex->flex);

    free(myflex);
    return 0;
}
