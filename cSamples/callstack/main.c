#include <stdio.h>
#include <stdlib.h>

struct callstack {
    int first;
    int second;
};

int main(int argc, char **argv)
{
    struct callstack cs = {20, 10};
    struct callstack *csm = (struct callstack*) malloc(sizeof(struct callstack));
    printf("callstack address: argc:%p, argv:%p,"
        "cs:%p, cs.first:%p, cs:second:%p\n",
        &argc, argv,
        &cs, &cs.first, &cs.second);
    printf("callstack malloc address:"
        "cs:%p, cs.first:%p, cs:second:%p\n",
        &csm, &csm->first, &csm->second);

    return 0;
}

