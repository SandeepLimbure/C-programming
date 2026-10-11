#include <stdio.h>

int main(void)
{
    char str[20];

    char* ptr = str;

    printf("Enter the string : ");
    fgets(str,sizeof(str),stdin);

    int cnt = 0;

    while(*ptr != '\0')
    {
        cnt++;
        ptr++;
    }

    printf("The length of given string is %d\n",cnt-1);

    return 0;
}