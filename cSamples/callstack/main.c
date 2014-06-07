#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct callstack {
    int first;
    int second;
};

int main(int argc, char **argv)
{
    struct callstack cs = {20, 10};
    printf("callstack address: argc:%p, argv:%p,"
        "cs:%p, cs.first:%p, cs:second:%p\n",
        &argc, argv,
        &cs, &cs.first, &cs.second);
    {
    struct callstack *cs_alloc = (struct callstack*) malloc(sizeof(struct callstack));
    if (cs_alloc == NULL) {
        return ENOMEM;
    }

    printf("callstack malloc address:"
        "cs:%p, cs.first:%p, cs:second:%p\n",
        &cs_alloc, &cs_alloc->first, &cs_alloc->second);
    }
    return 0;
}

