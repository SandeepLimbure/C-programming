#include <stdio.h>

int main(void)
{
    int arr1[] = {1, 2, 3, 2, 3};
    int arr2[] = {3, 2, 2, 3, 3, 2};
    int n1 = 5, n2 = 6;

    int visited[11] = {0};

    printf("Union: ");

    // Scan arr1
    for (int i = 0; i < n1; i++)
    {
        if (visited[arr1[i]] == 0)
        {
            printf("%d ", arr1[i]);
            visited[arr1[i]] = 1;
        }
    }

    // Scan arr2
    for (int i = 0; i < n2; i++)
    {
        if (visited[arr2[i]] == 0)
        {
            printf("%d ", arr2[i]);
            visited[arr2[i]] = 1;
        }
    }
    printf("\n");

    return 0;
}