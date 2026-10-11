#include <stdio.h>

int binary(int arr[],int low,int high,int target)
{
    while(low <= high)
    {
         int mid = (low + high)/2;
         if(arr[mid] == target)
         {
            return mid;
         }
         else if(arr[mid] < target)
         {
            low = mid+1;
         }
         else{
            high = mid-1;
         }
    }
    return -1;
}

int main(void)
{
    int n,target;
    printf("Enter size of array : ");
    scanf("%d",&n);

    printf("Enter the target element : ");
    scanf("%d",&target);

    int arr[n];

    for(int i = 0;i<n;i++)
    {
        printf("Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    int res = binary(arr,0,n-1,target);

    if(res == -1)
    {
        printf("%d is not found in the array.\n",target);
    }
    else{
        printf("%d is at the index %d in the array.\n",target,res);
    }

    return 0;
}