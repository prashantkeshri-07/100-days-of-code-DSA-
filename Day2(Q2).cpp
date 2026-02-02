// Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.
#include <stdio.h>

int main() {
    int n, pos, i;

    printf("Enter size: ");
    if (scanf("%d", &n) != 1) return 1; // Exit if input isn't a number

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    printf("Enter position to delete: ");
    if (scanf("%d", &pos) != 1) return 1;

    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
    } else {
        // Correct shifting loop
        for (i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; // Reduce logical size

        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}



