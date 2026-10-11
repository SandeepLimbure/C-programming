#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter arr[%d] : ", i);
        scanf("%d", (arr + i));
    }

    bubbleSort(arr, n);

    float median = 0;

    if (n % 2 != 0)
    {
        median = arr[n / 2];
    }
    else
    {
        median = (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
    }

    printf("median of array elements : %.2f\n", median);

    free(arr);

    return 0;
}