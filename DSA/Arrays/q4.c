#include <stdio.h>

void sort(int arr[], int n)
{
    int left = 0, right = n - 1;

    while (left < right)
    {
        while (arr[left] < 0)
        {
            left++;
        }
        while (arr[right] >= 0)
        {
            right--;
        }
        if (right > left)
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

    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};

    int n = 9;

    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}