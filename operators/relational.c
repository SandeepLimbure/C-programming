#include <stdio.h>

int main(){
    int a = 6;
    int b = 4;
    printf("Relational Operators:\n");
    printf("%d > %d : %d\n", a, b, a > b);   // Greater than
    printf("%d < %d : %d\n", a, b, a < b);   // Less than
    printf("%d >= %d : %d\n", a, b, a >= b); // Greater than or equal to
    printf("%d <= %d : %d\n", a, b, a <= b); // Less than or equal to
    printf("%d == %d : %d\n", a, b, a == b); // Equal to
    printf("%d != %d : %d\n", a, b, a != b); // Not equal to
    return 0;
}