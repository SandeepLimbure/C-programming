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
            adjMatrix[i][j] = 0; // 0 indicates no edge
        }
    }
}

void addDirectedEdge(int src, int dest, int weight)
{
    if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
    {
        adjMatrix[src][dest] = weight;
        // Notice we DO NOT set adjMatrix[dest][src] for a directed graph
        printf("Directed edge added from %d to %d with weight %d.\n", src, dest, weight);
    }
    else
    {
        printf("Invalid vertices!\n");
    }
}

void removeDirectedEdge(int src, int dest)
{
    if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
    {
        adjMatrix[src][dest] = 0;
        printf("Directed edge removed from %d to %d.\n", src, dest);
    }
    else
    {
        printf("Invalid vertices!\n");
    }
}

void printGraph()
{
    printf("\nWeighted Directed Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%4d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}