#include <stdio.h>

int add(int* a,int* b,int* sum)
{
    *sum = *a + *b;
    return *sum;
}

int main(void)
{
    int a = 4,b = 5,sum;

    int res = add(&a,&b,&sum);

    printf("%d + %d : %d\n",a,b,res);

    return 0;
}