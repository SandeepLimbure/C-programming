#include <stdio.h>

int main(){
    int num,digit;
    printf("Enter a number :- ");
    scanf("%d",&num);
    printf("Enter a digit :- ");
    scanf("%d",&digit);
    int count = 0;
    while(num!=0){
        int rem = num%10;
        if(rem==digit){
            count++;
        }
        num /= 10;
    }
    printf("The digit %d occurs %d times\n",digit,count);
}