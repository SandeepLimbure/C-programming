#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int length(Node *head)
{
    int count = 0;

    if (head == NULL)
    {
        return count;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}