#include <stdio.h>
#include <stdlib.h>

struct book
{
    int bookId;
    char title[20];
    char author[20];
    int price;
    int year;
};

struct book *addBook(struct book *arr, int *count)
{
    char choice;

    do
    {
        struct book *temp = (struct book *)realloc(arr, (*count + 1) * sizeof(struct book));

        if (temp == NULL)
        {
            printf("Memory allocation failed.\n");
            return arr;
        }

        arr = temp;

        printf("\nEnter the bookId : ");
        scanf("%d", &arr[*count].bookId);

        printf("Enter book title : ");
        scanf(" %19[^\n]", arr[*count].title);

        printf("Enter author name : ");
        scanf(" %19[^\n]", arr[*count].author);

        printf("Enter the price : ");
        scanf("%d", &arr[*count].price);

        printf("Enter the year of publication : ");
        scanf("%d", &arr[*count].year);

        (*count)++;

        printf("\nDo you want to enter more books? (Y/N) : ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return arr;
}

void deleteBookById(struct book *arr, int *count)
{
    int id;
    printf("Enter the Id of book to delete.");
    scanf("%d", &id);

    if (count == 0)
    {
        printf("There are no books.\n");
        return;
    }
    int found = 0;

    for (int i = 0; i < *count; i++)
    {
        if (arr[i].bookId == id)
        {
            found = 1;
            for (int j = i; j < (*count) - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            (*count)--;
            printf("Book with ID %d deleted successfully!\n", id);
            break;
        }
    }
    if (!found)
    {
        printf("Book with ID %d not found!\n", id);
    }
}

void displayBooks(struct book *arr, int count)
{
    if (count == 0)
    {
        printf("There are no books.\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf(" Book Id : %d\n", arr[i].bookId);
        printf(" Book title : %s\n", arr[i].title);
        printf(" Book Author : %s\n", arr[i].author);
        printf(" Book Price : %d\n", arr[i].price);
        printf(" year of publication : %d\n", arr[i].year);
    }
}

void displayByAuthor(struct book *arr, int count)
{
    char author[20];
    printf("Enter author name : ");
    scanf(" %19[^\n]", author);

    if (count == 0)
    {
        printf("There are no books.\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        if (arr[i].author == author)
        {
            printf(" Book Id : %d\n", arr[i].bookId);
            printf(" Book title : %s\n", arr[i].title);
            printf(" Book Author : %s\n", arr[i].author);
            printf(" Book Price : %d\n", arr[i].price);
            printf(" year of publication : %d\n", arr[i].year);
        }
    }
}

void displayByYear(struct book *arr, int count)
{
    int year;
    printf("Enter year : ");
    scanf("%d", &year);

    if (count == 0)
    {
        printf("There are no books.\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        if (arr[i].year == year)
        {
            printf(" Book Id : %d\n", arr[i].bookId);
            printf(" Book title : %s\n", arr[i].title);
            printf(" Book Author : %s\n", arr[i].author);
            printf(" Book Price : %d\n", arr[i].price);
            printf(" year of publication : %d\n", arr[i].year);
        }
    }
}

void average(struct book *arr, int count)
{
    if (count == 0)
    {
        printf("No data found.\n");
        return;
    }
    float avg = 0;
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += arr[i].price;
    }
    avg = sum / count;

    printf("The average price of books is : %f\n.", avg);
}

int main(void)
{
    int choice;

    struct book *arr = NULL;

    int count = 0;

    while (1)
    {
        printf("\n\n1.Add Book \n2.Delete book by id \n3.Print all books \n4.Print books of an Author. \n5.Print books published in a year. \n6.Find average price of books.\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            arr = addBook(arr, &count);
            break;
        case 2:
            deleteBookById(arr, &count);
            break;
        case 3:
            displayBooks(arr, count);
            break;
        case 4:
            displayByAuthor(arr, count);
            break;
        case 5:
            displayByYear(arr, count);
            break;
        case 6:
            average(arr, count);
            break;
        case 7:
            free(arr);
            break;
        }
    }

    return 0;
}