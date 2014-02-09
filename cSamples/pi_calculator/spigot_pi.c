
/* avoid warning with -std=c99 */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


/* Spigot algorithms 
 * http://en.wikipedia.org/wiki/Pi#Spigot_algorithms
 **/
static float pi(unsigned long int sum_items)
{
    float sum = 0, sum_right;
    unsigned long int i = 0;

    for (i = 0 ; i < sum_items; ++i)
    {
        sum_right = (float)4/(8*i + 1)
            - (float)1/(4*i+2) 
            - (float)1/(8*i+5)
            - (float)1/(8*i+6);

        sum += (float)1/pow(16,i) * sum_right;
    }

    return sum;
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

    n = atoi(argv[1]);
    calculatedpi = pi(n);
    printf("%f\n",calculatedpi);

    return 0;
}
