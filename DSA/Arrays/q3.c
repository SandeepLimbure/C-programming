#include <stdio.h>

void sort(int arr[],int n)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[] = {10,5,4,3,48,6,2,33,53,10};

    int n = 10,k = 4;

   sort(arr,n);

   printf("K-th smallest element is %d\n",arr[k-1]);

    return 0;
}