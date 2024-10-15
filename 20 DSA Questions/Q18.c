#include <stdio.h>
#include <stdlib.h>
// Structure to represent a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Structure to represent a queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}
// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}
// Function to enqueue an element into the queue
void enqueue(Queue* q, int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}
// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }
    Node* temp = q->front;
    int element = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; // If the queue is now empty, set rear to NULL
    }
    free(temp);
    return element;
}
// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = q->front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
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
