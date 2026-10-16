#include <stdio.h>

void moveNegative(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        while (left < right && arr[left] < 0)
        {
            left++;
        }
        while (left < right && arr[right] >= 0)
        {
            right--;
        }
        if (left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }
}

int main(void)
{
    int arr[] = {1, 2, 3, -4, -1, 4};

    int n = 6;

    printf("Before arranging : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    moveNegative(arr, n);

    printf("After arranging : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}