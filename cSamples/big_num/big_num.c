/*
 * source: http://openhome.cc/Gossip/AlgorithmGossip/BigNumber.htm
 * ben6: refined code with meaningful name
 **/

#include <stdio.h> 
#include <stdlib.h>

#define N 8

void add(int*, int*, int*);
void subtract(int*, int*, int*);
void multiply(int*, int, int*);
void divide(int*, int, int*);
void to_complement(int*, int*);
void absolute_value(int*, int*); 
void print_big_num(int*);

int main(void) { 
    int a[] = {0, 0, 0, 1234, 5678, 9910, 1923, 1124};
    int b[] = {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9901}; // -99
    int c1[N], c2[N], c3[N], c4[N] = {0};

    add(a, b, c1);       print_big_num(c1);
    subtract(a, b, c2);  print_big_num(c2);
    multiply(a, -3, c3); print_big_num(c3);
    divide(a, -3, c4);   print_big_num(c4);

    return 0; 
} 

void add(int* a, int* b, int* c) { 
    if(b[0] == 9999) {
        int comp[N] = {0};
        to_complement(b, comp);
        subtract(a, comp, c);
    } else {
        int i, carry = 0; 
        for(i = N - 1; i >= 0; i--) {
            c[i] = a[i] + b[i] + carry; 
            if(c[i] < 10000) {
                carry = 0; 
            } else { // 進位 
                c[i] = c[i] - 10000; 
                carry = 1; 
            } 
        } 
    }
} 

void subtract(int* a, int* b, int* c) {
    if(b[0] == 9999) {
        int comp[N] = {0};
        to_complement(b, comp);
        add(a, comp, c);
    } else {
        int i, borrow = 0; 
        for(i = N - 1; i >= 0; i--) { 
            c[i] = a[i] - b[i] - borrow; 
            if(c[i] >= 0) {
                borrow = 0;
            } else { // 借位 
                c[i] = c[i] + 10000; 
                borrow = 1; 
            } 
        } 
    }
} 

void multiply(int* multiplicand, int multiplier, int* c) { // b 為乘數
    int op1[N] = {0};
    int op2 = abs(multiplier);
    absolute_value(multiplicand, op1);

    int i, tmp, carry = 0; 
    for(i = N - 1; i >= 0; i--) { 
        tmp = op1[i] * op2 + carry; 
        c[i] = tmp % 10000;    
        carry = tmp / 10000; 
    }

    if((multiplicand[0] == 9999 && multiply > 0) || (multiplicand[0] == 0 && multiply < 0)) {
        to_complement(c, c);
    }
} 

void divide(int* dividend, int divisor, int *c) {
    int op1[N] = {0}; absolute_value(dividend, op1);
    int op2 = abs(divisor);

    int i, tmp, remain = 0; 
    for(i = 1; i < N; i++) { 
        tmp = op1[i] + remain;
        c[i] = tmp / op2; 
        remain = (tmp % op2) * 10000; 
    }

    if((dividend[0] == 9999 && divisor > 0) || (dividend[0] == 0 && divisor < 0)) {
        to_complement(c, c);
    }    
}

void to_complement(int* src, int* comp)
{
    int j;
    for(j = 0; j < N; j++) {
        comp[j] = 9999 - src[j];
    }
    comp[N - 1] += 1;
}

void absolute_value(int* src, int* op)
{
    if(src[0] == 9999) {
        to_complement(src, op);
    } else {
        int i;
        for(i = 0; i < N; i++) {
            op[i] = src[i];
        }
    }
}

void print_big_num(int* c)
{
    int v[N] = {0}; absolute_value(c, v);

    if(c[0] == 9999) {
        printf("-");
    }

    int isDropZero = 1;
    int i;
    for(i = 0; i < N; i++) {
        char s[5] = {'\0'};
        sprintf(s, "%04d", v[i]);
        if(isDropZero) {
            int j;
            for(j = 0; s[j] == '0' && j < 4; j++);
            if(j < 4) {
                isDropZero = 0;
                for(; j < 4; j++) {
                    printf("%c", s[j]);
                }
            } else if(i == N - 1) {
                printf("0");
            }
        } else {
            printf(s);
        }
    }
    printf("\n");
}
