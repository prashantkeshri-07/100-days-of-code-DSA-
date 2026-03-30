//Construct a binary tree from given preorder and inorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find the index of a value in an array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Recursive function to construct the tree
struct Node* buildTree(int in[], int pre[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    // Pick current node from Preorder traversal using preIndex
    struct Node* root = newNode(pre[(*preIndex)++]);

    // If this node has no children, return
    if (inStart == inEnd) return root;

    // Else find the index of this node in Inorder traversal
    int inIndex = search(in, inStart, inEnd, root->data);

    // Using index in Inorder traversal, construct left and right subtrees
    root->left = buildTree(in, pre, inStart, inIndex - 1, preIndex);
    root->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return root;
}

// Function to print postorder traversal
void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    int pre[n], in[n];

    printf("Enter Preorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);

    printf("Enter Inorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    int preIndex = 0;
    struct Node* root = buildTree(in, pre, 0, n - 1, &preIndex);

    printf("Postorder traversal: ");
    printPostorder(root);
    printf("\n");

    return 0;
}
