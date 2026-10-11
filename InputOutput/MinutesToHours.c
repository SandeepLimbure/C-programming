#include <stdio.h>

int main()
{
    int minutes,hours,remMinutes;

    printf("Enter the Minutes :");
    scanf("%d",&minutes);

    hours = minutes/60;

    remMinutes = minutes%60;

    printf("The time in hours and minutes : %d hours and %d minutes\n",hours,remMinutes);

    return 0;
}