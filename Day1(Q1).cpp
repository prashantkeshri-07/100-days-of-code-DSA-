//Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
#include <stdio.h>

int main() {
    int arr[100]; // Fixed capacity array
    int n, i, x, pos;

    // 1. Get current number of elements
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    // 2. Input array elements
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Get element to insert and 1-based position
    printf("Enter element to insert: ");
    scanf("%d", &x);
    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);

    // Check for valid position
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Please enter a value between 1 and %d.\n", n + 1);
    } else {
        // 4. Shift elements to the right
        // Start from the end (n) back to the target index (pos-1)
        for (i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }

        // 5. Insert element at the 0-based index (pos-1)
        arr[pos - 1] = x;

        // 6. Update size and print
        n++;
        printf("Updated array: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
