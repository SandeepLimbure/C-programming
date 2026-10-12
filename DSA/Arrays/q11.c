#include <stdio.h>

int main(void)
{
    int arr[] = {2, 3, -8, 7, -1, 2, 3};

    int n = 7;

    int max = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (max < sum)
        {
            max = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    printf("maxsub array sum : %d\n", max);

    return 0;
}