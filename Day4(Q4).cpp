// Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>

void reverseArray(int *arr, int n) {
    int *left = arr;
    int *right = arr + n - 1;
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int main() {
    int n;
    printf("Enter number of elements: "); // Prompt for size
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];
    printf("Enter %d integers: ", n); // Prompt for elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, n);

    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
