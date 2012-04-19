#include <stdio.h>

extern int verbose;
#define dmsg(fmt, arg1) { if (verbose) printf(fmt, arg1); }

int run(const char *s);

