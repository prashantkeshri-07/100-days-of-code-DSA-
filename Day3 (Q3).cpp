//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

int main() {
    int n, k, i, found_at = -1, comparisons = 0;

    printf("Enter array size: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found_at = i;
            break;
        }
    }

    if (found_at != -1) {
        printf("Found at index %d\n", found_at);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
