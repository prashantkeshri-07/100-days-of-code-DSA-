//Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    // If the Linked List is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse until the last node
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to delete the first occurrence of a key
void deleteFirstOccurrence(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;

    // Case 1: If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Change head
        free(temp);             // Free old head memory
        return;
    }

    // Case 2: Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Case 3: If key was not present in linked list
    if (temp == NULL) {
        printf("\nKey %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Enter the key to delete: ");
    scanf("%d", &key);

    deleteFirstOccurrence(&head, key);

    printf("Resulting list: ");
    printList(head);

    return 0;
}
