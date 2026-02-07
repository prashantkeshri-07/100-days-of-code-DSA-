//Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.
#include <stdio.h>

// Recursive function to find the n-th Fibonacci number
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    // A prompt makes it clear the program is waiting for you
    printf("Enter a number: ");
    
    // Ensure you use '&n' to provide the memory address to scanf
    if (scanf("%d", &n) == 1) {
        printf("Result: %d\n", fib(n));
    } else {
        printf("Invalid input. Please enter an integer.\n");
    }

    return 0;
}

