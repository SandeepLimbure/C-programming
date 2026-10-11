#include <stdio.h>

void display(int *arr)
{
    for(int i = 0;i<5;i++)
    {
        printf("element - %d : %d\n",i,*(arr+i));
    }
}

int main(void)
{
    int arr[] = {5,7,2,9,8};

    display(arr);

    return 0;
}