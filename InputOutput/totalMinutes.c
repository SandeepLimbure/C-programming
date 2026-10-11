#include <stdio.h>

int main()
{
    int minutes,hours;
    int totalMinutes;
    
    printf("Enter the hours : ");
    scanf("%d",&hours);

    printf("Enter the Minutes :");
    scanf("%d",&minutes);

    totalMinutes = (hours * 60)+minutes;

    printf("Total Minutes : %d\n",totalMinutes);

    return 0;

}