//Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate the linked list
struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || n <= 1) return head;

    // Handle k greater than n
    k = k % n;
    if (k == 0) return head;

    // 1. Find the current tail and connect it to the head
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head; // The list is now circular

    // 2. Find the new tail (n - k steps from head)
    struct Node* newTail = head;
    for (int i = 0; i < (n - k - 1); i++) {
        newTail = newTail->next;
    }

    // 3. Set the new head and break the link
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n, k, val;
    struct Node *head = NULL, *temp = NULL;

    printf("Enter the number of elements (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid list size.\n");
        return 0;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter rotation value (k): ");
    scanf("%d", &k);

    // Perform rotation
    head = rotateRight(head, k, n);

    // Print result
    printf("Rotated List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        struct Node* toDelete = temp; // Keep track for memory cleanup
        temp = temp->next;
        free(toDelete); // Freeing memory as we go
    }
    printf("\n");

    return 0;
}
