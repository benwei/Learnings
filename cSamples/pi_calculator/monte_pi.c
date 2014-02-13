
/* avoid warning with -std=c99 */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


/* reference:
 * http://stackoverflow.com/questions/8029219/pi-calculator-in-c */
static double pi(unsigned long int number_of_points_check)
{
    unsigned long int z = 0, inside = 0;
    double x, y, dist;

    srand(time(0));

    while(z < number_of_points_check)
    {
        x = rand()/(double)RAND_MAX;
        y = rand()/(double)RAND_MAX;
        dist = sqrt(pow(x,2) + pow(y,2));
        if (dist <= 1.0)
            inside++;
        z++;
    }

    /* pi = 4 * (number of hits)/(number of points checked)
     * for simple explanation of monte carlo method for pi
     * calculation see:
     * http://www.chem.unl.edu/zeng/joy/mclab/mcintro.html
     **/
    return 4*((double)inside/number_of_points_check);
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
