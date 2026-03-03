//Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure for a Polynomial Term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term at the end of the list
void insertTerm(struct Node** head, int c, int e) {
    struct Node* newNode = createNode(c, e);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the polynomial
void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("\nResulting Polynomial: ");
    while (temp != NULL) {
        // Format: Coeff and X
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        // Add the '+' sign for next terms
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Main Interactive Program
int main() {
    struct Node* poly = NULL;
    int n, c, e;

    printf("--- Polynomial Linked List Creator ---\n");
    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nTerm #%d:\n", i + 1);
        printf("  Enter coefficient: ");
        scanf("%d", &c);
        printf("  Enter exponent: ");
        scanf("%d", &e);
        
        insertTerm(&poly, c, e);
    }

    displayPolynomial(poly);

    // Freeing memory before exit
    struct Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }

    printf("\nMemory cleared. Goodbye!\n");
    return 0;
}
