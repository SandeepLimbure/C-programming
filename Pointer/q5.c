#include <stdio.h>

void greatest(int* a,int* b)
{
    if(*a > *b)
    {
        printf("%d is greater than %d\n",*a,*b);
    }else{
        printf("%d is greater than %d\n",*b,*a);
    }
}

int main(void)
{
    int a = 5;
    int b = 6;

    greatest(&a,&b);

    return 0;
}