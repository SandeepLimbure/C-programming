/*
Q11: Read a given file 3 times by using the fopen() and fclose() only
once. Use the fseek() to position the stream to the starting of the file
once the end of the file has been reached.
Hence, read the same file 3 times in some array, print the data then exit
the program.
*/

#include <stdio.h>

void readThreeTimes(const char *filename)
{
    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        perror("error opening file");
        return;
    }

    char str[100];
    size_t bytesRead;

    for(int i = 0;i<3;i++)
    {
        printf("-------Reading File %d times-------\n",i+1);

        while((bytesRead = fread(str,1,sizeof(str),fp)) > 0)
        {
            str[bytesRead] = '\0';
            printf("%s",str);
        }
        printf("\n");

        fseek(fp,0,SEEK_SET);
    }

    fclose(fp);
}


int main(void)
{
    const char *filename = "D:\\C programming\\Assignment_10\\textFiles\\q11.txt";

    readThreeTimes(filename);

    return 0;
}