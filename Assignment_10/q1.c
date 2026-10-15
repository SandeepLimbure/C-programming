//Write a C program to open a file named “Hello.txt” using “r”, “r+”
//modes, in following cases.
//Case 1: While file actually exists on the path specified
//Case 2: When doesn’t exists on the path specified
//  ***Monitor the errors you got using perror() and comment the same in
//  the source file.***

#include <stdio.h>

// case - 1 : While file actually exists on the path specified.

void readMode(const char *filename)
{
    FILE *fp =  fopen(filename,"r");

    /*
       No output on the console.
       Reason: The file exists at the specified path, so fopen opens it
       successfully in read mode. fp is not NULL, so the if block is
       skipped and perror is never called.
    */
    if(fp == NULL)
    {
        perror("fopen");
    }

    fclose(fp);
}

void readAndWriteMode(const char *filename)
{
    FILE *fp = fopen(filename,"r+");

    /*
       No error on console.
       Reason: The file already exists, so fopen opens it in both read
       and write mode. The file pointer starts at the beginning of the
       file. Writing does NOT truncate the existing content.
       (Note: "r+" does NOT create a new file if it doesn't exist.)
    */
    if(fp == NULL)
    {
        perror("fopen");
    }

}

// case - 2 : While file doesn't exists on the path specified.

void readModeNewFile(const char *filename)
{
    FILE *fp =  fopen(filename,"r");

    /*
       Output on console:
       "fopen: No such file or directory"
       Reason: The file does NOT exist at the given path, so fopen
       returns NULL. The if block executes and perror prints the
       message along with the system error description.
    */
    if(fp == NULL)
    {
        perror("File doesn't exists on the provided path.");
        return;
    }

    fclose(fp);
}

void readAndWriteModeNewFile(const char *filename)
{
    FILE *fp = fopen(filename,"r+");

    /*
       Output on console:
       "fopen: No such file or directory"
       Reason: The file does NOT exist at the given path. "r+" mode
       requires the file to already exist (unlike "w+" or "a+"), so
       fopen returns NULL. perror prints the error message.
    */
    if(fp == NULL)
    {
        perror("fopen");
    }

    fclose(fp);

}

int main(void)
{

     const char *filename = "\\wsl.localhost\\Ubuntu\\home\\sandeep\\CDAC\\Assignment_10\\textFiles\\q1.txt";	
    //readMode();
    //readAndWriteMode();

    //readModeNewFile();
    readAndWriteModeNewFile(filename);

    return 0;
    
}
