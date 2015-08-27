/* @brief shared lib sample c project
 * written by ben6 2015-08
 */

#include <stdio.h> /* printf */
#include "foo.h"

int main(int argc, char **argv)
{
    int r = 0;
    int success_counter = 0, error_counter = 0;
    foo_banner();
    r = foo_max(1, 2);
    if (r == 2) {
        success_counter++;
    } else {
        error_counter++;
    }

    r = foo_min(3,5);
    if (r == 3) {
        success_counter++;
    } else {
        error_counter++;
    }
    
    printf("pass:%d,fail:%d,total:%d\n",
            success_counter, error_counter,
            success_counter+error_counter);
    return 0;
}
