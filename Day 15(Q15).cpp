//Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
#include <stdio.h>

int main() {
    int m, n;

    // Ask user for dimensions
    printf("Enter number of rows (m) and columns (n): ");
    if (scanf("%d %d", &m, &n) != 2) {
        printf("Invalid input dimensions.\n");
        return 1;
    }

    int matrix[m][n];
    int sum = 0;

    // Ask user for matrix elements
    printf("Enter the elements of the %d x %d matrix:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Prompting for each specific position (optional)
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the primary diagonal sum
    // A primary diagonal exists where row index == column index
    // We only go up to the smaller of m or n
    int limit = (m < n) ? m : n; 
    
    for (int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    // Output the result
    printf("\nThe sum of the primary diagonal elements is: %d\n", sum);

    return 0;
}
