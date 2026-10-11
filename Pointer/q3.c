#include <stdio.h>

int main(void)
{
    int m = 300;
    float fx = 300.600006;
    char cht = 'z';

    int* ptr1 = &m;
    float* ptr2 = &fx;
    char* ptr3 = &cht;

    printf("address of m is : %p\n",&m);
    printf("address of fx is : %p\n",&fx);
    printf("address of cht is : %p\n",&cht);

    printf("value of m : %d\n",*(&m));
    printf("value of fx : %f\n",*(&fx));
    printf("value of cht : %c\n",*(&cht));

    printf("address of m : %p\n",ptr1);
    printf("address of fx : %p\n",ptr2);
    printf("address of cht : %p\n",ptr3);

    printf("value of m : %d\n",*ptr1);
    printf("value of m : %f\n",*ptr2);
    printf("value of m : %c\n",*ptr3);

    return 0;
}