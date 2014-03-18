#include <stdio.h> /* printf */

int find_min(int *array, int max)
{
    int *array_end = (int *)(array + max);
    int i = 1, min = 0;

    for (min = *array, ++array; array < array_end; ++array, ++i) {
        printf("compare min(%2d) and a%d[%2d]\n", min, i, *array);
        if (*array < min) {
            min = *array;
        }
    }
    return min;
}

int main(int argc, char **argv)
{
    int input_array[] = {6, 9, 1, 3, 8, 7, 6, 4, 2, 0, 10};

    int min = find_min(input_array, sizeof(input_array)/sizeof(input_array[0])); 
    printf("the minmum value is %d\n", min);
    return 0;
}
