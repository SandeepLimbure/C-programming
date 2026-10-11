#include <stdio.h>


int a = 5,b=10;
int change1(int *p);
int change2(int **pp);

int main(void)
{
    int x = 20, *ptr = &x;
    printf("%d\n",*ptr);
    change1(ptr);
    printf("%d\n",*ptr);
    change2(&ptr);
    printf("%d\n",*ptr);
    
    return 0;
}

int change1(int *p)
{
    p=&a;
}

int change2(int **pp)
{
    *pp = &b;
}