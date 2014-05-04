#include <stdio.h> /* printf */

typedef int (*pfcompare_t)(int, int);

static int compare_min(int left, int right)
{
    return left < right;
}

static int find(int *array, int max, pfcompare_t compare)
{
    int *array_end = (int *)(array + max);
    int i = 1, min = 0;

    for (min = *array, ++array; array < array_end; ++array, ++i) {
        printf("compare min(%2d) and a%d[%2d]\n", min, i, *array);
        if (compare(*array, min) == 1) {
            min = *array;
        }
    }
    return min;
}

int main(int argc, char **argv)
{
    int input_array[] = {6, 9, 1, 3, 8, 7, 6, 4, 2, 0, 10};

    int min = find(input_array, sizeof(input_array)/sizeof(input_array[0]), &compare_min); 
    printf("the minmum value is %d\n", min);
    return 0;
}
