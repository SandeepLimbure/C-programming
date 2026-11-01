#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    int choice, vertices, src, dest, weight;
    struct Graph *graph = NULL;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    graph = createGraph(vertices);

    while (1)
    {
        printf("\n--- Weighted Graph Menu (Adjacency List) ---\n");
        printf("1. Add Weighted Edge\n2. Print Graph\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter source, destination (0 to %d), and weight: ", vertices - 1);
            scanf("%d %d %d", &src, &dest, &weight);
            addWeightedEdge(graph, src, dest, weight);
            break;
        case 2:
            printGraph(graph);
            break;
        case 3:
            freeGraph(graph);
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}