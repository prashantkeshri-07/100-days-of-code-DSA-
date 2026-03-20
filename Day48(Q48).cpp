//Count Leaf Nodes
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // If tree is empty
    if (root == NULL)
        return 0;
    
    // If node has no children, it is a leaf
    if (root->left == NULL && root->right == NULL)
        return 1;
    
    // Recursively sum leaves from left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Interactive function to build a tree (Depth-First)
struct Node* buildTree() {
    int val;
    printf("Enter node data (-1 for no node): ");
    scanf("%d", &val);

    if (val == -1) {
        return NULL;
    }

    struct Node* root = createNode(val);

    printf("Entering left child of %d:\n", val);
    root->left = buildTree();

    printf("Entering right child of %d:\n", val);
    root->right = buildTree();

    return root;
}

int main() {
    printf("--- Build Your Binary Tree ---\n");
    struct Node* root = buildTree();

    int totalLeaves = countLeafNodes(root);
    printf("\nTotal number of leaf nodes: %d\n", totalLeaves);

    return 0;
}
