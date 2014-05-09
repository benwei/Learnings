#include <stdio.h>
#include <test.h>

int convert_num(ulong val, int len, int shift, char *buf)
{
    int i = 0, count=0;
    buf[len] = '\0';
    for(i = len-1; i >= 0;  --i) 
    {
        if (val == 0) {
            break;
        }
        buf[i] = (val % 10) + '0';
        val /= 10;
        ++count;
    }

    if (shift == 1) {
        int j = 0, k = i + 1;
        for(; j < count ; ++j, ++k) {
            buf[j] = buf[k];
        }

        for(;j < len; j++) {
            buf[j] = ' ';
        }
        buf[j] = '\0';
    } else {
        for(;i >= 0; --i) {
            buf[i] = ' ';
        }
    }

    return count;
}
