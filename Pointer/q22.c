#include <stdio.h>
#include <string.h>

void reverse(char *str, int *low, int *high)
{
    while(*low < *high)
    {
        char temp = str[*low];
        str[*low] = str[*high];
        str[*high] = temp;
        (*low)++;
        (*high)--;
    }

    printf("Reverse string : %s\n",str);
}

int main(void)
{
    char str[20];

    printf("Enter a string : ");
    fgets(str,sizeof(str),stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("original string : %s\n",str);

    int low = 0;
    int high = strlen(str) - 1;
    reverse(str,&low,&high);

    return 0;
}