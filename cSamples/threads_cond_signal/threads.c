/* \file threads.c
 * \brief an example that producer and workers handle tasks.
 * using pthread_cond_signal and pthread_cond_wait
 * to implement the notify and receive mechanism. 
 * \note: written by ben6 2014.05
 **/

#include <stdio.h>
#include <unistd.h> /* usleep */
#include <pthread.h>

struct targs {
    pthread_t thread;
    pthread_cond_t *cond;
    int num;
    int counter;
    int max;
};

static unsigned long up_counter = 0;

typedef void *(*thread_routine)(void *);
static pthread_mutex_t thread_lock = PTHREAD_MUTEX_INITIALIZER;

#define MAX_TASKS 10
#define MAX_WORKERS 10
#define MAX_RUNNING_THREADS MAX_WORKERS + 1
static int work_wait_exit_counter = MAX_WORKERS;

thread_routine thread_routines[MAX_RUNNING_THREADS];
static int task_queue_count = 0;

static int new_task_to_queue(void)
{
    task_queue_count++;
    return 0;
}

static int task_queue_empty(void)
{
    return task_queue_count == 0;
}

static int worker_can_go_home = 0;
int go_home_now(void) 
{
    return worker_can_go_home == 1;
}

static void thread_producer(struct targs *arg)
{
    printf("producer tid (%08lx) started\n", (long) pthread_self());
    do {
        /* without lock the up_counter will be correct */
        pthread_mutex_lock(&thread_lock);
        new_task_to_queue();
        pthread_cond_signal(arg->cond);
        printf("producer t%d(%08lx) A%d: add new tasks\n", arg->num, (long)arg->thread,  arg->counter);
        pthread_mutex_unlock(&thread_lock);
        usleep(500);
    } while (arg->counter++ < arg->max) ;

    while (work_wait_exit_counter > 0) {
        pthread_mutex_lock(&thread_lock);
        worker_can_go_home = 1;
        pthread_cond_signal(arg->cond);
        printf("producer t%d(%08lx) A%d: said: workers can go home now.\n", arg->num, (long)arg->thread,  arg->counter);
        pthread_mutex_unlock(&thread_lock);
        usleep(500);
    }

    printf("producer t%d(%08lx) A%d exited\n", arg->num, (long)arg->thread,  arg->counter);
    pthread_exit(0);
}

static void handle_task()
{
    up_counter++;
    task_queue_count--;
}

static void thread_worker(struct targs *arg)
{
    printf("worker%d tid (%08lx) started\n", arg->num, (long) pthread_self());
    do {
        /* without lock the up_counter will be correct */
        pthread_mutex_lock(&thread_lock);
        /* condition 1: while new task is added, producer will notify worker to 
         * handle new task.
         * condition 2: producer notify to stop, worker went back */
        while(task_queue_empty() && ! go_home_now()) {
            pthread_cond_wait(arg->cond, &thread_lock);
        }

        if (go_home_now()) {
            pthread_mutex_unlock(&thread_lock);
            break;
        }

        handle_task();

        printf("worker%d (%08lx) A%d: handled %lu task(s)\n", arg->num, (long)arg->thread,  arg->counter, up_counter);
        pthread_mutex_unlock(&thread_lock);
        usleep(500);
    } while (arg->counter++ < arg->max) ;
    printf("worker%d (%08lx) A%d exited\n", arg->num, (long)arg->thread,  arg->counter);

    pthread_mutex_lock(&thread_lock);
    work_wait_exit_counter--;
    pthread_mutex_unlock(&thread_lock);
    pthread_exit(0);
}


int main()
{
    struct targs threads[MAX_RUNNING_THREADS] = {};
    void *value = NULL;
    int i = 0;
    pthread_cond_t cond;
    pthread_cond_init(&cond, NULL);
    thread_routines[0] = (thread_routine) thread_producer;
    for (i = 1; i < MAX_RUNNING_THREADS; ++i) {
        thread_routines[i] = (thread_routine) thread_worker;
    }

    pthread_mutex_init(&thread_lock, NULL);
    for (i = 0; i < MAX_RUNNING_THREADS; i++) {
        struct targs *ta = &threads[i];
        printf("thread %d created\n", i);
        ta->num = i;
        ta->counter = 1;
        ta->max = 5;
        ta->cond = &cond;
        pthread_create(&ta->thread, NULL, (thread_routine) thread_routines[i], ta);
    }

    for (i = 0; i < 2; i++) {
        struct targs *ta = &threads[i];
        pthread_join(ta->thread, &value);
    }
    pthread_mutex_destroy(&thread_lock);
    printf("everyone exited.\n");
    return 0;
}
