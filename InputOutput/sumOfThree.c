#include <stdio.h>

int main()
{
    int num1,num2,num3;

    printf("Enter the first,second and third number :");

    scanf("%d, %d, %d,",&num1,&num2,&num3);

    int sum = num1+num2+num3;

    printf("The sum of the numbers is : %d\n",sum);

    return 0;
}