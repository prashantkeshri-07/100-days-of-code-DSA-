//Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to count occurrences of a key in the list
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int main() {
    int n, value, key;
    struct Node *head = NULL, *tail = NULL, *temp = NULL;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) return 0;

    // Building the linked list interactively
    if (n > 0) {
        printf("Enter %d integers separated by spaces: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            
            // Dynamically allocate memory for a new node using malloc
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            if (newNode == NULL) {
                printf("Memory allocation failed!\n");
                return 1;
            }
            newNode->data = value;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    printf("Enter the key (element to be counted): ");
    scanf("%d", &key);

    // Output the result
    int result = countOccurrences(head, key);
    printf("Output: %d\n", result);

    // Freeing dynamically allocated memory to avoid leaks
    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
