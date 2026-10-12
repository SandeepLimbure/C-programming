#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = 9;

    int temp = arr[n - 1];

    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = temp;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}