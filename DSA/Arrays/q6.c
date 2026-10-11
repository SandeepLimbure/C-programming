#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int fact = 1;

    for (int i = n; i > 1; i--)
    {
        fact *= i;
    }

    return fact;
}

int count(int n)
{
    int cnt = 0;

    while (n != 0)
    {
        cnt++;
        n /= 10;
    }

    return cnt;
}

int main(void)
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);

    int fact = factorial(n);

    int cnt = count(fact);

    int m = cnt - 1;

    int *arr = (int *)malloc(cnt * sizeof(int));

    while (fact != 0)
    {
        arr[m] = fact % 10;
        m--;
        fact /= 10;
    }

    for (int i = 0; i < cnt; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
