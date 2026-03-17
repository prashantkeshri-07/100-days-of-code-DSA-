//Find the height (maximum depth) of a given binary tree.
#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Simple Queue for level-order construction
struct Node** createQueue(int size, int *front, int *rear) {
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * size);
    *front = *rear = 0;
    return queue;
}

void enqueue(struct Node** queue, int *rear, struct Node* node) {
    queue[(*rear)++] = node;
}

struct Node* dequeue(struct Node** queue, int *front) {
    return queue[(*front)++];
}

// Function to calculate height
int getHeight(struct Node* root) {
    if (root == NULL) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    int n;
    printf("Enter the number of nodes (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int*)malloc(sizeof(int) * n);
    printf("Enter level-order traversal (use -1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build the tree
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = arr[0];
    root->left = root->right = NULL;

    int front, rear;
    struct Node** queue = createQueue(n, &front, &rear);
    enqueue(queue, &rear, root);

    int i = 1;
    while (i < n) {
        struct Node* temp = dequeue(queue, &front);

        // Left Child
        if (i < n && arr[i] != -1) {
            temp->left = (struct Node*)malloc(sizeof(struct Node));
            temp->left->data = arr[i];
            temp->left->left = temp->left->right = NULL;
            enqueue(queue, &rear, temp->left);
        }
        i++;

        // Right Child
        if (i < n && arr[i] != -1) {
            temp->right = (struct Node*)malloc(sizeof(struct Node));
            temp->right->data = arr[i];
            temp->right->left = temp->right->right = NULL;
            enqueue(queue, &rear, temp->right);
        }
        i++;
    }

    printf("\nMaximum Height: %d\n", getHeight(root));

    return 0;
}
