#include <stdio.h>

int length(char* str)
{
    int count = 0;

    while(*str != '\0')
    {
        count++;
        str++;
    }

    return count;
}

int main(void)
{
    char str[20];

    printf("Enter a string : ");
    fgets(str,sizeof(str),stdin);

    int len = length(str);

    printf("length of the string is %d\n",len-1);

    return 0;
}