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
static pthread_mutex_t thread_lock = PTHREAD_MUTEX_INITIALIZER;

static void thread_monitor(struct targs *arg)
{
    printf("tid (%08lx) started\n", (long) pthread_self());
    do {
        /* without lock the up_counter will be correct */
        pthread_mutex_lock(&thread_lock);
        up_counter++;
        pthread_mutex_unlock(&thread_lock);
        printf("thread%d(%08lx) A%d %lu\n", arg->num, (long)arg->thread,  arg->counter, up_counter);
        usleep(500);
    } while (arg->counter++ < arg->max) ;
    pthread_exit(0);
}

thread_routine thread_routines[2];

int main()
{
    struct targs threads[2] = {};
    void *value = NULL;
    int i = 0;
    thread_routines[0] = (thread_routine) thread_monitor;
    thread_routines[1] = (thread_routine) thread_monitor;

    pthread_mutex_init(&thread_lock, NULL);
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
    pthread_mutex_destroy(&thread_lock);
    return 0;
}
