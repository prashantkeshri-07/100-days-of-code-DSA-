//A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.
#include <stdio.h>

// Function to merge two sorted logs into a single chronological log
void mergeLogs(int logA[], int sizeA, int logB[], int sizeB, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Compare elements from both logs and pick the smaller one
    while (i < sizeA && j < sizeB) {
        if (logA[i] <= logB[j]) {
            merged[k++] = logA[i++];
        } else {
            merged[k++] = logB[j++];
        }
    }

    // Append remaining elements from logA (if any)
    while (i < sizeA) {
        merged[k++] = logA[i++];
    }

    // Append remaining elements from logB (if any)
    while (j < sizeB) {
        merged[k++] = logB[j++];
    }
}

int main() {
    int n1, n2;

    // Get input for the first server log
    printf("Enter number of entries for Server A: ");
    scanf("%d", &n1);
    int logA[n1];
    printf("Enter %d arrival times (sorted): ", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &logA[i]);
    }

    // Get input for the second server log
    printf("Enter number of entries for Server B: ");
    scanf("%d", &n2);
    int logB[n2];
    printf("Enter %d arrival times (sorted): ", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &logB[i]);
    }

    // Prepare the merged log array
    int mergedLog[n1 + n2];

    // Merge the logs
    mergeLogs(logA, n1, logB, n2, mergedLog);

    // Display the results
    printf("\nMerged Chronological Log:\n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", mergedLog[i]);
    }
    printf("\n");

    return 0;
}
