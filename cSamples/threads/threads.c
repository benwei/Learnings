#include <stdio.h>
#include <unistd.h> /* usleep */
#include <pthread.h>

struct targs {
    pthread_t thread;
    int num;
    int counter;
    int max;
};

static unsigned long up_counter = 0;

typedef void *(*thread_routine)(void *);

static void thread_monitor(struct targs *arg)
{
    do {
        /* without lock the up_counter will be correct */
        up_counter++;
        printf("thread%d(%08lx) A%d %lu\n", arg->num, (long)arg->thread,  arg->counter, up_counter);
        usleep(500);
    } while (arg->counter++ < arg->max) ;
}

int main()
{
    struct targs threads[2] = {};
    void *value = NULL;
    int i = 0;
    for (i = 0; i < 2; i++) {
        struct targs *ta = &threads[i];
        printf("thread %d created\n", i);
        ta->num = i;
        ta->counter = 1;
        ta->max = 5;
        pthread_create(&ta->thread, NULL, (thread_routine) thread_monitor, ta);
    }

    for (i = 0; i < 2; i++) {
        struct targs *ta = &threads[i];
        pthread_join(ta->thread, &value);
    }
    return 0;
}
