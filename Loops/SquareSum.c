#include <stdio.h>

int main(){
    int  n;
    int sum = 0;
    printf("Enter a number greater than 1. :- ");
    scanf("%d",&n);
    for(int i =1;i<=n;i++){
        sum += i*i;
    }
    printf("The sum of squares of numbers from 1 to %d is %d\n",n,sum);
    
    int SquareSum = (n*(n+1)*(2*n+1))/6;
    printf("The sum of squares of numbers from 1 to %d using formula is %d\n",n,SquareSum);
}