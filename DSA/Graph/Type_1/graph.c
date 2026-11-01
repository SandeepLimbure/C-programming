#include <stdio.h>
#include "graph.h"

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;

void initGraph(int vertices)
{
    numVertices = vertices;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest)
{
    if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
    {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        printf("Edge added between %d and %d.\n", src, dest);
    }
    else
    {
        printf("Invalid vertices!\n");
    }
}

void removeEdge(int src, int dest)
{
    if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
    {
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0;
        printf("Edge removed between %d and %d.\n", src, dest);
    }
    else
    {
        printf("Invalid vertices!\n");
    }
}

void printGraph()
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}