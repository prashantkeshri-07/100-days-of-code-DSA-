//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper to create a new tree node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void zigzagTraversal(struct Node* root, int n) {
    if (!root) return;

    // Use two arrays to track levels
    struct Node** currentLevel = (struct Node**)malloc(sizeof(struct Node*) * n);
    struct Node** nextLevel = (struct Node**)malloc(sizeof(struct Node*) * n);
    int currIdx = 0, nextIdx = 0;
    bool leftToRight = true;

    currentLevel[currIdx++] = root;

    while (currIdx > 0) {
        int levelSize = currIdx;
        int* tempValues = (int*)malloc(sizeof(int) * levelSize);
        
        nextIdx = 0;
        for (int i = 0; i < levelSize; i++) {
            struct Node* node = currentLevel[i];
            tempValues[i] = node->data;

            // Collect children for the next level
            if (node->left) nextLevel[nextIdx++] = node->left;
            if (node->right) nextLevel[nextIdx++] = node->right;
        }

        // Print values based on current direction
        if (leftToRight) {
            for (int i = 0; i < levelSize; i++) printf("%d ", tempValues[i]);
        } else {
            for (int i = levelSize - 1; i >= 0; i--) printf("%d ", tempValues[i]);
        }

        // Clean up and prepare for the next level
        free(tempValues);
        for(int i = 0; i < nextIdx; i++) currentLevel[i] = nextLevel[i];
        currIdx = nextIdx;
        leftToRight = !leftToRight;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    printf("Enter level-order traversal values (-1 for NULL):\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) return 0;

    // Build the tree using level-order logic
    struct Node* root = newNode(arr[0]);
    struct Node** q = (struct Node**)malloc(sizeof(struct Node*) * n);
    int f = 0, r = 0;
    q[r++] = root;

    int i = 1;
    while (i < n && f < r) {
        struct Node* curr = q[f++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) q[r++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) q[r++] = curr->right;
        }
    }

    printf("\nZigzag Traversal: ");
    zigzagTraversal(root, n);

    return 0;
}
