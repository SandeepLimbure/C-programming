#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *removeLastNode(Node *head)
{
    if (head == NULL)
        return head;

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    return head;
}