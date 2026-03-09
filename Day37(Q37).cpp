//Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        } else break;
    }
}

void bubbleDown(int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

void insert(int x) {
    if (size < MAX_SIZE) {
        heap[size] = x;
        bubbleUp(size);
        size++;
    }
}

int deleteMin() {
    if (size == 0) return -1;
    int root = heap[0];
    heap[0] = heap[size - 1]; // Move last element to root
    size--;
    bubbleDown(0);
    return root;
}

int peek() {
    return (size == 0) ? -1 : heap[0];
}

int main() {
    int n, value;
    char op[20];

    printf("Enter number of operations: ");
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        printf("Enter operation (insert [val], delete, peek): ");
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}

