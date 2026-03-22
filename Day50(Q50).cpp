//BST Search
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node with data
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) return NULL; // Safety check for memory allocation
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST and return the (potentially new) root
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// Search for a key in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (root->data < key) return search(root->right, key);
    return search(root->left, key);
}

// Helper to show the tree (In-order traversal)
void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main() {
    struct Node* root = NULL; // Crucial: Initialize to NULL
    int choice, value;

    printf("--- Robust BST Interactive Program ---\n");
    
    while(1) {
        printf("\n1. Insert  2. Search  3. View Tree  4. Exit\nChoice: ");
        
        // Validation: If scanf fails (e.g., user enters a letter), clear the buffer
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 4) break;

        switch(choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) == 1) root = insert(root, value);
                break;
            case 2:
                printf("Search for: ");
                if (scanf("%d", &value) == 1) {
                    struct Node* res = search(root, value);
                    printf(res ? "Found!\n" : "Not in tree.\n");
                }
                break;
            case 3:
                printf("Tree (Sorted): ");
                display(root);
                printf("\n");
                break;
            default:
                printf("Pick 1-4.\n");
        }
    }
    return 0;
}
