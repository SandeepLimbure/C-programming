#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct Node *createNode(int dest, int weight)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
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

void addWeightedEdge(struct Graph *graph, int src, int dest, int weight)
{
    if (src >= 0 && src < graph->V && dest >= 0 && dest < graph->V)
    {
        // Add edge from src to dest
        struct Node *newNode = createNode(dest, weight);
        newNode->next = graph->head[src];
        graph->head[src] = newNode;

        // Add edge from dest to src (Remove for directed graph)
        newNode = createNode(src, weight);
        newNode->next = graph->head[dest];
        graph->head[dest] = newNode;

        printf("Weighted edge added between %d and %d (Weight: %d).\n", src, dest, weight);
    }
    else
    {
        printf("Invalid vertices!\n");
    }
}

void printGraph(struct Graph *graph)
{
    printf("\nWeighted Adjacency List:\n");
    for (int i = 0; i < graph->V; i++)
    {
        struct Node *temp = graph->head[i];
        printf("Vertex %d: ", i);
        while (temp)
        {
            printf("[%d|W:%d] -> ", temp->dest, temp->weight);
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