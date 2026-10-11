#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
    int day, month, year;
};

struct Patient
{
    int patientId;
    char name[30];
    char disease[20];
    struct Date admitDate;
    float billAmount;
};

struct Patient *AdmitPatient(struct Patient *arr, int *count)
{
    char choice;

    do
    {
        struct Patient *temp = (struct Patient *)realloc(arr, (*count + 1) * sizeof(struct Patient));

        if (temp == NULL)
        {
            printf("Memory not assigned.\n");
            return arr;
        }

        arr = temp;

        printf("Enter Patient ID : ");
        scanf("%d", &arr[*count].patientId);

        printf("Enter Patient Name : ");
        scanf(" %19[^\n]", arr[*count].name);

        printf("Enter Disease Name : ");
        scanf(" %19[^\n]", arr[*count].disease);

        printf("Enter Date (DD/MM/YY) : ");
        scanf("%d %d %d", &arr[*count].admitDate.day, &arr[*count].admitDate.month, &arr[*count].admitDate.year);

        printf("Enter Bill Amount : ");
        scanf("%f", &arr[*count].billAmount);

        (*count)++;

        printf("Do You Want to Enter another record? (y/n)");
        scanf(" %c", &choice);

    } while (choice == 'y');

    return arr;
}

void DischargePatient(struct Patient *arr, int *count)
{
    if (*count == 0)
    {
        printf("No data found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter patient id : ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++)
    {
        if (arr[i].patientId == id)
        {
            found = 1;
            for (int j = i; j < *count; j++)
            {
                arr[j] = arr[j + 1];
            }
            (*count)--;
            printf("The patient with patient id %d is discharged successfully.\n", id);
            return;
        }
    }

    if (!found)
    {
        printf("The patient with patient id %d is not found.\n", id);
        return;
    }
}

void SearchByDisease(struct Patient *arr, int count)
{
    if (count == 0)
    {
        printf("No data found.\n");
        return;
    }

    int found = 0;
    char disease[20];

    printf("Enter the disease : ");
    scanf(" %19[^\n]", disease);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(arr[i].disease, disease) == 0)
        {
            found = 1;

            printf("Patient Id : %d\n", arr[i].patientId);
            printf("atient Name : %s\n", arr[i].name);
            printf("Patient Disease : %s\n", arr[i].disease);
            printf("Admit Date : %d/%d/%d\n", arr[i].admitDate.day, arr[i].admitDate.month, arr[i].admitDate.year);
            printf("Bill Amount : %f\n", arr[i].billAmount);
        }
    }

    if (!found)
    {
        printf("Patient with %s disease is not found.\n", disease);
        return;
    }
}

void SortByBillAmount(struct Patient *arr, int count)
{

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i].billAmount > arr[j].billAmount)
            {
                struct Patient temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void SaveToFile(struct Patient *arr, int count)
{
    FILE *fp = fopen("data.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fwrite(&arr[i], sizeof(struct Patient), 1, fp);
    }

    fclose(fp);
    printf("Data saved successfully.\n");
}

void ReadFromFile(void)
{
    FILE *fp = fopen("data.txt", "rb"); // Use "rb" for fread!
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    struct Patient temp;
    printf("\n--- Reading Records from File using fread() ---\n");
    while (fread(&temp, sizeof(struct Patient), 1, fp) == 1)
    {
        printf("ID: %d | Name: %s | Disease: %s | Date: %d/%d/%d | Bill: %.2f\n",
               temp.patientId, temp.name, temp.disease,
               temp.admitDate.day, temp.admitDate.month, temp.admitDate.year,
               temp.billAmount);
    }

    fclose(fp);
}

void DisplayAll(struct Patient *arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Pateint Id : %d\n", arr[i].patientId);
        printf("Patient Name: %s\n", arr[i].name);
        printf("Disease Name : %s\n", arr[i].disease);
        printf("Date of joining : %d\\%d\\%d\n", arr[i].admitDate.day, arr[i].admitDate.month, arr[i].admitDate.year);
        printf("Bill Amount : %f\n", arr[i].billAmount);
        printf("\n");
    }
}

int main(void)
{
    int choice = 0;
    int count = 0;

    struct Patient *arr = NULL;

    while (1)
    {

        printf("1.Admit New Patient.\n2.Discharge Patient By ID.\n3.Search patient by Disease.\n4.Sort patient by Bill Amount.\n5.Save High Bill Patients to File.\n6.Display Data.\n7.Exit.\n");

        printf("Enter yout choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            arr = AdmitPatient(arr, &count);
            break;
        case 2:
            DischargePatient(arr, &count);
            break;
        case 3:
            SearchByDisease(arr, count);
            break;
        case 4:
            SortByBillAmount(arr, count);
            break;
        case 5:
            SaveToFile(arr, count);
            break;
        case 6:
            DisplayAll(arr, count);
        case 7:
            ReadFromFile();
            break;
        case 8:
            free(arr);
            break;
        }
    }

    return 0;
}