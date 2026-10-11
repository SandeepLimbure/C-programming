#include <stdio.h>

int main(){
    int principal,rate,time;
    printf("enter the principal amount : ");
    scanf("%d",&principal);
    printf("enter the rate of interest : ");
    scanf("%d",&rate);
    printf("enter the time period : ");
    scanf("%d",&time);
    float simpleInterest = (principal*rate*time)/100.0;
    printf("the simple Interest : %.3f",simpleInterest);
    return 0;
}