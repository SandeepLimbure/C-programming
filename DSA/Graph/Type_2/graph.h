#ifndef GRAPH_H
#define GRAPH_H

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** head;
};

struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void freeGraph(struct Graph* graph);

#endif