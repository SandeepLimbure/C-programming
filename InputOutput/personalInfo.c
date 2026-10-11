#include <stdio.h>

int main()
{
    char fname[10];
    char sname[10];
    int year;

    printf("Enter your firstname : ");
    scanf("%s",fname);

    printf("Enter your surname :");
    scanf("%s",sname);

    printf("Enter your year of birth :");
    scanf("%d",&year);

    printf("%s %s %d\n",fname,sname,year);

    return 0;
}