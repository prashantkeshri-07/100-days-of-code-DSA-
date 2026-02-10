//Read a string and check if it is a palindrome using two-pointer comparison.
#include <stdio.h>
#include <string.h>

int main() {
    // 1. Declare a buffer with a fixed size (e.g., 100 characters)
    char s[100]; 
    int left, right;
    int isPalindrome = 1; 

    // 2. Read string input
    // The space before %s helps clear any previous white space in the buffer
    printf(" Input: ");
    if (scanf("%99s", s) != 1) return 0; 

    // 3. Initialize two pointers
    left = 0;
    right = strlen(s) - 1;

    // 4. Two-pointer comparison
    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break; 
        }
        left++;
        right--;
    }

    // 5. Output result
    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    // Optional: Keeps the console window open in some IDEs
    // printf("\nPress Enter to exit...");
    // getchar(); getchar(); 

    return 0;
}
