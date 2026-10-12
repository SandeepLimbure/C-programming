#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool tripletSum(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == target)
            {
                return true;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return false;
}

int main(void)
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int target = 13;
    int n = 6;

    bool res = tripletSum(arr, n, target);

    printf("%s", res);

    return 0;
}