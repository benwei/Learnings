#include <stdlib.h> /* abs */
#include "test.h"

/* 
 * Sqrt by Inv
 * source:http://diducoder.com/sotry-about-sqrt.html 
 * paper: http://www.math.purdue.edu/~clomont/Math/Papers/2003/InvSqrt.pdf
 **/
float testcase_sqrt(float x, float precision) 
{ 
    float xhalf = 0.5f*x;
    // warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
    int i = *(int*)&x; // get bits for floating VALUE 
    i = 0x5f375a86- (i>>1); // gives initial guess y0
    x = *(float*)&i; // convert bits BACK to float
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy

    return 1/x;
}
