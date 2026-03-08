//Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Global pointer to the rear of the circular queue
struct Node* rear = NULL;

// Function to add an element (Enqueue)
void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    
    if (rear == NULL) {
        rear = newNode;
        rear->next = rear; // Points to itself to maintain circularity
    } else {
        newNode->next = rear->next; // New node points to front
        rear->next = newNode;      // Old rear points to new node
        rear = newNode;            // Update rear to new node
    }
}

// Function to perform rotation (as per your example: front moves to back)
void rotate() {
    if (rear != NULL) {
        rear = rear->next; // The front node effectively becomes the new rear
    }
}

// Function to print the queue starting from the front
void display() {
    if (rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = rear->next; // Start at front
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
    printf("\n");
}

int main() {
    int n, m, val;

    printf("Enter number of elements to enqueue: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    printf("Enter number of operations to perform: ");
    scanf("%d", &m);

    // Performing rotations to match the example logic
    for (int i = 0; i < m; i++) {
        rotate();
    }

    printf("Resulting Queue: ");
    display();

    return 0;
}
