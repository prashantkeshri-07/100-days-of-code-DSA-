//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
#include <stdio.h>
#include <stdlib.h>

// Define the BST Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

// Function to find the LCA
int findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        // If both nodes are smaller, LCA is in left
        if (root->data > n1 && root->data > n2)
            root = root->left;
        // If both nodes are greater, LCA is in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        // We found the split point
        else
            break;
    }
    return root->data;
}

int main() {
    int n, val, p, q;
    struct Node* root = NULL;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Enter %d node values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter the two nodes to find LCA for: ");
    scanf("%d %d", &p, &q);

    int lca = findLCA(root, p, q);
    printf("The LCA of %d and %d is: %d\n", p, q, lca);

    return 0;
}
