//Check whether a given binary tree satisfies the Min-Heap property.
#include <stdio.h>
#include <stdbool.h>

/**
 * Checks if a binary tree satisfies the Min-Heap property.
 * In a Min-Heap, every parent node must be smaller than or equal to its children.
 */
int main() {
    int n;
    
    // Step 1: Get the number of nodes from the user
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int arr[n];
    
    // Step 2: Input the level-order traversal
    printf("Enter %d level-order traversal values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bool isMinHeap = true;

    // Step 3: Iterate through all internal nodes (parents)
    // The last parent node in a zero-indexed array is at (n-2)/2
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // Check if current parent is greater than its left child
        if (leftChild < n && arr[i] > arr[leftChild]) {
            isMinHeap = false;
            break;
        }

        // Check if current parent is greater than its right child
        if (rightChild < n && arr[i] > arr[rightChild]) {
            isMinHeap = false;
            break;
        }
    }

    // Step 4: Final Output
    if (isMinHeap) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
