#include <stdio.h>

int main(){
    int a ,b;
    printf("Enter the value of a :- ");
    scanf("%d",&a);
    printf("Enter the value of b :- ");
    scanf("%d",&b);
    printf("conditional operator example:\n");
    (a>b)?printf("a is greater than b\n"):printf("b is gretaer than a\n");
    return 0;
}