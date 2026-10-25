#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int DataAtIndex(Node *head, int index)
{
    if (head == NULL)
    {
        return -1;
    }

    Node *temp = head;
    for (int i = 1; i < index; i++)
    {
        if (temp == NULL)
        {
            return -1;
        }
        temp = temp->next;
    }

    return (temp == NULL) ? -1 : temp->data;
}