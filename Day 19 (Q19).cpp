// Given an array of integers, find two elements whose sum is closest to zero.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    // Ask for the number of elements
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Please enter at least 2 integers.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array: Time Complexity O(n log n)
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int min_sum = INT_MAX;
    int res_l = left, res_r = right;

    // Two-pointer approach: Time Complexity O(n)
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Check if current sum is closer to zero than the previous minimum
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            res_l = left;
            res_r = right;
        }

        // Move pointers to get closer to zero
        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            // If sum is 0, it's the absolute closest to zero
            break;
        }
    }

    printf("The pair whose sum is closest to zero is: %d and %d\n", arr[res_l], arr[res_r]);

    return 0;
}
