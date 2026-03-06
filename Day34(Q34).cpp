//Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for the stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Push: Allocate memory for a new node
void push(Node** top, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop: Return data and free the memory
int pop(Node** top) {
    if (*top == NULL) {
        printf("Error: Stack Underflow (Invalid Expression)\n");
        exit(1);
    }
    Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == ' ' || exp[i] == '\n') continue;

        // Handle multi-digit numbers
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--; // Step back to compensate for the outer loop increment
            push(&stack, num);
        } 
        // Handle operators
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int val1 = pop(&stack); // Second operand
            int val2 = pop(&stack); // First operand
            
            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
            }
        }
    }
    
    int result = pop(&stack);
    
    // Check if the stack is empty (valid expression)
    if (stack != NULL) {
        printf("Error: Invalid expression (Too many operands)\n");
        exit(1);
    }
    
    return result;
}

int main() {
    char expression[100];

    printf("--- Postfix Evaluator ---\n");
    printf("Enter a postfix expression (e.g., 2 3 1 * + 9 -):\n");
    
    if (fgets(expression, sizeof(expression), stdin)) {
        int result = evaluatePostfix(expression);
        printf("Output: %d\n", result);
    }

    return 0;
}
