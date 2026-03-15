#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue implementation for tree construction
struct Node* queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Function to build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;
    while (i < n && !isEmpty()) {
        struct Node* current = dequeue();

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    inorder(root);

    return 0;
}