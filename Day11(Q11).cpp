// Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.
#include <stdio.h>
#include <stdlib.h> // Required for system("pause")

int main() {
    int m, n, i, j;

    // 1. Get Matrix Dimensions
    printf("Enter number of rows and columns (e.g. 3 3): ");
    if (scanf("%d %d", &m, &n) != 2) {
        return 1;
    }

    int a[m][n], b[m][n], sum[m][n];

    // 2. Input for First Matrix
    printf("\nEnter elements of the FIRST matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // 3. Input for Second Matrix
    printf("\nEnter elements of the SECOND matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    // 4. Addition and Output
    printf("\n--- Resultant Matrix ---\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    // 5. Keep window open in Dev-C++
    printf("\nExecution finished.\n");
    system("pause"); 

    return 0;
}

