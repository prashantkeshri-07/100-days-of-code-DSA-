//Check whether a given binary tree is symmetric around its center.#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to check if two subtrees are mirrors
bool isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return true; // Both null is symmetric
    if (t1 == NULL || t2 == NULL) return false; // One null, one not is asymmetric
    
    // Values must match and subtrees must be mirrored
    return (t1->data == t2->data) && 
           isMirror(t1->left, t2->right) && 
           isMirror(t1->right, t2->left);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter level-order traversal (use -1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build the tree using a queue
    struct Node* root = createNode(arr[0]);
    if (root == NULL) {
        printf("YES\n"); // Empty tree is symmetric
        return 0;
    }

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = queue[head++];
        if (curr == NULL) continue;

        // Assign left child
        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        // Assign right child
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }

    // Final Symmetry Check
    if (isMirror(root->left, root->right)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    // Optional: Free allocated memory here
    free(arr);
    free(queue);
    return 0;
}
