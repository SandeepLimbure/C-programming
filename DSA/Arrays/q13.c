#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int compare(const void *p1, const void *p2)
{
    return (*(int *)p1 - *(int *)p2);
}

void merge(int a[], int b[], int n, int m)
{
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m)
    {
        if (a[i] > b[j])
        {
            swap(&a[i], &b[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }

    qsort(a, n, sizeof(int), compare);
    qsort(b, m, sizeof(int), compare);
}

int main(void)
{
    int a[] = {2, 4, 7, 10};
    int b[] = {2, 3};
    int n = 4;
    int m = 2;

    merge(a, b, n, m);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (int i = 0; i < m; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}