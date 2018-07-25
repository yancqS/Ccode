#include <stdio.h>

int main() {
    int a, b, t;
    a = 5;
    b = 6;
    printf("a=%d,b=%d\n", a, b);
    printf("=============\n");
    t = a;
    a = b;
    b = t;
    printf("a=%d,b=%d", a, b);
    return 0;
}