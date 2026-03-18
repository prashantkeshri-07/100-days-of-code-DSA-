// Level Order Traversal
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node for BFS
struct Queue {
    struct Node* treeNode;
    struct Queue* next;
};

// Function to create a new tree node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Basic Queue operations
void enqueue(struct Queue** head, struct Queue** tail, struct Node* tNode) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->treeNode = tNode;
    temp->next = NULL;
    if (*tail == NULL) {
        *head = *tail = temp;
        return;
    }
    (*tail)->next = temp;
    *tail = temp;
}

struct Node* dequeue(struct Queue** head, struct Queue** tail) {
    if (*head == NULL) return NULL;
    struct Queue* temp = *head;
    struct Node* tNode = temp->treeNode;
    *head = (*head)->next;
    if (*head == NULL) *tail = NULL;
    free(temp);
    return tNode;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue *head = NULL, *tail = NULL;
    enqueue(&head, &tail, root);

    while (head != NULL) {
        struct Node* current = dequeue(&head, &tail);
        printf("%d ", current->data);

        if (current->left) enqueue(&head, &tail, current->left);
        if (current->right) enqueue(&head, &tail, current->right);
    }
}

// Helper to build a simple tree for interaction
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    printf("--- Level Order Traversal (BFS) ---\n");
    while (1) {
        printf("\n1. Insert Node\n2. Print Level Order\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Result: ");
                levelOrder(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
