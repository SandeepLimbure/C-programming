#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    int id;
    char name[20];
    float salary;
};

int compareById(struct employee a, struct employee b)
{
    return a.id > b.id;
}

int compareBySalary(struct employee a, struct employee b)
{
    return a.salary > b.salary;
}

int compareByName(struct employee a, struct employee b)
{
    return strcmp(a.name, b.name) > 0;
}

void sortEmployees(struct employee *arr, int count, int (*compare)(struct employee, struct employee))
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (compare(arr[j], arr[j + 1]))
            {
                struct employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayAll(struct employee *arr, int n)
{
    printf("%-10s %-15s %-10s\n", "ID", "Name", "Salary");
    printf("--------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%-10d %-15s %.2f\n", arr[i].id, arr[i].name, arr[i].salary);
    }
    printf("\n");
}

int main(void)
{
    struct employee arr[3] = {{123, "sandeep", 123456.67}, {456, "jyothi", 34567.89}, {678, "nimai", 24567.56}};

    int (*operation[3])(struct employee, struct employee) = {compareById, compareByName, compareBySalary};

    printf("Sorting using compare by id : \n");
    sortEmployees(arr, 3, (operation)[0]);
    displayAll(arr, 3);

    printf("Sorting using compare by Name : \n");
    sortEmployees(arr, 3, operation[1]);
    displayAll(arr, 3);

    printf("Sorting using compare by salary : \n");
    sortEmployees(arr, 3, operation[2]);
    displayAll(arr, 3);

    return 0;
}
