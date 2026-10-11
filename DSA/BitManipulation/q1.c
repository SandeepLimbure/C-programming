#include <stdio.h>

int main(void)
{
    int n, cnt = 0;
    printf("Enter a number : ");
    scanf("%d", &n);

    while (n != 0)
    {
        int rem = n % 2;
        if (rem == 1)
        {
            cnt++;
        }
        n /= 2;
    }

    printf("The number of ones : %d", cnt);

    return 0;
}