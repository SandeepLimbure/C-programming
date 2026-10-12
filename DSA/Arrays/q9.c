#include <stdio.h>

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void sort012(int arr[], int n)
{
    int low = 0, mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr, mid, low);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr, mid, high);
            high--;
        }
    }
}

int main(void)
{
    int n = 6;
    int arr[] = {0, 1, 2, 0, 1, 2};

    sort012(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}