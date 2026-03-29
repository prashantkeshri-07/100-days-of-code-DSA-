//Convert a binary tree into its mirror image by swapping left and right children at every node.
#include <stdio.h>
#include <stdlib.h>

// Standard Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Mirror function: Swaps left and right pointers recursively
void mirror(struct Node* node) {
    if (node == NULL) return;
    
    mirror(node->left);
    mirror(node->right);

    // Swap the pointers
    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

// Inorder Traversal: Left -> Root -> Right
void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) return 0;

    int arr[n];
    printf("Enter level-order traversal (use -1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build the tree using a simple Queue-based approach
    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        
        // Assign left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[tail++] = curr->left;
        }
        i++;

        // Assign right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[tail++] = curr->right;
        }
        i++;
    }

    printf("\nMirroring the tree...\n");
    mirror(root);

    printf("Inorder Traversal of Mirrored Tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}
