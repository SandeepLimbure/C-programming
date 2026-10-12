#include <stdio.h>

void merge(const int a[], int n, const int b[], int m, int c[])
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
    int n = 1, m = 5;

    // int a[] = {-5, 3, 6, 12, 15};

    // int b[] = {-12, -10, -6, -3, 4, 10};

    int a[] = {1};

    int b[] = {2, 4, 5, 6, 7};

    int len = m + n;

    int c[len];

    merge(a, n, b, m, c);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\n");

    int mid = len / 2;

    if (len % 2 == 0)
    {
        printf("median : %.1f\n", (c[mid] + c[mid - 1]) / 2.0);
    }
    else
    {
        printf("median  : %d\n", c[mid]);
    }

    return 0;
}