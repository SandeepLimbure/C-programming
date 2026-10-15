/*

Q9:Given a file, write a C program to take 1 line of user input and store
the data on the file: (Implement using fgets(), Refer to man page)
Once data has been written, read the file and store the data in the array

f_array[]; print the same once reading is completed.

*/

#include <stdio.h>
#include <string.h>

void WriteAndRead(const char *filename)
{
    FILE *fp = fopen(filename,"r+");

    if(fp == NULL)
    {
        perror("Error opening file.");
        return;
    }

    char str[256];
    printf("Enter data to store on th file : ");
    fgets(str,sizeof(str),stdin);

    // Remove trailing newline
    str[strcspn(str, "\n")] = '\0';

    // Write to file
    fwrite(str, 1, strlen(str), fp);

    // Rewind to start before reading back
    rewind(fp);

    char f_array[256] = {0};            // zero-initialized
    size_t bytes_read = fread(f_array, 1, 255, fp);
    f_array[bytes_read] = '\0';        // null-terminate at actual length

    fclose(fp);

    printf("File Content : %s\n",f_array);
}

int main()
{
    const char *filename = "D:\\C programming\\Assignment_10\\textFiles\\q9.txt";

    WriteAndRead(filename);
    return 0;

}