// Implement push and pop operations on a stack and verify stack operations.
#include <stdio.h>

int main() {
    int n, m;
    int stack[100]; // Array-based stack
    int top = -1;   // Tracks the top element

    // Input: Number of elements to push
    printf("Enter number of elements to push: ");
    if (scanf("%d", &n) != 1) return 1;

    // Input: The elements themselves
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        // Push operation
        stack[++top] = val;
    }

    // Input: Number of pops
    printf("Enter number of pops: ");
    if (scanf("%d", &m) != 1) return 1;

    // Pop operation
    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }

    // Output: Remaining elements from top to bottom
    printf("Remaining stack (top to bottom): ");
    if (top == -1) {
        printf("Stack is empty");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");

    return 0;
}
