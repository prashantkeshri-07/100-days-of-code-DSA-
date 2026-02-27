//Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to calculate the length of the list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find the intersection based on values
void findIntersection(struct Node* head1, struct Node* head2) {
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Advance the pointer of the longer list
    int diff = abs(l1 - l2);
    if (l1 > l2) {
        for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++) ptr2 = ptr2->next;
    }

    // Move both pointers until the values match
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("\nIntersection Point Value: %d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("\nNo Intersection\n");
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL, *temp = NULL;
    int n, m, val;

    // Input for List 1
    printf("Enter number of elements for First List (n): ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head1 == NULL) {
            head1 = newNode;
            temp = head1;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Input for List 2
    printf("Enter number of elements for Second List (m): ");
    scanf("%d", &m);
    printf("Enter %d elements: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head2 == NULL) {
            head2 = newNode;
            temp = head2;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Process Intersection
    findIntersection(head1, head2);

    return 0;
}
