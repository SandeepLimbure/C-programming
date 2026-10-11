#include <stdio.h>

int main(){
    int num;
    printf("Enter a number greater than 1. :- ");
    scanf("%d",&num);
    int div = 3;
    for(int i = 1;i<=num;i++){
        if(i%div==0){
            printf("the cube of %d is = %d\n",i,i*i*i);
        }
    }
}