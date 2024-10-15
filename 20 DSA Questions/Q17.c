#include <stdio.h>
#define MAX_SIZE 5
// Structure to represent a queue
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}
// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->count == 0;
}
// Function to check if the queue is full
int isFull(Queue* q) {
    return q->count == MAX_SIZE;
}
// Function to enqueue an element into the queue
void enqueue(Queue* q, int element) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue element %d.\n", element);
        return;
    }
    q->arr[q->rear] = element;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->count++;
}
// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int element = q->arr[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    return element;
}
// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->arr[(q->front + i) % MAX_SIZE]);
    }
    printf("\n");
}
int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);
    int dequeuedElement = dequeue(&q);
    printf("Dequeued element: %d\n", dequeuedElement);
    displayQueue(&q);
    return 0;
}
