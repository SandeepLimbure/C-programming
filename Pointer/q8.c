#include <stdio.h>

void swap(int* a,int* b,int* c)
{
    int temp = *b;
    *b = *a;
    *a = *c;
    *c = temp;
}


int main(void)
{
    int a,b,c;

    printf("Enter a,b and c values : ");
    scanf("%d %d %d",&a,&b,&c);

    printf("values of a , b and c before swapping : \n");
    printf("value of a : %d\n",a);
    printf("value of b : %d\n",b);
    printf("value of c : %d\n",c);

    swap(&a,&b,&c);

    printf("\n\nvalues of a , b and c after swapping : \n");
    printf("value of a : %d\n",a);
    printf("value of b : %d\n",b);
    printf("value of c : %d\n",c);

    return 0;
}
