#include <stdio.h>

int getMinSwaps(const int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            count++;
        }
    }

    if (count <= 1 || count == n)
    {
        return 0;
    }

    int bad = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > k)
        {
            bad++;
        }
    }

    int min_swaps = bad;

    for (int i = 0, j = count; j < n; i++, j++)
    {
        if (arr[i] > k)
        {
            bad--;
        }
        if (arr[j] > k)
        {
            bad++;
        }
        if (bad < min_swaps)
        {
            min_swaps = bad;
        }
    }

    return min_swaps;
}

int main(void)
{
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int ans = getMinSwaps(arr, n, k);

    printf("Minimum swaps = %d\n", ans);

    return 0;
}