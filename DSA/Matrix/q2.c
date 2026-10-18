#include <stdio.h>
#include <stdlib.h>

int *spiral(int col, int row, int mat[][col])
{
    int *arr = (int *)malloc(row * col * sizeof(int));

    int n = row * col;
    int k = 0;

    int left = 0, top = 0, right = col - 1, bottom = row - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            arr[k++] = mat[top][i];
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            arr[k++] = mat[i][right];
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                arr[k++] = mat[bottom][i];
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                arr[k++] = mat[i][left];
            }
            left++;
        }
    }

    printf("Spiral maatrix : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int row = 4;
    int col = 4;
    int mat[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    spiral(col, row, mat);

    return 0;
}