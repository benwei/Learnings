/* posix sample c project
 * written by ben6 2016-05
 */


#include <unistd.h> /* printf */
#include <stdio.h> /* printf */
#include <time.h> /* clock_gettime */

#define SECONDS_OF_DAY  86400
#define SECONDS_OF_HOUR  3600
#define SECONDS_OF_MIN     60

int main(int argc, char **argv)
{
    unsigned long days = 0, hours = 0, mins = 0, remains = 0;
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    /* tv_sec => uptime in sec */
    printf("%lu.%lu\n", tp.tv_sec, tp.tv_nsec);
    days = tp.tv_sec / SECONDS_OF_DAY;
    remains = tp.tv_sec - days * SECONDS_OF_DAY;
    hours = remains / SECONDS_OF_HOUR;
    remains %= SECONDS_OF_HOUR;
    mins = remains / SECONDS_OF_MIN;
    remains %= SECONDS_OF_MIN;
    printf("uptime %lu, days %02lu:%02lu:%02lu\n", days, hours, mins, remains);
    return 0;
}
