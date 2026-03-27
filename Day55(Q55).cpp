//Print the nodes visible when the binary tree is viewed from the right side.
#include <stdio.h>
#include <stdlib.h>

// Standard tree node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure to handle level-order traversal
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a new node or return NULL if value is -1
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Basic Queue Operations
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* treeNode) {
    if (!treeNode) return;
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    struct Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

// Logic: Process each level and print only the last node
void printRightView(struct Node* root) {
    if (!root) return;
    struct Queue* q = createQueue();
    enqueue(q, root);

    while (q->front != NULL) {
        int level_size = 0;
        struct QueueNode* temp = q->front;
        while(temp) { level_size++; temp = temp->next; }

        for (int i = 0; i < level_size; i++) {
            struct Node* curr = dequeue(q);
            if (i == level_size - 1) printf("%d ", curr->data);
            if (curr->left) enqueue(q, curr->left);
            if (curr->right) enqueue(q, curr->right);
        }
    }
}

// Reconstructs tree from level-order array input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root);
    int i = 1;
    while (i < n && q->front != NULL) {
        struct Node* curr = dequeue(q);
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) enqueue(q, curr->left);
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) enqueue(q, curr->right);
        }
    }
    return root;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    printf("Right View: ");
    printRightView(root);
    printf("\n");
    return 0;
}
