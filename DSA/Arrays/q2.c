#include <stdio.h>

void maxAndMin(int arr[],int n,int *max,int *min)
{
    for(int i = 0;i<n;i++)
    {
        if(arr[i] > *max)
        {
            *max = arr[i];
        }
        if(arr[i] < *min)
        {
            *min = arr[i];
        }
    }
}

int main(void)
{
    int arr[] = {3,5,4,1,9};

    int n = 5;

    int max = 0,min = arr[0];

    maxAndMin(arr,n,&max,&min);

    printf("Max and Min values in the array are : %d %d",max,min);

    return 0;
}