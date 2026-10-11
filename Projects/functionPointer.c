#include <stdio.h>
#include <stdlib.h>

void (*func)(int *, int);

void findMax(int *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Max element in array is : %d\n", max);
}

void findMin(int *arr, int n)
{
    int min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("Min element of the array is : %d\n", min);
}

void Average(int *arr, int n)
{
    int sum = 0;
    float avg = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    avg = (float)(sum / n);

    printf("Avg of array elements is : %f\n", avg);
}

int main(void)
{
    int n;
    printf("Enter the size of arr : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory not allocated.\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter arr[i] : ");
        scanf("%d", (arr + i));
    }

    int choice;

    printf("\n0.Find Max.\n1.Find Min.\n2.Find average\n");

    printf("Enter your choice : ");
    scanf("%d", &choice);

    void (*operations[3])(int *, int) = {findMax, findMin, Average};

    operations[choice](arr, n);

    free(arr);

    return 0;
}