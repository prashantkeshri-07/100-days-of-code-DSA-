//Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to create a circular list with n nodes
void createList(int n) {
    if (n <= 0) return;
    struct Node *newNode, *temp;
    int data, i;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Link back to head
        }
    }
    printf("\nCircular list created successfully!\n");
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("\nCircular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, n;
    while (1) {
        printf("\n--- MENU ---");
        printf("\n1. Create List\n2. Display List\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
