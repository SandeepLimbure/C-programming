/*
Create a file manually in your folder with name “hello.txt” and add
the following data to the file: “Welcome to my world”
Write a C program to read one character at a time from this file and store
in some array, once you have read 7 characters (add ‘\0’ manually) then
print the array data and then using fseek() and SEEK_CUR with an offset
of 7, try reading the 5 characters again from the file and store in same
array and print again. Try understanding the behaviour based on output
and the content of the file.
*/

#include <stdio.h>

void writeToFile(const char *filename)
{
    FILE *fp = fopen(filename,"w");

    if(fp == NULL)
    {
        perror("error opening file");
        return;
    }

    char str[] = "Welcome to my world";

    fputs(str,fp);

    fclose(fp);

    fp = fopen(filename,"r");

    int i;
    char str1[20];

    for(i = 0;i<7;i++)
    {
        str1[i] = fgetc(fp);
    }
    str1[i] = '\0';

    printf("1. First 7 characters : '%s'\n", str1);

    // 3. fseek() with SEEK_CUR and an offset of 7
    // This moves the cursor 7 bytes forward from its CURRENT position.
    fseek(fp, 7, SEEK_CUR);

    // 4. Read the next 5 characters into the same array
    for (i = 0; i < 5; i++)
    {
        str1[i] = fgetc(fp);
    }
    str1[i] = '\0';

    printf("2. Next 5 characters  : '%s'\n", str1);

    fclose(fp);
}

int main(void)
{
    const char *filename = "D:\\C programming\\Assignment_10\\textFiles\\q10.txt";
 
    writeToFile(filename);

    return 0;

}