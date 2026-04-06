//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int node;
    int parent;
} StackFrame;

bool hasCycleIterative(int adj[MAX][MAX], int V, int startNode, bool visited[MAX]) {
    StackFrame stack[MAX * MAX];
    int top = -1;

    // Push initial node with -1 as parent
    stack[++top] = (StackFrame){startNode, -1};

    while (top >= 0) {
        StackFrame current = stack[top--];
        int u = current.node;
        int p = current.parent;

        if (!visited[u]) {
            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (adj[u][v]) {
                    if (!visited[v]) {
                        stack[++top] = (StackFrame){v, u};
                    } else if (v != p) {
                        // Found a visited neighbor that is not the parent
                        return true; 
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    int adj[MAX][MAX] = {0};
    bool visited[MAX] = {false};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    bool found = false;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleIterative(adj, V, i, visited)) {
                found = true;
                break;
            }
        }
    }

    if (found) printf("YES\n");
    else printf("NO\n");

    return 0;
}
