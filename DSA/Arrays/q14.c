#include <stdio.h>

int countInversion(int arr[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }

    return count;
}

int main(void)
{
    int arr[] = {2, 4, 1, 3, 5};

    int n = 5;

    int count = countInversion(arr, n);

    printf("Count Inversion : %d\n", count);

    return 0;
}