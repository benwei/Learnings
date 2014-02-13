
/* avoid warning with -std=c99 */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


/* Calculate The Value Of Pi Using Infinite Series
 * http://www.dreamincode.net/forums/topic/99268-calculate-the-value-of-pi-using-infinite-series/
 **/
static double pi(unsigned long int sum_items)
{
    double pi = 4;
    unsigned long int i = 0;
    unsigned long counter = 0;
    for (i = 3 ; i <= sum_items; i+=2)
    {
        if (counter % 2 == 0) {
            pi -=  4.0 / (double) i;
        } else {
            pi += 4.0 / (double) i;
        }
        counter++;
    }
    return pi;
}

static void syntax(char **argv)
{
    char *exename = strrchr(argv[0], '/');
    if (!exename) 
        exename = argv[0];
    else
        ++exename;

    printf("syntax: <number of points checked>\n"
            "ex: %s 99999\n", exename);
}

int main(int argc, char **argv)
{
    unsigned long int n = 0;
    double calculatedpi;

    if (argc < 2)
    {
        syntax(argv);
        return 1;
    }

    n = atol(argv[1]);
    calculatedpi = pi(n);
    printf("%f\n",calculatedpi);

    return 0;
}
