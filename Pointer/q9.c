#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* ptr;

    ptr = malloc(5*sizeof(int));

    if(ptr == NULL)
    {
        printf("No memory allocated.\n");
        return -1;
    }

    for(int i = 0;i<5;i++)
    {
        printf("Enter number %d : ",i+1);
        scanf("%d",(ptr+i));
    }

    int largest = 0;
    for(int i = 0;i<5;i++)
    {
        if(largest < *(ptr+i))
        {
            largest = *(ptr+i);
        }
    }
    printf("largest number is : %d\n",largest);

    return 0;
}