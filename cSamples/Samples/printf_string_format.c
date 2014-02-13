
/* http://stackoverflow.com/questions/293438/left-pad-printf-with-spaces */
#include<stdio.h>

#define MAX_BUF_LEN 5

typedef void (*format_callback)(unsigned int size, const char *buf);

void print_ascii_shape(format_callback cb)
{
    int i, j;
    char buf[MAX_BUF_LEN+1] = {0};
    for (j = 1; j <= MAX_BUF_LEN; ++j) {
        for (i = 0; i < j; ++i) {
            buf[i] = '*';
        }
        buf[i] = '\0';
        cb(MAX_BUF_LEN, buf);
    }
}

void shape_leftside_format_callback(unsigned int size, const char *buf)
{
    printf("%*.*s\n", size, size, buf);
}

void shape_rightside_format_callback(unsigned int size, const char *buf)
{
    /* aother method
    char fmt[5] = {0};
    snprintf(fmt, sizeof(fmt),"%%%ds\n", size);
    printf(fmt, buf);
    */
    printf("%*.*s\n", 1, size, buf);
}

int main()
{

    printf("%-5s\n","123");
    /* aa... */
    printf("%5s\n","456");
    /* ...aa */
    print_ascii_shape(shape_leftside_format_callback);
    print_ascii_shape(shape_rightside_format_callback);
/* print result of this program
./testfmt
123  
  456
    *
   **
  ***
 ****
*****
*
**
***
****
*****

*/
    return 0;
}

