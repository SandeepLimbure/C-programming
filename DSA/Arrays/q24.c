#include <stdio.h>

void moveZeroes(int *arr, int n)
{
    int i = 0, index = 0;
    while (i < n)
    {
        if (arr[i] != 0)
        {
            arr[index++] = arr[i];
        }
        i++;
    }
    while (index < n)
    {
        arr[index++] = 0;
    }
}

int main(void)
{
    int arr[] = {0, 1, 0, 3, 12};

    int n = 5;

    moveZeroes(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}