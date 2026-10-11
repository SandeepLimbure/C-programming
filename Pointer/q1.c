#include <stdio.h>

int main(void)
{
    int m = 10;

    int *z= &m;

    printf("Value of m is : %d\n",m);
    printf("Value of m using pointer is : %d\n",*z);
    printf("Value of z is : %p\n",&z);

    return 0;
}

