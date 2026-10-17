#include <stdio.h>

void search(int col, int row, int arr[][col], int target)
{
    int low = 0;
    int high = row * col - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int mid_row = mid / col;
        int mid_col = mid % col;
        int mid_val = arr[mid_row][mid_col];

        if (mid_val == target)
        {
            printf("The target value %d is found at position (%d, %d) in the matrix.\n", target, mid_row, mid_col);
            return;
        }
        else if (mid_val < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("The target element %d is not found in the array.\n", target);
}

int main(void)
{
    int row = 3;
    int col = 4;
    int arr[][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    int target;
    printf("Enter the target : ");
    scanf("%d", &target);

    search(col, row, arr, target);

    return 0;
}