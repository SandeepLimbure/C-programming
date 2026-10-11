#include <stdio.h>

int main(){
    printf("Bitwise Operators:\n");
    int a = 4;
    int b =3;
    printf("a & b : %d\n",a & b); // bitwise AND
    printf("a | b : %d\n",a | b); // bitwise OR     
    printf("a ^ b : %d\n",a ^ b); // bitwise XOR
    printf("~a : %d\n",~a);       // bitwise NOT
    printf("b << 1 : %d\n",b << 1); // left shift
    printf("b >> 1 : %d\n",b >> 1); // right shift
    return 0;
}