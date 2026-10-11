#include <stdio.h>

int main(void)
{
    int m = 29;
    int* ab = &m;

    printf("Value of m : %d\n",m);
    printf("value of ab : %d\n",*ab);
    printf("address of m : %p\n",&m);
    printf("address of ab : %p\n",ab);
    
    m = 34;

    printf("Value of m is : %d\n",m);
    printf("Value of ab is : %d\n",*ab);

    *ab= 7;

    printf("Value of m is : %d\n",m);
    printf("Value of ab is : %d\n",*ab);

    return 0;

}