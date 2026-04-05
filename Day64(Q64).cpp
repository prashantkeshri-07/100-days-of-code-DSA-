//Problem: Perform BFS from a given source using queue.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure using an array
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

// Add element to queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Remove element from queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) return -1;
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// BFS logic
void bfs(int adj[MAX][MAX], int n, int startNode) {
    struct Queue q;
    int visited[MAX];
    int i, u, v;

    // Initialize visited array to 0 (false)
    for (i = 0; i < n; i++) visited[i] = 0;

    initQueue(&q);
    visited[startNode] = 1;
    enqueue(&q, startNode);

    printf("\nBFS Traversal Order: ");

    while (!isEmpty(&q)) {
        u = dequeue(&q);
        printf("%d ", u);

        for (v = 0; v < n; v++) {
            if (adj[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                enqueue(&q, v);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, source, i, j;
    int adj[MAX][MAX];

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source node.\n");
    } else {
        bfs(adj, n, source);
    }

    return 0;
}

