#include <stdio.h>

int main(void)
{
    int arr[] = {15,2,45,4,7};

    for(int i = 0;i<5;i++)
    {
        if(arr[i] == i+1)
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\n");

    return 0;
}