//Create a text file manually with some data, read the total number of
//lines present in that text file and show the result at the end of program.

#include <stdio.h>
#include <stdlib.h>

int readLines(const char *filename)
{
    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        return -1;
    }

    int lines = 0;
    char line[256];

    while(fgets(line,sizeof(line),fp) > 0)
    {
        lines++;
    }

    return lines;
}

int main(void)
{
    const char *filename = "D:\\C programming\\Assignment_10\\textFiles\\q6.txt";

    int lines = readLines(filename);

    printf("The number of lines in the file are %d.",lines);

    return 0;
}