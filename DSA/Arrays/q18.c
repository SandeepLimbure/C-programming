#include <stdio.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(const void *p1, const void *p2)
{
    return (*(int *)p1 - *(int *)p2);
}

bool subset(int a[], int b[], int n, int m)
{
    if (m > n)
        return false;

    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);

    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            return false;
        }
    }

    return (j == m);
}

int main(void)
{
    int a[] = {11, 7, 1, 13, 21, 3, 7, 3}, b[] = {11, 3, 7, 1, 7};

    int n = 8, m = 5;

    bool res = subset(a, b, n, m);

    if (res)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}