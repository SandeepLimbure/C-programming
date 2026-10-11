#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a  = *b;
    *b = temp;
}

void bubbleSort(int n,int *arr)
{
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            if(*(arr+j) > *(arr+j+1))
            {
               swap((arr+j),(arr+j+1));
            }
        }
    }
}

int main(void)
{
    int arr[] = {25,45,89,15,82};
   
    bubbleSort(5,arr);

    for(int i = 0;i<5;i++)
    {
        printf("%d ",*(arr+i));
    }
}