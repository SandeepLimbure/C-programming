#include <stdio.h>
#include <math.h>

int isPerfectSquare(int n)
{
    if(n < 0)
    {
        return 0;
    }
    int root = sqrt(n);
    return (root*root == n);
}

int main(void)
{
    int n = 9;
    int count = 0;

    for(int i = 1;i<n;i++)
    {
        if(isPerfectSquare(i))
        {
            count++;
        }
    }

    printf("%d",count);

    return 0;
}