//Perform inorder, preorder, and postorder traversals of a given binary tree.
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL; // -1 represents a NULL node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to build the tree from level-order array using a queue
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* current = queue[head++];

        // Left child
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[tail++] = current->left;
        }

        // Right child
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[tail++] = current->right;
        }
    }
    free(queue);
    return root;
}

void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    printf("Enter number of elements (N): ");
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    printf("Enter level-order elements (use -1 for NULL nodes):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("\nInorder Traversal:   ");
    printInorder(root);
    
    printf("\nPreorder Traversal:  ");
    printPreorder(root);
    
    printf("\nPostorder Traversal: ");
    printPostorder(root);
    printf("\n");

    free(arr);
    return 0;
}
