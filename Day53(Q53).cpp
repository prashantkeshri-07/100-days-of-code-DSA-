//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
#include <stdio.h>
#include <stdlib.h>

// Node structure for the Binary Tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Node for a Linked List to store horizontal distance groups
struct List {
    int data;
    struct List* next;
};

// Map-like structure to store horizontal distances
struct MapNode {
    int hd;
    struct List* head;
    struct List* tail;
    struct MapNode *left, *right;
};

// Create a new tree node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Add value to the linked list associated with a specific HD
void addToList(struct MapNode* mNode, int data) {
    struct List* temp = (struct List*)malloc(sizeof(struct List));
    temp->data = data;
    temp->next = NULL;
    if (mNode->head == NULL) {
        mNode->head = mNode->tail = temp;
    } else {
        mNode->tail->next = temp;
        mNode->tail = temp;
    }
}

// Insert HD into a Binary Search Tree (to keep HDs sorted)
struct MapNode* insertMap(struct MapNode* root, int hd, int data) {
    if (root == NULL) {
        struct MapNode* temp = (struct MapNode*)malloc(sizeof(struct MapNode));
        temp->hd = hd;
        temp->head = temp->tail = NULL;
        temp->left = temp->right = NULL;
        addToList(temp, data);
        return temp;
    }
    if (hd == root->hd) addToList(root, data);
    else if (hd < root->hd) root->left = insertMap(root->left, hd, data);
    else root->right = insertMap(root->right, hd, data);
    return root;
}

// Traverse the tree to populate the Map
void getVerticalOrder(struct Node* root, int hd, struct MapNode** mRoot) {
    if (root == NULL) return;

    // Use a simple Queue for Level Order to ensure top-to-bottom order
    struct Node* q[100];
    int hds[100];
    int head = 0, tail = 0;

    q[tail] = root;
    hds[tail++] = 0;

    while (head < tail) {
        struct Node* temp = q[head];
        int curr_hd = hds[head++];

        *mRoot = insertMap(*mRoot, curr_hd, temp->data);

        if (temp->left) {
            q[tail] = temp->left;
            hds[tail++] = curr_hd - 1;
        }
        if (temp->right) {
            q[tail] = temp->right;
            hds[tail++] = curr_hd + 1;
        }
    }
}

// Print the sorted Map (In-order traversal of the HD BST)
void printMap(struct MapNode* root) {
    if (root == NULL) return;
    printMap(root->left);
    struct List* temp = root->head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printMap(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) return 0;

    // Build tree from level-order array
    struct Node* treeNodes[n];
    for (int i = 0; i < n; i++) treeNodes[i] = newNode(arr[i]);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (treeNodes[i] != NULL) {
            int left = 2 * count + 1;
            int right = 2 * count + 2;
            if (left < n) treeNodes[i]->left = treeNodes[left];
            if (right < n) treeNodes[i]->right = treeNodes[right];
            count++;
        }
    }

    struct MapNode* mRoot = NULL;
    getVerticalOrder(treeNodes[0], 0, &mRoot);

    printf("Vertical Order Traversal: ");
    printMap(mRoot);
    printf("\n");

    return 0;
}
