#include <stdio.h>

int fact(int *num)
{
    if(*num <= 1)
    {
        return 1;
    }
    return (*num) * fact(&(int){*num - 1});
}

int main(void)
{
    int n;
    printf("Enter an integer : ");
    scanf("%d",&n);

    int factorial = fact(&n);

    printf("The factorial of %d is %d",n,factorial);

    return 0;
}