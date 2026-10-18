#include <stdio.h>

int countOnes(int row, int col, int mat[][col])
{
    int count = 0, prevCount = 0, row_no = -1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 1)
            {
                prevCount++;
            }
        }
        if (prevCount > count)
        {
            count = prevCount;
            row_no = i;
        }
    }

    return row_no;
}

int main(void)
{
    int row = 3;
    int col = 4;
    int mat[][4] = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}};

    int res = countOnes(row, col, mat);

    printf("The row with max number of ones is : %d\n", res);

    return 0;
}