/* tested on gcc version 4.7.2 (Debian 4.7.2-5) */
#define _POSIX_C_SOURCE 199309L /* clock_gettime */

#include <stdio.h>
#include <unistd.h> /* sleep usleep */
#include <sys/time.h> /* clock_gettime */
#include <time.h> /* clock_gettime */

/* tick()
 * reference: source http://stackoverflow.com/questions/8322782/rdtsc-too-many-cycles 
 **/
static inline unsigned long long tick()
{ 
    unsigned long long d;

        __asm__ __volatile__ ( 
            "rdtsc" 
            : "=A" (d)); 
    return d;
}

int main(int argc, char **argv)
{
    unsigned long long t1=1000, t2=2999;
    int x = 0;
    t1 = tick(); 
    printf("test1");
    t2 = tick(); 
    printf("time cost of printf: %llu\n", t2-t1);
 
    t1 = tick(); 
    x=x*x*x;
    t2 = tick(); 
    printf("time cost of x mul 3 times: %llu\n", t2-t1);
 
    t1 = tick();
    sleep(1);
    t2 = tick();
    printf("time sleep(1): %llu\n", t2-t1);

    t1 = tick();
    usleep(10);
    t2 = tick();
    printf("time usleep(10): %llu\n", t2-t1);

    {
    struct timespec ts_start, ts_end;
    clock_gettime(CLOCK_REALTIME, &ts_start);
    usleep(10);
    clock_gettime(CLOCK_REALTIME, &ts_end);
    printf("clock_getdifftime usleep(10): s: %lu ns:%lu\n", 
            ts_end.tv_sec - ts_start.tv_sec,
            ts_end.tv_nsec - ts_start.tv_nsec);
    }
    return 0;
}
