//Implement a Min Heap using an array where the smallest element is always at the root.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }
void bubbleUp(int index) {
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
void bubbleDown(int index) {
    int smallest = index, left = 2 * index + 1, right = 2 * index + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != index) { swap(&heap[index], &heap[smallest]); bubbleDown(smallest); }
}
void insert(int x) {
    if (size >= MAX_SIZE) { printf("Heap Overflow!\n"); return; }
    heap[size] = x; bubbleUp(size); size++; printf("Inserted %d.\n", x);
}
void extractMin() {
    if (size <= 0) { printf("Heap Empty\n"); return; }
    printf("Extracted: %d\n", heap[0]);
    heap[0] = heap[--size]; bubbleDown(0);
}
void display() {
    for (int i = 0; i < size; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.Insert 2.Extract 3.Display 4.Exit\nEnter: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Val: "); scanf("%d", &val); insert(val); break;
            case 2: extractMin(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid\n");
        }
    }
}

