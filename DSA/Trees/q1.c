#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createRoot(int val)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    printf("Node added successfully.\n");
    return newNode;
}

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        return createRoot(val);
    }
    char choice;

    printf("Enter the char to insert (l-left and r-right) : ");
    scanf(" %c", &choice);

    if (choice == 'l' || choice == 'L')
    {
        root->left = insert(root->left, val);
    }
    else if (choice == 'r' || choice == 'R')
    {
        root->right = insert(root->right, val);
    }
    else
    {
        printf("Node addition failed !!. Enter a valid choice \n");
    }

    return root;
}

int Getheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = Getheight(root->left);
    int right = Getheight(root->right);

    return (left > right) ? (left + 1) : (right + 1);
}

void printLevelOrder(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf("%d ", root->data);
        return;
    }
    else
    {
        printLevelOrder(root->left, level - 1);
        printLevelOrder(root->right, level - 1);
    }
}

void LevelOrderTraversal(node *root)
{
    int h = Getheight(root);

    for (int i = 1; i <= h; i++)
    {
        printLevelOrder(root, i);
    }
}

void PostOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    printf("%d ", root->data);
}

void PreOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void InOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrderTraversal(root->left);
    printf("%d ", root->data);
    InOrderTraversal(root->right);
}

void freeTree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

int main(void)
{
    node *root = NULL;
    int choice, val;

    while (1)
    {
        printf("\n========== BINARY TREE MENU ==========\n");
        printf("1. Insert Node\n");
        printf("2. Level-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. In-Order Traversal\n");
        printf("5. Post-Order Traversal\n");
        printf("6. Get Tree Height\n");
        printf("7. Exit\n");
        printf("======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 2:
            printf("Level-Order Traversal: ");
            LevelOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Pre-Order Traversal: ");
            PreOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("In-Order Traversal: ");
            InOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Post-Order Traversal: ");
            PostOrderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("Tree Height is: %d\n", Getheight(root));
            break;
        case 7:
            freeTree(root);
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}