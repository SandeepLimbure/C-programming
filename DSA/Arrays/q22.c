#include <stdio.h>

int minJumps(int arr[], int n)
{
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;

    int jumps = 0, currEnd = 0, farthest = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (i + arr[i] > farthest)
            farthest = i + arr[i];

        if (i == currEnd)
        {
            jumps++;
            currEnd = farthest;
            if (currEnd >= n - 1)
                return jumps;
            if (farthest <= i)
                return -1;
        }
    }
    return -1;
}

int main(void)
{
    // int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    int arr[] = {1, 4, 3, 2, 6, 7};

    int n = sizeof(arr) / sizeof(int);

    int count = minJumps(arr, n);

    printf("minimum number of jumps : %d\n", count);

    return 0;
}