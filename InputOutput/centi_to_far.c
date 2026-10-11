#include <stdio.h>

int main(void)
{
    float celsius, farhenit;
    printf("Enter the temperature in celsius : ");
    scanf("%f", &celsius);

    farhenit = (celsius * 9.0/5.0 ) + 32.0;

    printf("temperature in farhenit : %.3f\n", farhenit);

    return 0;

}