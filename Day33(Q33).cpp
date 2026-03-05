// Convert an infix expression to postfix notation using stack.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// --- Stack Utility Functions ---
void push(char x) {
    if (top < MAX - 1) stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// --- Precedence Logic ---
int precedence(char x) {
    if (x == '(') return 0; // Lowest inside stack to stay until ')'
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return -1;
}

int main() {
    char infix[MAX];
    printf("Enter Infix Expression: ");
    
    // fgets is safer than scanf; it handles spaces and limits input size
    if (fgets(infix, MAX, stdin) == NULL) return 1;

    printf("Postfix Result: ");
    
    for (int i = 0; infix[i] != '\0' && infix[i] != '\n'; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            printf("%c", token); // Print operands directly
        } 
        else if (token == '(') {
            push(token);
        } 
        else if (token == ')') {
            // Pop until '(' is found
            while (top != -1 && peek() != '(') {
                printf("%c", pop());
            }
            pop(); // Remove '(' from stack
        } 
        else if (isspace(token)) {
            continue; // Skip spaces
        }
        else {
            // While stack top has >= precedence, pop it
            while (top != -1 && precedence(peek()) >= precedence(token)) {
                printf("%c", pop());
            }
            push(token);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}


