#include <stdio.h>

int maxSum(int *arr, int n)
{
    int sum = 0;
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > max)
        {
            max = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return max;
}

int main(void)
{
    int arr[] = {2, 3, -8, 7, -1, 2, 3};

    int n = 7;

    int res = maxSum(arr, n);

    printf("max subarray sum : %d\n", res);

    return 0;
}