//Given an array of integers, rotate the array to the right by k positions.
#include <stdio.h>

// Function to reverse a specific portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;

    // 1. Get the size of the array
    printf("Enter the number of elements (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];

    // 2. Get the array elements
    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Get the rotation count
    printf("Enter the number of positions to rotate (k): ");
    if (scanf("%d", &k) != 1) {
        printf("Invalid input for k.\n");
        return 1;
    }

    // Handle k larger than n and negative k
    k = k % n;
    if (k < 0) k = k + n; // Converts left rotation to equivalent right rotation

    if (k != 0) {
        // 4. Perform the Three-Step Reverse
        // Reverse first (n-k) elements: [0...n-k-1]
        reverse(arr, 0, n - k - 1);
        
        // Reverse last k elements: [n-k...n-1]
        reverse(arr, n - k, n - 1);
        
        // Reverse the whole array: [0...n-1]
        reverse(arr, 0, n - 1);
    }

    // 5. Output the result
    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
