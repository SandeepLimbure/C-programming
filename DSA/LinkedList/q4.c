#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int frequency(Node *head, int key)
{
    int count = 0;

    if (head == NULL)
    {
        return count;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            count++;
        }
        temp = temp->next;
    }

    return count;
}