#include <stdio.h>
#include <time.h>
#include <stdlib.h> /* rand() */
#include <sys/time.h> /* gettimeofday() */

int main()
 {
     struct timeval time = {0}; 

     // avoid the follow once without srand()
     // you will get the same number each run
     printf("only rand %8d\n", rand());

     gettimeofday(&time,NULL);
     // microsecond has 1 000 000
     // Assuming you don't need quite that accuracy
     // Also don't assume system clock that accuracy.
     // use srand in advance to increase the randomability of number
     srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
     // it is bad to user rand, just try to generate it for testing
     printf("with srand: %8d\n", rand());

     return 0;
 }

/** testing on macos
ciMMBP:cSamples ci$ uname -a
Darwin ciMMBP.localdomain 22.1.0 Darwin Kernel Version 22.1.0: Sun Oct  9 20:15:09 PDT 2022; root:xnu-8792.41.9~2/RELEASE_ARM64_T6000 arm64

ciMMBP:cSamples ci$ ./a.out
only rand    16807
with srand: 1998294494
ciMMBP:cSamples ci$ ./a.out
only rand    16807
with srand: 2033236247
ciMMBP:cSamples ci$ ./a.out
only rand    16807
with srand: 2052816402
ciMMBP:cSamples ci$ ./a.out
only rand    16807
with srand: 2068682210
ciMMBP:cSamples ci$ ./a.out
only rand    16807
with srand: 2092195203

*/
