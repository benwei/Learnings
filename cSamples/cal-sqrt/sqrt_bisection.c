#include <stdlib.h> /* abs */
#include "test.h"

/* source:http://diducoder.com/sotry-about-sqrt.html 
 * Sqrt by Bisection
 **/

float testcase_sqrt(float x, float precision) 
{ 
    float mid = 0,last = 0, low = 0,up = 0; 
    if(x < 0)
        return x; 

    up = x; 
    mid = (low + up) / 2; 

    do
    {
        if (mid*mid  > x)
            up = mid; 
        else 
            low = mid;
        last = mid;
        mid = (up + low) / 2; 
    } while (abs(mid - last) > precision);

    return mid; 
}
