#include <stdio.h>

struct student{
    char name[20];
    short int age;
    int marks ;
};

int main(void)
{
    struct student s1,s2;

    printf("Enter the name of student1: ");
    scanf("%s",s1.name);

    printf("Enter the age of student1 :");
    scanf("%hd",&s1.age);

    printf("Enter the marks of student1 : ");
    scanf("%d",&s1.marks);

    printf("Enter the name of student2: ");
    scanf("%s",s2.name);

    printf("Enter the age of student2 :");
    scanf("%hd",&s2.age);

    printf("Enter the marks of student2 : ");
    scanf("%d",&s2.marks);

    float avergage = (float)((s1.marks + s2.marks)/2);
    
    printf("average : %f\n",avergage);

    return 0;
}