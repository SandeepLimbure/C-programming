#include <stdio.h>

int main(){
    float celsius, farhenit;
    printf("Enter temperature in celsius: ");
    scanf("%f",&celsius);
    farhenit = (celsius * 9/5) + 32;
    printf("Temperature in farhenit: %.2f\n",farhenit);
    return 0;
}