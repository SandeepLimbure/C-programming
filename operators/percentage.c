#include <stdio.h>

int main(){
    int a,b,c,d,e;
    printf("enter the marks in five subjects :");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    int total = a+b+c+d+e;
    float percentage = (total/500.0)*100;
    printf("the percentage is : %.2f",percentage);
    return 0;
}