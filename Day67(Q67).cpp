//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

// DFS to explore nodes and push to stack after visiting all neighbors
void dfs(int v, int n, int adj[MAX][MAX], bool visited[MAX]) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }

    // Finished visiting all dependencies, now safe to add to ordering
    push(v);
}

int main() {
    int n, edges, u, v;
    int adj[MAX][MAX] = {0};
    bool visited[MAX] = {false};

    printf("--- Interactive Topological Sort (DFS) ---\n");
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge as 'source destination' (e.g., 5 2):\n");
    for (int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        if (u >= n || v >= n || u < 0 || v < 0) {
            printf("Invalid indices! Use nodes between 0 and %d.\n", n - 1);
            i--; // Retry this edge
            continue;
        }
        adj[u][v] = 1;
    }

    // Run DFS for every unvisited node to handle disconnected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, adj, visited);
        }
    }

    printf("\nTopological Ordering: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    return 0;
}
