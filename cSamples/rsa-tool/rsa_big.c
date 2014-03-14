#include <stdio.h>
#include <stdlib.h> /* atoi */
#include <assert.h>
#include <stdint.h>

/*
 * Reference: http://www.codedata.com.tw/social-coding/rsa-c-implementation
 */

typedef uint64_t big_int;

static inline big_int newbig_int(char *str)
{
    return atoi(str);
}

static char tempStr[1025] = {};

static inline char *big2str(big_int a) 
{
    sprintf(tempStr, "%lld", a);
    return tempStr;
}

static inline big_int mul(big_int a, big_int b) {
    return a*b;
}

static inline big_int big_div(big_int a, big_int b) {
    return a/b;
}

static inline big_int mod(big_int a, big_int n) {
    return a%n;
}

big_int inv(big_int e, big_int r)
{
    big_int d;
    for (d=2; d<r; d++)
    {
        big_int ed = mul(e, d); // re = (e*d) % r;
        big_int re = mod(ed,r);
        if (re == 1) {
            printf("e=%lld d=%lld r=%lld (e*d) mod r=%lld\n", e, d, r, re);
            return d;
        }
    }
    assert(0);
}


big_int powerUsingMod(big_int a, big_int k, big_int N)
{
    big_int p=1, i;
    for (i=1; i<=k; i++)
    { 
        p = mul(p, a); // p = (p * a) % N;
        p = mod(p, N);
    }
    return p;
}

big_int power(big_int a, big_int k, big_int N)
{
    if (k < 0)
        assert(0);

    if (k == 0) {
        return 1;
    } else if (k == 1) {
        return a;
    }
    big_int k2 = big_div(k, 2);   // k2 = k / 2;
    big_int re = mod(k, 2);       // re = k % 2;
    big_int ak2= power(a, k2, N); // ak2 = a^(k/2);
    big_int ak = mul(ak2, ak2);   // ak  = ak2*ak2 = a^((k/2)*2)
    big_int akN= mod(ak, N);      // akN = ak % N
    if (re == 1) {               // if k is odd
        akN = mul(akN, a);       //   ak = ak*a;
        return mod(akN, N);      //   return ak * k;
    }
    return akN;                  // if k is even then return ak;
}


int main()
{
    big_int p = newbig_int("2213"), q = newbig_int("2663");
    big_int N = mul(p, q);
    big_int r = mul(p-1, q-1);
    printf("N=%s r=%s\n", big2str(N), big2str(r));
    big_int e = newbig_int("4723");
    big_int d = inv(e, r);
    big_int m = newbig_int("3320");
    printf("m=%s\n", big2str(m));
    big_int c = power(m, e, N);
    printf("c=%s\n", big2str(c));
    big_int m2 = power(c, d, N);
    printf("m2=%s\n", big2str(m2));
}
