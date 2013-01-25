#include <stdio.h>

int main() {
    int c = 2;
    int a = c++ + 3;
    --c;
    int b = ++c + 3;
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    return 0;
}
