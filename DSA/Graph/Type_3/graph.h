#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 50

extern int adjMatrix[MAX_VERTICES][MAX_VERTICES];
extern int numVertices;

void initGraph(int vertices);
void addWeightedEdge(int src, int dest, int weight);
void removeEdge(int src, int dest);
void printGraph();

#endif