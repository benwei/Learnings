/* tested on gcc version 4.7.2 (Debian 4.7.2-5) */
/* checked not support on OSX darwin */
#define _POSIX_C_SOURCE 199309L /* clock_gettime */

#include <stdio.h>
#include <unistd.h> /* sleep usleep */
#include <sys/time.h> /* clock_gettime */
#include <time.h> /* clock_gettime */

#ifdef CLOCK_REALTIME
#define INIT_CLOCK_GETTIME(suffix) \
    struct timespec ts_base_##suffix, ts_end_##suffix;
#define CLOCK_GETTIME_START(suffix) \
    clock_gettime(CLOCK_REALTIME, &ts_base_##suffix);
#define CLOCK_GETTIME_END(suffix) { \
    clock_gettime(CLOCK_REALTIME, &ts_end_##suffix); \
            ts_end_##suffix.tv_sec -= ts_base_##suffix.tv_sec ; \
            ts_end_##suffix.tv_nsec -= ts_base_##suffix.tv_nsec ; }
#define CLOCK_GETTIME_DIFF_SEC(suffix)  ts_end_##suffix.tv_sec
#define CLOCK_GETTIME_DIFF_NSEC(suffix) ts_end_##suffix.tv_nsec
#endif

#define INIT_RDTSC(suffix) \
    unsigned long long tick_base_##suffix, tick_end_##suffix;
#define RDTSC_START(suffix) \
    tick_base_##suffix = tick();
#define RDTSC_END(suffix) { \
    tick_end_##suffix = tick(); \
    tick_end_##suffix -= tick_base_##suffix; }
#define RDTSC_DIFF_TICK(suffix) tick_end_##suffix


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
    INIT_RDTSC(test);
    int x = 0;

    RDTSC_START(test);
    printf("test1");
    RDTSC_END(test);
    printf("time cost of printf: %llu\n", RDTSC_DIFF_TICK(test));
 
    RDTSC_START(test);
    x=x*x*x;
    RDTSC_END(test);
    printf("time cost of x mul 3 times: %llu\n", RDTSC_DIFF_TICK(test));
 
    RDTSC_START(test);
    sleep(1);
    RDTSC_END(test);
    printf("time sleep(1): %llu\n", RDTSC_DIFF_TICK(test));

    RDTSC_START(test);
    usleep(10); /* warning in C99 */
    RDTSC_END(test);
    printf("time usleep(10): %llu\n", RDTSC_DIFF_TICK(test));

#ifdef CLOCK_REALTIME
    {
    INIT_CLOCK_GETTIME(test_usleep);
    CLOCK_GETTIME_START(test_usleep);
    usleep(10);
    CLOCK_GETTIME_END(test_usleep);
    printf("clock_getdifftime usleep(10): s: %lu ns:%lu\n", 
            CLOCK_GETTIME_DIFF_SEC(test_usleep),
            CLOCK_GETTIME_DIFF_NSEC(test_usleep));
    }
#endif /* CLOCK_REALTIME */
    return 0;
}
