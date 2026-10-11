#include "stdio.h"
#define PI 3.14159


int main(void)
{
    float radius;
    float volume ;

    printf("Enter the value of radius :");
    scanf("%f",&radius);

    volume = (4.0/3.0) * PI * (radius * radius * radius);

    printf("The volume of sphere is : %.3f\n",volume);

    return 0;
}