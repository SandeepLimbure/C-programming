#include <stdio.h>
#define KPH_TO_MPH 0.621371192

int main()
{
    float kph,mph;
    printf("Enter the distance in kph :");
    scanf("%f",&kph);

    mph = kph * KPH_TO_MPH;

    printf("The distance in mph : %.3f\n",mph);

    return 0;
}