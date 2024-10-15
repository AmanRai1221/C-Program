#include <stdio.h>
#define MAX_SIZE 5
// Structure to represent a stack
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;
// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}
// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}
// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}
// Function to push an element onto the stack
void push(Stack* s, int element) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push element %d.\n", element);
        return;
    }
    s->arr[++s->top] = element;
}
// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }
    return s->arr[s->top--];
}
// Function to display the stack
void displayStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int main() {
    Stack s;
    initStack(&s);
    push(&s, 40);
    push(&s, 60);
    push(&s, 80);
    displayStack(&s);
    int poppedElement = pop(&s);
    printf("Popped element: %d\n", poppedElement);
    displayStack(&s);
    return 0;
}
