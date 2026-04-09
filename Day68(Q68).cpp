//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to perform Kahn's Algorithm
void kahnAlgorithm(int n, int adj[MAX][MAX], int in_degree[MAX]) {
    int queue[MAX], front = 0, rear = 0;
    int topo_order[MAX], count = 0;

    // 1. Initial queue: add all nodes with 0 in-degree
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // 2. Process queue: remove node, update neighbors, add new 0-degree nodes
    while (front < rear) {
        int u = queue[front++];
        topo_order[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // 3. Result and cycle detection
    if (count < n) {
        printf("\nError: The graph contains a cycle! Topological sort not possible.\n");
    } else {
        printf("\nTopological Sort Order: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, edges, u, v;
    int adj[MAX][MAX] = {0};
    int in_degree[MAX] = {0};

    printf("--- Interactive Kahn's Algorithm ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination) using 0-based indexing:\n");
    for (int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        
        // Input validation
        if (u >= n || v >= n || u < 0 || v < 0) {
            printf("Invalid vertex index! Use 0 to %d.\n", n - 1);
            i--; // Repeat this iteration
            continue;
        }
        
        adj[u][v] = 1;
        in_degree[v]++;
    }

    kahnAlgorithm(n, adj, in_degree);

    return 0;
}
