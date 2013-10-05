#include <stdio.h>
#include "hello_dep.h"

int main(int argc, char **argv)
{
    const char *guy = TEXT_DEFAULT_NAME;
    if (argc >= 2) {
        guy = argv[1];
    }
	printf("%s %s!\n", TEXT_HELLO, guy);
	return 0;
}
