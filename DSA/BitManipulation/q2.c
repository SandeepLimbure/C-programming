#include <stdio.h>
#include <math.h>

int countSetBits(int n)
{

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int x = log2(n);
    return ((pow(2, x - 1) * x) + (n - pow(2, x) + 1) + countSetBits(n - pow(2, x)));
}

int main(void)
{
    int n = 4;

    int count = countSetBits(n);

    printf("The number of ones from 1 to 4 numbers is : %d\n", count);

    return 0;
}