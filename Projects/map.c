#include <stdio.h>
#include <stdlib.h>

int (*transform)(int);

int square(int n)
{
    return (n * n);
}

int doubleEle(int n)
{
    return (n * 2);
}

int negate(int n)
{
    return (!n);
}

void mapArray(int *arr, int n, int (*transform)(int))
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = transform(arr[i]);
    }
}

int main(void)
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter arr[i] : ");
        scanf("%d", (arr + i));
    }

    printf("Elements before any operations : \n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[i] : %d\n", *(arr + i));
    }

    int (*operations[3])(int) = {square, doubleEle, negate};

    int choice;

    printf("Enter your choice :  ");
    scanf("%d", &choice);

    mapArray(arr, n, operations[choice]);

    printf("Array elements after operations : \n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[i] : %d\n", *(arr + i));
    }

    return 0;
}