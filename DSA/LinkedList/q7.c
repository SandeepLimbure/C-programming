#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *moveToFront(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *secLast = NULL;
    node *last = NULL;

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }

    secLast->next = NULL;

    last->next = head;

    head = last;

    return head;
}