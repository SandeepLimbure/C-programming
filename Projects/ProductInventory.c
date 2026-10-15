#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    short int product_id;
    char name[20];
    short int quantity;
    int price;
} product;

product *addProduct(product *arr, int *count)
{
    char choice;

    do
    {
        product *temp = (product *)realloc(arr, (*count + 1) * sizeof(product));

        if (temp == NULL)
        {
            printf("memory allocation failed.\n");
            return NULL;
        }

        arr = temp;

        printf("Enter the product id : ");
        scanf("%hd", &arr[*count].product_id);

        printf("Enter product name : ");
        scanf(" %19[^\n]", arr[*count].name);

        printf("Enter the quantity : ");
        scanf("%hd", &arr[*count].quantity);

        printf("Enter the price : ");
        scanf("%d", &arr[*count].price);

        (*count)++;

        printf("Do you want to add more products? (y/n) : ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return arr;
}

void delete(product *arr, int *count)
{
    int found = 0, id;

    printf("Enter the product id : ");
    scanf("%d", &id);

    if (*count == 0)
    {
        printf("the product list is empty.\n");
        return;
    }

    for (int i = 0; i < (*count); i++)
    {
        if (arr[i].product_id == id)
        {
            found = 1;
            for (int j = i; j < (*count); j++)
            {
                arr[j] = arr[j + 1];
            }
            printf("Product deleted successfully.\n");
            (*count)--;
            return;
        }
    }

    if (!found)
    {
        printf("The product is not found.\n");
        return;
    }
}

void lowStock(product *arr, int count)
{
    int limit;
    printf("Enter the limit : ");
    scanf("%d", &limit);
    if (count == 0)
    {
        printf("the product list is empty.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (arr[i].quantity < limit)
        {
            printf("The product with %d product id has low stock.\n", arr[i].product_id);
        }
    }
}

void totalInventoryValue(product *arr, int count)
{
    int totalValue = 0;

    if (count == 0)
    {
        printf("the product list is empty.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        totalValue += (arr[i].quantity * arr[i].price);
    }

    printf("The total value of Inventory is : %d\n", totalValue);
}

void updateQuantity(product *arr, int count)
{
    int found = 0, id, quantity;

    printf("Enter the product id : ");
    scanf("%d", &id);

    printf("Enter the quantity : ");
    scanf("%d", &quantity);

    if (count == 0)
    {
        printf("the product list is empty.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (arr[i].product_id == id)
        {
            found = 1;
            arr[i].quantity = quantity;
            break;
        }
    }

    if (!found)
    {
        printf("product with %d product id not found.\n", id);
    }
    else
    {
        printf("product quantity updated successfully.\n");
    }
}

void display(product *arr, int count)
{
    if (count == 0)
    {
        printf("the product list is empty.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("------------------- product %d -----------------------\n", i + 1);
        printf("product id : %hd\n", arr[i].product_id);
        printf("product namer : %s\n", arr[i].name);
        printf("product quantity : %hd\n", arr[i].quantity);
        printf("product price : %d\n", arr[i].price);
        printf("-------------------------------------------------------\n");
    }
}

void destroy(product *arr)
{
    if (arr != NULL)
    {
        free(arr);
        arr = NULL;
        printf("memory freed successfully.!\n");
    }
}

int main(void)
{
    int choice, count = 0;

    product *arr = NULL;

    do
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            arr = addProduct(arr, &count);
            break;
        case 2:
            delete(arr, &count);
            break;
        case 3:
            lowStock(arr, count);
            break;
        case 4:
            totalInventoryValue(arr, count);
            break;
        case 5:
            updateQuantity(arr, count);
            break;
        case 6:
            display(arr, count);
            break;
        case 7:
            destroy(arr);
        }
    } while (choice != 0);

    return 0;
}