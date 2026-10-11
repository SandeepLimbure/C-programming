#include <stdio.h>

int main(){
    int a = 14;
    int b = 5;
    // unary operators
    printf("Unary Operators:\n");
    printf("Positive a: %d\n", +a);
    printf("Negative b: %d\n", -b);
    // binary operators
    printf("Binary Operators:\n");
    int c = 12;
    int d = 4;
    printf("Addition : %d + %d = %d\n",c,d,c+d);
    printf("Subtraction  : %d - %d = %d\n",c,d,c-d);
    printf("Multiplication : %d * %d = %d\n",c,d,c*d);
    printf("Division : %d / %d = %d\n",c,d,c/d);
    printf("Modulo : %d %% %d = %d\n",c,d,c%d); // modulo operator can't be used for floating point numbers.
    return 0;
}