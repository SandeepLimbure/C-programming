#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int identical(Node *head1, Node *head2)
{
    Node *temp1 = head1, *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return (temp1 == NULL && temp2 == NULL);
}