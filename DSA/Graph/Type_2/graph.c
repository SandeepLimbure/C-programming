#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct Node *createNode(int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = vertices;
    graph->head = (struct Node **)malloc(vertices * sizeof(struct Node *));

    for (int i = 0; i < vertices; i++)
        graph->head[i] = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    if (src >= 0 && src < graph->V && dest >= 0 && dest < graph->V)
    {
        // Add edge from src to dest
        struct Node *newNode = createNode(dest);
        newNode->next = graph->head[src];
        graph->head[src] = newNode;

        // Add edge from dest to src (Remove for directed graph)
        newNode = createNode(src);
        newNode->next = graph->head[dest];
        graph->head[dest] = newNode;

        printf("Edge added between %d and %d.\n", src, dest);
    }
    else
    {
        printf("Invalid vertices!\n");
    }
}

void printGraph(struct Graph *graph)
{
    printf("\nAdjacency List:\n");
    for (int i = 0; i < graph->V; i++)
    {
        struct Node *temp = graph->head[i];
        printf("Vertex %d: ", i);
        while (temp)
        {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->V; i++)
    {
        struct Node *temp = graph->head[i];
        while (temp)
        {
            struct Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->head);
    free(graph);
}