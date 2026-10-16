#include <stdio.h>

int main(void)
{
    int arr[] = {3, 4, 2, 2, 1, 2, 3, 3};

    int k = 4;

    int n = sizeof(arr) / sizeof(int);

    int count = n / k;

    for (int i = 0; i < n; i++)
    {
        int countEle = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                countEle++;
            }
        }
        if (countEle > count)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}