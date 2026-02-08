//Given integers a and b, compute a^b using recursion without using pow() function.
#include <stdio.h>

long long power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    printf("Enter two numbers (e.g., 2 5): "); // Adding a prompt
    
    // scanf returns the number of successfully read items
    if (scanf("%d %d", &a, &b) == 2) {
        printf("Result: %lld\n", power(a, b));
    } else {
        printf("Error: Please enter two valid integers.\n");
    }

    return 0;
}
