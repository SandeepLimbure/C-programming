#include <stdio.h>

int main(){
    int a,b,c,sum;
    sum = (a=6,b=8,c=10,a+b+c);
    printf("value of sum is = %d",sum);
    return 0;
}