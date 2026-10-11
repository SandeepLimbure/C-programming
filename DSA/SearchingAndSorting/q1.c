#include <stdio.h>

void FirstLastIndex(int arr[],int target,int n, int *start,int *last)
{

    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = (low+high)/2;

        if(arr[mid] == target)
        {
            *start = mid;
            high = mid-1;
        }
        else if(arr[mid] < target)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    low = 0,high = n-1;

    while(low <= high)
    {
        int mid = (low+high)/2;

        if(arr[mid] == target)
        {
            *last = mid;
             low = mid+1;
        }
        else if(arr[mid] < target)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

}

int main(void)
{
    int arr[] = {1,3,5,5,5,5,67,123,125};
    int target = 5;

    int start = 0,last = 0;

    int n = 9;

    FirstLastIndex(arr,target,n,&start,&last);
    printf("First and Last index of target is %d %d",start,last);

    return 0;

}