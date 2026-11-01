#ifndef GRAPH_H
#define GRAPH_H

struct Node
{
    int dest;
    int weight;
    struct Node *next;
};

struct Graph
{
    int V;
    struct Node **head;
};

struct Graph *createGraph(int vertices);
void addDirectedEdge(struct Graph *graph, int src, int dest, int weight);
void printGraph(struct Graph *graph);
void freeGraph(struct Graph *graph);

#endif