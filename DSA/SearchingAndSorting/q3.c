#include <stdio.h>

int linearSearch(int arr[],int target,int n)
{
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int arr[] = {4,5,6,7,0,1,2};

    int target = 0;
    int n = 7;

    int res = linearSearch(arr,target,n);

    if(res != -1)
    {
       printf("%d is located at index number %d.",target,res);
    }
    else{
        printf("%d is not present in the array.",target);
    }

    return 0;
}