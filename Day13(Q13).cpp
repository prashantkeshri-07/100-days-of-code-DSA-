//You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.
#include <stdio.h>
#include <stdlib.h>

void spiralTraversal(int r, int c, int **matrix) {
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    printf("\nSpiral Order Output:\n");
    while (top <= bottom && left <= right) {
        // 1. Move Right
        for (int i = left; i <= right; ++i) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // 2. Move Down
        for (int i = top; i <= bottom; ++i) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // 3. Move Left
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // 4. Move Up
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
    printf("\n");
}

int main() {
    int r, c;
    
    // Asking for dimensions
    printf("Enter number of rows and columns (e.g., 3 3): ");
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    // Allocate memory for the matrix
    int **matrix = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int *)malloc(c * sizeof(int));
    }

    // Asking for matrix elements
    printf("Enter the elements of the %dx%d matrix:\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // Using a prompt for each row or just reading them all
            scanf("%d", &matrix[i][j]);
        }
    }

    // Call the traversal function
    spiralTraversal(r, c, matrix);

    // Free the allocated memory
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
