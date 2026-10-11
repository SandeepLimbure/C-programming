#include <stdio.h>
#include <ctype.h>

void count(char *str)
{
    int vowelCnt = 0, consonantCnt = 0;

    while(*str != '\0')
    {
        *str = tolower(*str);
        if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u')
        {
            vowelCnt++;
        }
        else{
            consonantCnt++;
        }
        str++;
    }

    printf("Vowel count is %d\n",vowelCnt);
    printf("consonants count  is %d\n",consonantCnt-1);
}

int main(void)
{
    char str[20];

    printf("Enter a string : ");
    fgets(str,sizeof(str),stdin);

    count(str);

    return 0;
}