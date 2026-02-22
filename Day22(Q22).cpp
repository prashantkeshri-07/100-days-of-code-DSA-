//Count Nodes in Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL, *newNode = NULL;

    // 1. Ask for the number of nodes
    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n <= 0) {
        printf("The list is empty.\n");
        return 0;
    }

    // 2. Build the Linked List
    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) break;
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 3. Display the result
    printf("\nLinked List Output: ");
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    
    printf("\nTotal nodes counted: %d\n", count);

    // 4. Free Memory (Cleanup)
    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
