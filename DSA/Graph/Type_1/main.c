#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    int choice, vertices, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    initGraph(vertices);

    while (1)
    {
        printf("\n--- Graph Menu (Adjacency Matrix) ---\n");
        printf("1. Add Edge\n2. Remove Edge\n3. Print Graph\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter source and destination (0 to %d): ", vertices - 1);
            scanf("%d %d", &src, &dest);
            addEdge(src, dest);
            break;
        case 2:
            printf("Enter source and destination (0 to %d): ", vertices - 1);
            scanf("%d %d", &src, &dest);
            removeEdge(src, dest);
            break;
        case 3:
            printGraph();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}