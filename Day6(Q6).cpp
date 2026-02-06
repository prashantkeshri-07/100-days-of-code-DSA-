//Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
#include <stdio.h>

int main() {
    int n;

    // Prompt for the number of elements
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int arr[n];

    // Prompt for the array elements
    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; i++) {
        // ALWAYS use &arr[i] to ensure input is captured
        scanf("%d", &arr[i]);
    }

    // Two-pointer logic
    int write_index = 0;
    for (int read_index = 1; read_index < n; read_index++) {
        if (arr[read_index] != arr[write_index]) {
            write_index++;
            arr[write_index] = arr[read_index];
        }
    }

    // Output only unique elements
    printf("Unique elements: ");
    for (int k = 0; k <= write_index; k++) {
        printf("%d%s", arr[k], (k == write_index ? "" : " "));
    }
    printf("\n");

    return 0;
}


