//Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#include <stdlib.h>

// Define Stack structure
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack helper functions
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

int main() {
    int n, i;

    printf("Enter the number of integers in the queue: ");
    if (scanf("%d", &n) != 1) return 1;

    // We'll use an array to represent the Queue and a Stack for reversal
    int queue[n];
    struct Stack* stack = createStack(n);

    printf("Enter %d space-separated integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Step 1: De-queue all elements and push them onto the Stack
    for (i = 0; i < n; i++) {
        push(stack, queue[i]);
    }

    // Step 2: Pop from Stack and En-queue back (reversing the order)
    for (i = 0; i < n; i++) {
        queue[i] = pop(stack);
    }

    printf("Reversed queue: ");
    for (i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    // Free memory
    free(stack->array);
    free(stack);

    return 0;
}
