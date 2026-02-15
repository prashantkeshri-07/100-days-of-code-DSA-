//Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;

    printf("Enter the number of rows/columns (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Declare a 2D array of size n x n
    int matrix[n][n];
    bool is_identity = true;

    printf("Enter the %d x %d matrix elements:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Prompting for each specific position (optional but helpful)
            scanf("%d", &matrix[i][j]);
        }
    }

    // Logic to check if it's an Identity Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                // Check diagonal
                if (matrix[i][j] != 1) {
                    is_identity = false;
                    break; 
                }
            } else {
                // Check off-diagonal
                if (matrix[i][j] != 0) {
                    is_identity = false;
                    break;
                }
            }
        }
        if (!is_identity) break; // Exit outer loop if a mismatch is found
    }

    // Final Output
    printf("\nResult: ");
    if (is_identity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}
