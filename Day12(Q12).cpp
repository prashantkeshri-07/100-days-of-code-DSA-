//Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n;

    // Prompt for dimensions
    printf("Enter the number of rows and columns (e.g., 3 3): ");
    if (scanf("%d %d", &m, &n) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    // A symmetric matrix must be square
    if (m != n) {
        printf("Since rows (%d) != columns (%d), it is Not a Symmetric Matrix.\n", m, n);
        return 0;
    }

    int matrix[m][n];
    bool isSymmetric = true;

    // Prompt for matrix elements
    printf("Enter the elements of the %dx%d matrix:\n", m, n);
    for (int i = 0; i < m; i++) {
        printf("Row %d: ", i + 1); // Helper to show which row user is typing
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Logic to check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    // Final Output
    printf("\n--- Result ---\n");
    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}
