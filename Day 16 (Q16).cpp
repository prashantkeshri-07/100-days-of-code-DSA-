//Given an array of integers, count the frequency of each distinct element and print the result.
#include <stdio.h>

int main() {
    int n;

    // Prompt user for the size of the array
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    int visited[n]; // Array to keep track of elements we've already counted

    // Prompt user for the integers
    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize visited array to 0
    }

    printf("\nFrequency Results:\n");

    // Logic to count frequency and maintain original order
    for (int i = 0; i < n; i++) {
        // If this element has already been processed, skip it
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        // Look ahead in the array for matches
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1; // Mark as visited so we don't count it again
                count++;
            }
        }

        // Print the result for this specific element
        printf("%d:%d\n", arr[i], count);
    }

    return 0;
}
