/*
Implementing the code of Q2, try reading the data written previously
in some array and print the data on the screen.
*/

#include <stdio.h>
#include <stdlib.h>

void readFromFile(const char *filename)
{
    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        perror("error opening file");
        return;
    }

    // Determining the file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocating the  dynamic array 
    char *arr = malloc(size + 1);
    if (!arr)
    {
        printf("memory allocation failed.\n");
        fclose(fp);
        return;
    }

    fread(arr,1,size,fp);
    arr[size] = '\0';

    printf("%s\n",arr);

    free(arr);
    fclose(fp);
}

int main(void)
{
    const char *filename = "D:\\C programming\\Assignment_10\\textFiles\\q4.txt";
    
    readFromFile(filename);

    return 0;
}