#include <stdio.h>
#include <math.h>
#include <stdbool.h>


bool isPrime(int num){
    int i;
    for(i=2;i<=sqrt(num);i++){
         if(num%i==0){
            return false;
         }
    }
    return true;
}

int main(){
    for(int i =2;i<100;i++){
        if(isPrime(i)){
            printf("%d ",i);
        }
    }
}

