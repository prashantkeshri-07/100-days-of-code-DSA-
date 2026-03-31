//Construct a binary tree from given inorder and postorder traversal arrays.
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

// Search for the index of a value in the inorder array
int findInorderIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Recursive function to build the tree
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIdx) {
    if (inStart > inEnd) return NULL;

    // The root is the current element at postIdx in postorder array
    int curr = postorder[*postIdx];
    struct Node* node = newNode(curr);
    (*postIdx)--;

    // If node has no children, return it
    if (inStart == inEnd) return node;

    // Find root's position in inorder to split subtrees
    int inIdx = findInorderIndex(inorder, inStart, inEnd, curr);

    // Build Right subtree before Left (because we process postorder from the end)
    node->right = buildTree(inorder, postorder, inIdx + 1, inEnd, postIdx);
    node->left = buildTree(inorder, postorder, inStart, inIdx - 1, postIdx);

    return node;
}

// Print the tree in Preorder (Root -> Left -> Right)
void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1) return 1;

    int inorder[n], postorder[n];

    printf("Enter the Inorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    printf("Enter the Postorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIdx = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIdx);

    printf("Preorder Traversal: ");
    printPreorder(root);
    printf("\n");

    return 0;
}
