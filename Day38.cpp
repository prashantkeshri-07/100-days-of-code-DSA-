// Deque (Double-Ended Queue)

//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

typedef struct {
    Node *front, *rear;
    int size;
} Deque;

// Initialize Deque
void init(Deque *dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

// O(1) Push Front
void push_front(Deque *dq, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = dq->front;
    newNode->prev = NULL;
    if (!dq->front) dq->rear = newNode;
    else dq->front->prev = newNode;
    dq->front = newNode;
    dq->size++;
}

// O(1) Push Back
void push_back(Deque *dq, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = dq->rear;
    newNode->next = NULL;
    if (!dq->rear) dq->front = newNode;
    else dq->rear->next = newNode;
    dq->rear = newNode;
    dq->size++;
}

// O(1) Pop Front
void pop_front(Deque *dq) {
    if (!dq->front) return;
    Node *temp = dq->front;
    dq->front = dq->front->next;
    if (!dq->front) dq->rear = NULL;
    else dq->front->prev = NULL;
    free(temp);
    dq->size--;
}

// O(1) Pop Back
void pop_back(Deque *dq) {
    if (!dq->rear) return;
    Node *temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (!dq->rear) dq->front = NULL;
    else dq->rear->next = NULL;
    free(temp);
    dq->size--;
}

void display(Deque *dq) {
    Node *curr = dq->front;
    printf("Deque: [ ");
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("]\n");
}

int main() {
    Deque dq;
    init(&dq);
    int choice, val;

    printf("--- Deque Interactive Console ---\n");
    while (1) {
        printf("\n1.Push Front  2.Push Back  3.Pop Front  4.Pop Back  5.Size  6.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: printf("Val: "); scanf("%d", &val); push_front(&dq, val); break;
            case 2: printf("Val: "); scanf("%d", &val); push_back(&dq, val); break;
            case 3: pop_front(&dq); break;
            case 4: pop_back(&dq); break;
            case 5: printf("Size: %d\n", dq.size); break;
            case 6: exit(0);
            default: printf("Invalid!\n");
        }
        display(&dq);
    }
    return 0;
}
