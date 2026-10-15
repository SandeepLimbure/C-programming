/*
Try getting file related errors and analyze the behaviour using
perror() call.
1) Opening file using read permission and try to write in it.
2) Opening the file using write permission and try to read it
*/

#include <stdio.h>
#include <errno.h>

void openInRead(const char *filename)
{
    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        perror("error opening file");
        return;
    }

    char str[30] = "welcom to my world";

    if(fwrite(str,1,30,fp)<30)
    {
        perror("Error attempting to write");
    }

    fclose(fp);

}

// 2) Opening the file using write permission and try to read it
void openInWrite(const char *filename)
{
    // "w" opens for writing and creates the file if it doesn't exist
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        perror("Error opening file for writing");
        return;
    }

    char buffer[30];

    // Try to read 30 bytes from the write-only file
    size_t items_read = fread(buffer, 1, 30, fp);
    
    // fread returns 0 on failure or End-Of-File. 
    if (items_read == 0)
    {
        // ferror() confirms that an actual error occurred, rather than just hitting the end of the file.
        if (ferror(fp)) {
            perror("Error attempting to read");
        } else {
            printf("Reached End of File.\n");
        }
    }

    fclose(fp);
}

int main()
{
    const char *filename = "D:\\C programming\\Assignment_10\\textFiles\\q8.txt";
    printf("--- Test 1 ---\n");
    openInRead(filename);

    printf("\n--- Test 2 ---\n");
    openInWrite(filename);

    return 0;
}