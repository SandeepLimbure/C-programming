#include <stdio.h>
#include <stdlib.h>

struct vehicle
{
    int vehicleId;
    char vehicleName[20];
    int year;
    int speed;
};

struct vehicle *AddVehicle(struct vehicle *arr, int *count)
{
    char choice;

    do
    {
        struct vehicle *temp = (struct vehicle *)realloc(arr, (*count + 1) * sizeof(struct vehicle));

        if (temp == NULL)
        {
            printf("Memory allocation failed.\n");
            return arr;
        }

        arr = temp;

        printf("Enter vehicle Id:");
        scanf("%d", &arr[*count].vehicleId);

        printf("Enter vehicle Name : ");
        scanf(" %19[^\n]", arr[*count].vehicleName);

        printf("Enter yaer of manufacture : ");
        scanf("%d", &arr[*count].year);

        printf("Enter the speed of vehicle : ");
        scanf("%d", &arr[*count].speed);

        (*count)++;

        printf("\nDo you want to add one more vehicle data ?(y/n) : ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    return arr;
}

void DeleteById(struct vehicle *arr, int *count)
{
    int id;
    printf("Enter Id : ");
    scanf("%d", &id);

    if (*count == 0)
    {
        printf("There is no data.\n");
    }

    int found = 0;

    for (int i = 0; i < *count; i++)
    {
        if (arr[i].vehicleId == id)
        {
            found = 1;
            for (int j = i; j < *count; j++)
            {
                arr[j] = arr[j + 1];
            }
            (*count)--;
            printf("The vehicle with %d vehicle id is deleted succesfully.\n", id);
            return;
        }
    }
    if (!found)
    {
        printf("The vehicle with %d vehicle id is not found in the data.\n", id);
        return;
    }
}

void DisplayAll(struct vehicle *arr, int count)
{
    if (count == 0)
    {
        printf("There is no data.\n");
    }

    for (int i = 0; i < count; i++)
    {
        printf("vehicle id : %d\n", arr[i].vehicleId);
        printf("vehicle name : %s\n", arr[i].vehicleName);
        printf("year of manufacture : %d\n", arr[i].year);
        printf("vehicle speed : %d\n", arr[i].speed);
    }
}

void DisplayByYear(struct vehicle *arr, int count)
{
    int year;
    printf("Enter year : ");
    scanf("%d", &year);

    if (count == 0)
    {
        printf("There is no data.\n");
    }

    for (int i = 0; i < count; i++)
    {
        if (arr[i].year == year)
        {
            printf("vehicle id : %d\n", arr[i].vehicleId);
            printf("vehicle name : %s\n", arr[i].vehicleName);
            printf("year of manufacture : %d\n", arr[i].year);
            printf("vehicle speed : %d\n", arr[i].speed);
        }
    }
}

int main(void)
{
    int choice = 0;

    struct vehicle *arr = NULL;
    int count = 0;

    while (1)
    {

        printf("\n1.Add vehicle.\n2.Delete vehicle by id.\n3.Display all vehicles.\n4.Display by year.\n5.free\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            arr = AddVehicle(arr, &count);
            break;
        case 2:
            DeleteById(arr, &count);
            break;
        case 3:
            DisplayAll(arr, count);
            break;
        case 4:
            DisplayByYear(arr, count);
            break;
        case 5:
            free(arr);
            return 0;
        }
    }
}
