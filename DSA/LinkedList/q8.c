#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *removeDuplicates(Node *headRef)
{
    // code here
    if (headRef == NULL)
    {
        return headRef;
    }

    Node *temp = headRef;

    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            Node *newNode = temp->next;
            temp->next = newNode->next;
            free(newNode);
        }
        else
        {
            temp = temp->next;
        }
    }

    return headRef;
}