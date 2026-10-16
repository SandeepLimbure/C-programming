#include <stdio.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void SumZero(int *arr, int n)
{
    if (n < 2)
    {
        printf("Array size is less than 2, no pairs possible.\n");
        return;
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int count = 0;

    printf("Pairs with sum zero:\n");

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == 0)
        {
            printf("(%d %d)\n", arr[left], arr[right]);
            count++;

            while (left < right && arr[left] == arr[left + 1])
            {
                left++;
            }
            while (left < right && arr[right] == arr[right - 1])
            {
                right--;
            }
            left++;
            right--;
        }
        else if (sum < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
}

int main(void)
{
    int arr[] = {-1, 0, 1, 2, -1, -4};
    int n = 6;

    SumZero(arr, n);

    return 0;
}