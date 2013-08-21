#include <stdio.h>
#include <unistd.h> /* usleep */
#include <pthread.h>

struct targs {
    pthread_t thread;
    int num;
    int counter;
};

typedef void *(*thread_routine)(void *);

void thread_monitor(struct targs *arg)
{
    do {
        printf("thread%d(%08lx) A%d\n", arg->num, (long)arg->thread,  arg->counter);
        usleep(500);
    } while (arg->counter++ < 10) ;
}

int main()
{
    struct targs ta = {};
    void *value = NULL;
    printf("thread creation\n");
    ta.num = 1;
    ta.counter = 1;
    pthread_create(&ta.thread, NULL, (thread_routine) thread_monitor, &ta);
    pthread_join(ta.thread, &value);
    return 0;
}
