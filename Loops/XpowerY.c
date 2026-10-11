#include <stdio.h>

int main(){
    int x,y;
    printf("Enter a positive number to store in X :- ");
    scanf("%d",&x);
    printf("Enter a positive number to store in Y :- ");
    scanf("%d",&y);
    int power  = 1;
    int n = y; // Store original value of y for printing
    while(y!=0){
        power *= x;
        y--;
    }
    printf("%d raised to the power %d is %d\n",x,n,power);
}