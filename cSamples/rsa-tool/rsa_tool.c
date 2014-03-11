
/*
 * Reference: http://www.codedata.com.tw/social-coding/rsa-c-implementation
 *
 * RSA 的加解密原理
 *
 * RSA 加解密的關鍵是質數問題，利用對 N 取餘數所形成的整數場之特性，設計出了如下的演算法：
 * 1. 任取兩個質數 p, q ，令 N = p*q
 * 2. 設定 r 為 (p-1, q-1) 兩數的公倍數，通常直接使用 r=(p-1)*(q-1)。
 * 3. 取一個與 r 互質的數 e 做為加密密鑰。
 * 4. 找出 e 在 mod r 下的反元素 d，使得 e*d = 1 mod r
 * 5. 以 (N, e) 為私鑰，(N, d) 為公鑰，將 (N, d) 公開給解密者，但 (N, e) 則需自己留著保密。
 * 6. 假如明文的某個區塊為 m，加密時透過 m 與 e 計算出 c=m^e mod N 得到密文。
 * 7. 解密者用 m2 = c^d mod N 的方式解出 c 的密文 m2，該 m2 必然會是原本的訊息 m，也就是 m2=m。
 **/

#include <stdio.h>
#include <assert.h>
#include <stdint.h>
 
#define BigInt uint64_t
 
BigInt inv(BigInt e, BigInt r) {
  BigInt d;
  for (d=2; d<r; d++) {
      BigInt re = (e*d) % r;
      if (re == 1) {
            printf("e=%lld d=%lld r=%lld (e*d) mod r=%lld\n", e, d, r, re);
            return d;
          }
    }
  assert(0);
}
 
BigInt power(BigInt a, BigInt k, BigInt N) {
  BigInt p=1, i;
  for (i=1; i<=k; i++) { 
      p = (p*a)%N;
    }
  return p;
}
 
int main() {
  BigInt p =  2213, q = 2663;
  BigInt N = p*q;
  BigInt r = (p-1)*(q-1);
  printf("N=%lld r=%lld\n", N, r);
  BigInt e = 4723;
  BigInt d = inv(e, r);
  BigInt m = 3320;
  printf("m=%lld\n", m);
  BigInt c = power(m, e, N);
  printf("c=%lld\n", c);
  BigInt m2 = power(c, d, N);
  printf("m2=%lld\n", m2);
}

