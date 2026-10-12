#include <stdio.h>

void duplicateXor(int arr[], int n)
{
    int xor1 = 0, xor2 = 0;

    for (int i = 1; i < n; i++)
    {
        xor1 ^= i;
    }

    for (int i = 0; i < n; i++)
    {
        xor2 ^= arr[i];
    }

    int diff = xor1 ^ xor2;

    printf("Duplicate : %d\n", diff);
}

// 2nd method (Floyd's Cycle Detection)

void duplicate(int arr[])
{
    int fast = 0, slow = 0;

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = 0;

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    printf("Duplicate : %d\n", slow);
}

int main(void)
{
    int arr[] = {1, 3, 4, 2, 2};

    int n = 5;

    duplicateXor(arr, n);

    duplicate(arr);

    return 0;
}