#include <stdio.h>

void reverse(int arr[],int n)
{
    int low = 0;
    int high = n-1;

    while(low<high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

int main(void)
{
    int arr[] = {1,4,3,2,6,5};

    int n = 6;

    reverse(arr,n);

    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}