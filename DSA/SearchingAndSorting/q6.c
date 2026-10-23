#include <stdio.h>

void merge(int a[], int b[], int c[], int n, int m, int x)
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while (i < n)
    {
        c[k++] = a[i++];
    }
    while (j < m)
    {
        c[k++] = b[j++];
    }
}

int main(void)
{
    int a[] = {2, 3, 6, 7, 9}, b[] = {1, 4, 8, 10}, k = 5, n = 5, m = 4;

    int x = n + m;

    int c[x];

    merge(a, b, c, n, m, x);

    printf("The kth value of merged array is %d\n", c[k - 1]);

    return 0;
}