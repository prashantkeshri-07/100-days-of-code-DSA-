//Problem: Create and Traverse Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Ask user for the number of elements
    printf("Enter the number of elements (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input or empty list.\n");
        return 0;
    }

    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        // Allocate memory for a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!");
            return 1;
        }

        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            // If it's the first node, set it as head
            head = newNode;
            temp = head;
        } else {
            // Link the previous node to the new node
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Traversal and Printing
    printf("\nLinked List Output: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Freeing memory (Good practice)
    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
