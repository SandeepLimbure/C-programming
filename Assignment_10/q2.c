/*
Create a file manually name it is q2.txt and write data “Hello World”
to the file then try opening
the file using “w” mode and once opened sucessfully, close the file. Then
look at the file contents manually in some text editor and check the
following:
- Was the file content altered?
- What was the file content after running the program?
- If the file data was altered, what was the reason behind the same?
Monitor the same findings with “r”, “r+”, “w+” modes and comment your
in the same source file.
*/

#include <stdio.h>

void openInWrite(const char *filename)
{
    //data will be truncated.
    FILE *fp = fopen(filename,"w");

    if(fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    // char str[20];

    // fread(str,1,sizeof(str),fp);

    // printf("%s\n",str);

    fclose(fp);
}

void openInRead(const char *filename)
{
    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    // char str[20];

    // fread(str,1,sizeof(str),fp);

    // printf("%s\n",str);

    fclose(fp);
}

void openInWritePlus(const char *filename)
{
    FILE *fp = fopen(filename,"w+");

    if(fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    // char str[20];

    // fread(str,1,sizeof(str),fp);

    // printf("%s\n",str);

    fclose(fp);
}

void openInReadPlus(const char *filename)
{
    FILE *fp = fopen(filename,"r+");

    if(fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    // char str[20];

    // fread(str,1,sizeof(str),fp);

    // printf("%s\n",str);

    fclose(fp);
}

int main(void)
{
    const char *filename = "D:\\C programming\\Assignment_10\\textFiles\\q2.txt";
    
    openInWrite(filename);

    return 0;

}