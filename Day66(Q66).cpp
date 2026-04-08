//Problem: Detect cycle in directed graph using DFS and recursion stack.
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to perform DFS and detect cycle
bool isCyclicUtil(int v, int n, int adj[MAX][MAX], bool visited[MAX], bool recStack[MAX]) {
    if (!visited[v]) {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1) {
                if (!visited[i] && isCyclicUtil(i, n, adj, visited, recStack))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    // Remove the vertex from recursion stack before returning
    recStack[v] = false;
    return false;
}

int main() {
    int n, edges, u, v;
    int adj[MAX][MAX] = {0};
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    printf("--- Cycle Detection in Directed Graph (DFS) ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = 1;
        } else {
            printf("Invalid vertex! Try again.\n");
            i--;
        }
    }

    bool cycleFound = false;
    for (int i = 0; i < n; i++) {
        if (isCyclicUtil(i, n, adj, visited, recStack)) {
            cycleFound = true;
            break;
        }
    }

    if (cycleFound) {
        printf("\nResult: YES\n");
    } else {
        printf("\nResult: NO\n");
    }

    return 0;
}
