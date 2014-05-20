/* reference: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=616634
 * written by ben6 2014-05
 * test on: osx 10.9.2
 * Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
 * Apple LLVM version 5.1 (clang-503.0.40) (based on LLVM 3.4svn)
 * Target: x86_64-apple-darwin13.1.0
 * Thread model: posix
 *
 * Using -Werror with -pedantic to catch constructs the standard does not
permit
 **/

#include <stdio.h>  /* printf */
#include <stdlib.h> /* calloc, free*/
#include <string.h> /* memcpy */
#include <errno.h>

#if 0
/* for display warning
 * warning: flexible array members are a C99 feature
 *       [-Wc99-extensions]
 */
 exec make USE_C89=1
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

    /* include string.h cause the argument 2 macro expension failure
     * too many arguments provided to function-like macro invocation
       memcpy (myflex,
            &(foo const){.dummy=89,.flex_size=myflex_size},
            sizeof(foo));
     */

    const foo foo_base = {.dummy=89,.flex_size=myflex_size};
    memcpy (myflex, &foo_base, sizeof(foo));
    memcpy (myflex->flex, flex, sizeof(flex));

    printf("mytest.dummy=%d, .flex=%s\n", myflex->dummy, myflex->flex);

    free(myflex);
    return 0;
}
