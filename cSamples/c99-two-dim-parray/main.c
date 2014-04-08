/* written by ben6 2014
 **/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define ALLOC_TWO_DIMENSIONS_ARRAY(varname, type, row, col) \
    int (*varname)[col] = malloc(row*col*sizeof(type));

#define FREE_TWO_DIMENSIONS_ARRAY(varname) { \
    if (varname) free(varname); \
    }

static void dump_2d_addr(int *array2d, int row, int col)
{
    int i=0, j=0;
    int *p = array2d;
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j, p++)
        {
            printf("dump->2d[%d][%d]=%p\n", i, j, p);

        }
    }
}

static void dump_2d_table(int *array2d, int row, int col)
{
    int i=0, j=0;
    printf(" c");
    for (j = 0; j < col; ++j)
        printf(" %2d", j);
    printf("\nr ------------\n");
    for (i = 0; i < row; ++i)
    {
        printf("%d:", i);
        for (j = 0; j < col; ++j, array2d++)
        {
            printf(" %2d", *(array2d));
        }
        printf("\n");
    }
}

int main()
{
    int i=0, j=0;
    int row = 3, col = 4;
    int counter = 0;
    ALLOC_TWO_DIMENSIONS_ARRAY(array2d, int, row, col);
    if (!array2d)
    {
        printf("malloc failure: errno=%d\n", errno);
        return 1;
    }

    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; j++) {
            /*
             (*(array2d+i))[j] = ++counter;
             * same as bellow */
            /* allow access values in 2 dimensions array by [row][col] style */
            array2d[i][j] = ++counter;
            printf("2d[%d][%d]=%p\n", i, j, &array2d[i][j]);
        }
    }

    dump_2d_addr((int *)array2d, row, col);
    dump_2d_table((int *)array2d, row, col);
    
    FREE_TWO_DIMENSIONS_ARRAY(array2d);
    return 0;
}
