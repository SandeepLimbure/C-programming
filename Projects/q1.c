#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee{
    int emp_id;
    char *name;
    int no_of_ratings;
    int *performance_ratings;
};

struct employee* addEmployee(struct employee *emp,int *count)
{
    int n;
    char choice;

    do{
        struct employee *temp = (struct employee *)realloc(emp,(*count+1)*sizeof(struct employee));

        if(temp == NULL)
        {
            printf("fatal error : memory not allocated.\n");
            return emp;
        }

        emp = temp;

        printf("Enter the employee Id : ");
        scanf("%d",&emp[*count].emp_id);

        printf("Enter the lenth of name : ");
        scanf("%d",&n);

        while(getchar() != '\n');

        emp[*count].name = (char *)malloc(n*sizeof(char));

        if(emp[*count].name == NULL)
        {
            printf("fatal error : memory not allocated.\n");
            return emp;
        }

        printf("Enter yout name : ");
        

        if(fgets(emp[*count].name, n, stdin) != NULL)
        {
            emp[*count].name[strcspn(emp[*count].name,"\n")] = '\0';
        }

        printf("Enter number of ratings : ");
        scanf(" %d",&emp[*count].no_of_ratings);

        emp[*count].performance_ratings = (int *)malloc((emp[*count].no_of_ratings)*sizeof(int));
        if(emp[*count].performance_ratings == NULL)
        {
            printf("fatal error : memory not allocated.\n");
            return emp;
        }
        
        for(int i = 0;i<emp[*count].no_of_ratings;i++)
        {
            printf("Enter performance rating[%d] : ",i);
            scanf("%d",&emp[*count].performance_ratings[i]);
        }

        (*count)++;

        printf("Do you want to add more employees data? (y/n) : ");
        scanf(" %c",&choice);


    }while(choice == 'y' || choice == 'Y');

    return emp;
}

void display(struct employee *emp,int count)
{
    for(int i = 0;i<count;i++)
    {
        printf("Employee id : %d\n",emp[i].emp_id);
        printf("employee name : %s\n",emp[i].name);
        printf("number of ratings : %d\n",emp[i].no_of_ratings);
        printf("employee ratings : \n");
        for(int j = 0;j<emp[i].no_of_ratings;j++)
        {
            printf("performance rating : %d\n",emp[i].performance_ratings[j]);
        }
    }
    printf("\n");
}

void freeAll(struct employee *emp, int count) {
    if (emp == NULL) return;

    for (int i = 0; i < count; i++) {
        free(emp[i].name);              
        free(emp[i].performance_ratings); 
    }
    free(emp); 
    printf("All memory successfully freed.\n");
}

int main(void)
{

    struct employee *emp = NULL;

    int count = 0;

    int choice;

    while(1)
    {
        printf("1.Add Employee\n2.Display.\n3.free\n\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                emp = addEmployee(emp,&count);
                break;
            case 2:
                display(emp,count);
                break;
            case 3:
                freeAll(emp,count);
                return 0;
                break;
        }
    }

    return 0;
}
