#include <stdio.h>

int main(){
    int a = 10;
    int b = 5;
    printf("Assignment Operators:\n");
    printf("Initial values: a = %d, b = %d\n", a, b);

    a += b; // a = a + b
    printf("After a += b: a = %d\n", a);

    a -= b; // a = a - b
    printf("After a -= b: a = %d\n", a);

    a *= b; // a = a * b
    printf("After a *= b: a = %d\n", a);

    a /= b; // a = a / b
    printf("After a /= b: a = %d\n", a);

    a %= b; // a = a % b
    printf("After a %%= b: a = %d\n", a);

    return 0;
}

