//Problem: Perform DFS starting from a given source vertex using recursion.
#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node and Graph structure
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// 2. Initialize a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL; // Memory check
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// 3. Initialize the graph with n vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// 4. Add an edge (Directed)
void addEdge(struct Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices) return;
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// 5. Recursive DFS Traversal
void DFS(struct Graph* graph, int vertex) {
    // Mark vertex as visited (1 = true)
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, e, s, u, v;

    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &e) != 2) return 1;

    struct Graph* graph = createGraph(n);

    printf("Enter %d edges (format: source destination):\n", e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    if (s >= 0 && s < n) {
        printf("DFS Traversal Order: ");
        DFS(graph, s);
        printf("\n");
    } else {
        printf("Error: Invalid starting vertex.\n");
    }

    return 0;
}



