#include <stdio.h>
#include <limits.h>

int CountLeastElemets(int mat[][4], int row, int col, int mid)
{
    int i = 0, j = col - 1, count = 0;

    while (i < row && j >= 0)
    {
        if (mat[i][j] <= mid)
        {
            count += i;
            i++;
        }
        else
        {
            j--;
        }
    }
    return count;
}

int KthSmallest(int mat[][4], int col, int row, int k)
{
    int low = mat[0][0];
    int high = mat[row - 1][col - 1];

    while (low < high)
    {
        int mid = (low + high) / 2;

        int count = CountLeastElemets(mat, row, col, mid);

        if (count < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

int main(void)
{
    int row = 4, col = 4, k = 3;
    int mat[][4] = {{16, 28, 60, 64},
                    {22, 41, 63, 91},
                    {27, 50, 87, 93},
                    {36, 78, 87, 94}};

    int res = KthSmallest(mat, col, row, k);

    printf("Kth (%d) smallest element in the matrix is %d\n", k, res);

    return 0;
}
