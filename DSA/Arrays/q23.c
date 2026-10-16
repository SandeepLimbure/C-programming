#include <stdio.h>

void commonElements(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0, found = 0;

    printf("Common Elements in three sorted arrays : \n");

    while (i < n1 && j < n2 && k < n3)
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            printf("%d ", arr1[i]);
            found = 1;

            int current_match = arr1[i];

            while (i < n1 && arr1[i] == current_match)
                i++;
            while (j < n2 && arr2[j] == current_match)
                j++;
            while (k < n3 && arr3[k] == current_match)
                k++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr3[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    if (!found)
    {
        printf("No common elements found in the three sorted arrays.\n");
    }
}

int main(void)
{
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);
    int n3 = sizeof(arr3) / sizeof(int);

    commonElements(arr1, arr2, arr3, n1, n2, n3);

    return 0;
}