//Height of Binary Tree
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
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

// Interactive function to build the tree
struct Node* buildTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) return NULL;

    struct Node* root = newNode(data);

    printf("Enter left child of %d:\n", data);
    root->left = buildTree();

    printf("Enter right child of %d:\n", data);
    root->right = buildTree();

    return root;
}

// Function to calculate the height of the tree
int getHeight(struct Node* node) {
    if (node == NULL) {
        return 0; // Height of an empty tree is 0
    } else {
        // Recursively find the height of each subtree
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        // Use the larger height and add 1 for the current node
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

int main() {
    printf("--- Build your Binary Tree ---\n");
    struct Node* root = buildTree();

    int height = getHeight(root);
    printf("\nThe height of the binary tree is: %d\n", height);

    return 0;
}
