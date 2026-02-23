// Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Linked List node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node using dynamic memory
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Interactive function to build a list
struct Node* buildList() {
    int n, val;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return NULL;

    printf("Enter %d space-separated integers (sorted): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to merge two sorted lists in-place
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy; // Dummy node to simplify head management
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    // Attach remaining elements
    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    printf("--- List 1 ---\n");
    struct Node* list1 = buildList();

    printf("\n--- List 2 ---\n");
    struct Node* list2 = buildList();

    struct Node* mergedHead = mergeLists(list1, list2);

    printf("\nMerged Linked List: ");
    printList(mergedHead);

    return 0;
}
