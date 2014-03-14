#include <stdlib.h> /* abs */
#include "test.h"

/* source:http://diducoder.com/sotry-about-sqrt.html 
 * Sqrt by Newton
 **/

float testcase_sqrt(float x, float precision) 
{ 
    float val = x, last;
    do
    {
        last = val;
        val =(val + x/val) / 2;
    }
    while(abs(val-last) > precision);

    return val;
}
