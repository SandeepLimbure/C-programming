//Using C program Create a File named “myFirst.txt” and write your
//name and PRN by taking user input and store the data into that file.
//(verify the data by manually opening the file)


#include<stdio.h> 

void writetoFile(const char *filename)
{
    FILE *fp = fopen(filename,"a");

    if(fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    char str[20];
    int PRN;

    printf("Enter your name : ");
    fgets(str,sizeof(str),stdin);

    printf("Enter yout PRN : ");
    scanf("%d",&PRN);

    fprintf(fp,"%s",str);
    fprintf(fp,"%d",PRN);

    fclose(fp);

    return;

}

int main(void)
{
    const char *filename = "D:\\C programming\\Assignment_10\\textFiles\\q3.txt";
  
    writetoFile(filename);

    return 0;

}