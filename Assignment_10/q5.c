/*
Create a text file manually with some data, then using C program,
read the total number of characters persent in the text file and print the
total count at the end.
*/

#include <stdio.h>

void countCharacters(const char *filename)
{
    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        perror("error opening file.");
        return;
    }

    int ch,count = 0;

    while((ch = fgetc(fp)) != EOF)
    {
        count++;
    }

    printf("Total characters in the file %d\n",count);

    fclose(fp);

    
}

int main(void)
{
    const char *filename = "D:\\C programming\\Assignment_10\\textFiles\\q5.txt";

    countCharacters(filename);

    return 0;

}