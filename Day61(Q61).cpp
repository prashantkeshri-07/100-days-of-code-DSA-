//Build a graph with n vertices and m edges using adjacency matrix representation.
//The graph may be directed or undirected.
#include <stdio.h>

int main() {
    int n, m, isDirected;

    // 1. Get graph dimensions and type
    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    // 2. Initialize n x n matrix with zeros
    int adjMatrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // 3. Accept edge connections
    printf("Enter number of edges (m): ");
    scanf("%d", &m);

    printf("Enter %d pairs of edges (u v) where 0 <= u,v < %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // Validation and insertion
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adjMatrix[u][v] = 1;
            if (!isDirected) {
                adjMatrix[v][u] = 1; // Symmetrical for undirected graphs
            }
        } else {
            printf("Invalid vertices! Please use values between 0 and %d.\n", n - 1);
            i--; // Retry this edge
        }
    }

    // 4. Output the final matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
