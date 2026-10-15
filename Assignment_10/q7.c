/*
   Q7 Implement Q5, and count only alphabets present in the file and
      exclude all other characters like space, special character, numbers.
*/

#include <stdio.h>
#include <ctype.h>

void countAlphabet(const char *filename)
{
    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        perror("error opening file.");
        return;
    }

    int count = 0;
    int ch;

    while((ch = fgetc(fp) ) != EOF)
    {
        if(isalpha(ch))
        {
            count++;
        } 
    }

    fclose(fp);
    printf("Number of alphabets : %d\n",count);
    return;
}

int main(void)
{
    const char *filename = "D:\\C programming\\Assignment_10\\textFiles\\q7.txt";

    countAlphabet(filename);
}