#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int empId;
    char name[25];
    char department[15];
    float salary;
    unsigned char permissions;
};

struct Employee *addEmployee(struct Employee *arr, int *count)
{
    char choice;
    do
    {
        struct Employee *temp = (struct Employee *)realloc(arr, (*count + 1) * sizeof(struct Employee));
        if (temp == NULL)
        {
            printf("Memory allocation failed.\n");
            return arr;
        }
        arr = temp;

        printf("\nEnter Employee Id : ");
        scanf("%d", &arr[*count].empId);
        while (getchar() != '\n')
            ;

        printf("Enter Employee Name : ");
        scanf(" %24[^\n]", arr[*count].name);

        printf("Enter Department : ");
        scanf(" %14[^\n]", arr[*count].department);

        printf("Enter Salary : ");
        scanf("%f", &arr[*count].salary);

        // Safe 1-byte assignment
        int tempPerm;
        printf("Permissions (0 to 255) : ");
        scanf("%d", &tempPerm);
        arr[*count].permissions = (unsigned char)tempPerm;

        (*count)++;

        printf("Do you want to add more employees? (y/n) : ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return arr; // MUST return this back to main!
}

void DisplayAll(struct Employee *arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Employee id : %d\n", arr[i].empId);
        printf("Employee name : %s\n", arr[i].name);
        printf("Employee Department : %s\n", arr[i].department);
        printf("Employee Salary : %f\n", arr[i].salary);
        printf("Raw Permissions : %u\n", arr[i].permissions);

        // 2. Decode and print each permission bit (Bit 0, 1, 2, and 7)
        printf(" -> Server Room Access (Bit 0) : %s\n", ((arr[i].permissions >> 0) & 1) ? "YES" : "NO");
        printf(" -> R&D Lab Access     (Bit 1) : %s\n", ((arr[i].permissions >> 1) & 1) ? "YES" : "NO");
        printf(" -> Manager Cabin      (Bit 2) : %s\n", ((arr[i].permissions >> 2) & 1) ? "YES" : "NO");
        printf(" -> WFH Active Status  (Bit 7) : %s\n", ((arr[i].permissions >> 7) & 1) ? "YES" : "NO");
    }
}

void modifyPermissions(struct Employee *arr, int count)
{
    if (count == 0)
    {
        printf("No employee records found.\n");
        return;
    }

    int id, bit, op, found = 0;

    printf("\nEnter Employee ID to modify permissions : ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (arr[i].empId == id)
        {
            found = 1;
            printf("\nEmployee found: %s\n", arr[i].name);
            printf("Enter the bit to modify (0=Server, 1=R&D, 2=Manager, 7=WFH) : ");
            scanf("%d", &bit);

            if (bit != 0 && bit != 1 && bit != 2 && bit != 7)
            {
                printf("Invalid bit! Only 0, 1, 2, or 7 are allowed.\n");
                return;
            }

            printf("Choose Operation: 1. Grant (Set 1)  2. Revoke (Clear 0)  3. Toggle : ");
            scanf("%d", &op);

            if (op == 1)
            {
                arr[i].permissions |= (1 << bit); // SET BIT to 1
                printf("Permission Granted!\n");
            }
            else if (op == 2)
            {
                arr[i].permissions &= ~(1 << bit); // CLEAR BIT to 0
                printf("Permission Revoked!\n");
            }
            else if (op == 3)
            {
                arr[i].permissions ^= (1 << bit); // TOGGLE BIT (1->0, 0->1)
                printf("Permission Toggled!\n");
            }
            else
            {
                printf("Invalid operation choice.\n");
                return;
            }

            printf("New Raw Permissions Value: %u\n", arr[i].permissions);
            break; // Stop searching once employee is found
        }
    }

    if (!found)
    {
        printf("Employee with ID %d not found!\n", id);
    }
}

void averageSalaryByDept(struct Employee *arr, int count)
{
    if (count == 0)
    {
        printf("No employee records found.\n");
        return;
    }

    char searchDept[15];
    float totalSalary = 0.0;
    int empCount = 0;

    printf("\nEnter the Department name : ");
    scanf(" %14[^\n]", searchDept);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(arr[i].department, searchDept) == 0)
        {
            totalSalary += arr[i].salary;
            empCount++;
        }
    }

    if (empCount > 0)
    {
        printf("\nAverage Salary of %d employee(s) in '%s' is : %.2f\n",
               empCount, searchDept, (totalSalary / empCount));
    }
    else
    {
        printf("\nNo employees found in the '%s' department.\n", searchDept);
    }
}

int main(void)
{
    int choice, count = 0;

    struct Employee *arr = NULL;

    while (1)
    {
        printf("\n1.Add Employee.\n2.DisplayAll.\n3.Grant Permission.\n4.Avg Salary.\n5.free.\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            arr = addEmployee(arr, &count);
            break;
        case 2:
            DisplayAll(arr, count);
            break;
        case 3:
            modifyPermissions(arr, count);
            break;
        case 4:
            averageSalaryByDept(arr, count);
            break;
        case 5:
            free(arr);
            return 0;
        }
    }

    return 0;
}