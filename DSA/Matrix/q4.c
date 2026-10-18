#include <stdio.h>
#include <limits.h>

int countEquals(int *rows, int cols, int target)
{
    int lo = 0, hi = cols;

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (rows[mid] <= target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    return lo;
}

int median(int mat[][3], int row, int col)
{
    int lo = INT_MAX, hi = INT_MIN;

    for (int i = 0; i < row; i++)
    {
        if (mat[i][0] < lo)
        {
            lo = mat[i][0];
        }
        if (mat[i][col - 1] > hi)
        {
            hi = mat[i][col - 1];
        }
    }

    int desired = (row * col + 1) / 2;

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        int count = 0;

        for (int i = 0; i < row; i++)
        {
            count += countEquals(mat[i], col, mid);
        }

        if (count < desired)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    return lo;
}

int main()
{
    int mat[3][3] = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};
    printf("Median: %d\n", median(mat, 3, 3)); // Output: 5
    return 0;
}