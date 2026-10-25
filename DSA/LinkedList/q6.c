#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *insert(Node *head, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
        return head;
    }

    if (key < head->data)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *temp = head;

    while (temp->next != NULL && temp->next->data < key)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}