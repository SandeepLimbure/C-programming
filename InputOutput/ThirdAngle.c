#include <stdio.h>

int main()
{
    int frstAngle, secondAngle, ThirdAngle;

    printf("Enter the frst and second angle of the triangle separated by comma :");
    scanf("%d, %d",&frstAngle,&secondAngle);

    ThirdAngle = 180 - (frstAngle+secondAngle);

    printf("The third angle of the triangle is : %d\n",ThirdAngle);

    return 0;


}