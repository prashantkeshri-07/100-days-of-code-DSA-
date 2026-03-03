//Implement a stack data structure using an array with the following operations: push, pop, and display.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum capacity of the stack

int stack[MAX];
int top = -1;

// Function to add an element to the stack
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Function to remove and return the top element
void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

// Function to display the stack from top to bottom
void display() {
    if (top < 0) {
        return; // Stack is empty, nothing to display
    }
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0 ? "" : " "));
    }
    printf("\n");
}

int main() {
    int n, choice, value;

    printf("Enter the number of operations: ");
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        printf("\nOperation (1:Push, 2:Pop, 3:Display): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
                i--; // Don't count invalid operations toward n
        }
    }

    return 0;
}
