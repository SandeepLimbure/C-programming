#include <stdio.h>

int main()
{
    int num1,num2,sum,diff,prod;
    float quotient;

    printf("Enter the first and second number separated by comma :");
    scanf("%d, %d",&num1,&num2);

    sum = num1+num2;
    diff = num1 - num2;
    prod = num1 * num2; 
    quotient = num1 / num2;

    printf("The sum of the numbers is : %d\n",sum);
    printf("The difference of the numbers is : %d\n",diff);
    printf("The product of the numbers is : %d\n",prod);
    printf("The quotient of the numbers is : %.2f\n",quotient);

    return 0;

}