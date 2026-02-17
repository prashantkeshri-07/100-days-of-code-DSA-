//Write a program to find the maximum and minimum values present in a given array of integers.#include <stdio.h>
#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    // Check if input is a valid integer and greater than 0
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Please enter a valid positive integer.\n");
        return 1;
    }

    int arr[n]; // Ensure your compiler supports C99 or later

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Error: Invalid input at element %d.\n", i + 1);
            return 1;
        }
    }

    // IMPORTANT: Initialize max and min AFTER the array has been filled
    int max = arr[0]; 
    int min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("\nMax: %d", max);
    printf("\nMin: %d\n", min);

    return 0;
}

