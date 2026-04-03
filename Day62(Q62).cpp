//Build a graph with adjacency list representation. Use linked lists or dynamic arrays.
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a dynamic array for each vertex
typedef struct {
    int *neighbors;
    int count;
    int capacity;
} AdjList;

int main() {
    int n, m, isDirected;

    printf("Enter number of vertices (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter number of edges (m): ");
    scanf("%d", &m);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    // 1. Allocate the array of lists
    AdjList *graph = (AdjList *)malloc(n * sizeof(AdjList));
    if (graph == NULL) return 1;

    for (int i = 0; i < n; i++) {
        graph[i].count = 0;
        graph[i].capacity = 2; // Start with space for 2 neighbors
        graph[i].neighbors = (int *)malloc(graph[i].capacity * sizeof(int));
    }

    // 2. Input edges with validation
    printf("Enter %d pairs of edges (u v) between 0 and %d:\n", m, n - 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        if (scanf("%d %d", &u, &v) != 2) break;

        // Check if indices are within bounds
        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Error: Vertices must be between 0 and %d. Try again.\n", n - 1);
            i--; 
            continue;
        }

        // Add u -> v
        if (graph[u].count == graph[u].capacity) {
            graph[u].capacity *= 2;
            graph[u].neighbors = (int *)realloc(graph[u].neighbors, graph[u].capacity * sizeof(int));
        }
        graph[u].neighbors[graph[u].count++] = v;

        // If undirected, add v -> u
        if (!isDirected) {
            if (graph[v].count == graph[v].capacity) {
                graph[v].capacity *= 2;
                graph[v].neighbors = (int *)realloc(graph[v].neighbors, graph[v].capacity * sizeof(int));
            }
            graph[v].neighbors[graph[v].count++] = u;
        }
    }

    // 3. Print the Result
    printf("\n--- Adjacency List ---\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph[i].count; j++) {
            printf("%d ", graph[i].neighbors[j]);
        }
        printf("\n");
    }

    // 4. Free Memory
    for (int i = 0; i < n; i++) {
        free(graph[i].neighbors);
    }
    free(graph);

    return 0;
}

