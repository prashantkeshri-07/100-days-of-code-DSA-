// Given an array of integers, count the number of subarrays whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting the prefix sums
int compare(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    
    // Step 1: Ask user for the number of elements
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 0;

    // Allocate memory for the array and prefix sums
    long long *arr = (long long *)malloc(n * sizeof(long long));
    long long *prefix_sums = (long long *)malloc((n + 1) * sizeof(long long));

    // Step 2: Ask user for the actual integers
    printf("Enter %d integers: ", n);
    prefix_sums[0] = 0; // Base case for subarrays starting from index 0
    long long current_sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        current_sum += arr[i];
        prefix_sums[i + 1] = current_sum;
    }

    // Step 3: Sort the prefix sums to find matches
    qsort(prefix_sums, n + 1, sizeof(long long), compare);

    long long total_count = 0;
    long long frequency = 1;

    for (int i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            frequency++;
        } else {
            // Formula: If a sum appears 'k' times, there are k*(k-1)/2 zero-sum subarrays
            total_count += (frequency * (frequency - 1)) / 2;
            frequency = 1;
        }
    }
    // Final count for the last set of identical sums
    total_count += (frequency * (frequency - 1)) / 2;

    printf("Total zero-sum subarrays: %lld\n", total_count);

    // Free allocated memory
    free(arr);
    free(prefix_sums);
    return 0;
}
