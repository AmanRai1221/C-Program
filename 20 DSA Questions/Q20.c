#include <stdio.h>
#include <stdlib.h>
// Structure to represent a stack node
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Structure to represent a stack
typedef struct Stack {
    Node* top;
} Stack;
// Function to initialize the stack
void initStack(Stack* s) {
    s->top = NULL;
}
// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* s, int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = s->top;
    s->top = newNode;
}
// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }
    Node* temp = s->top;
    int element = temp->data;
    s->top = s->top->next;
    free(temp);
    return element;
}
// Function to display the stack
void displayStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* current = s->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    Stack s;
    initStack(&s);
    push(&s, 15);
    push(&s, 30);
    push(&s, 50);
    displayStack(&s);
    int poppedElement = pop(&s);
    printf("Popped element: %d\n", poppedElement);
    displayStack(&s);
    return 0;
}
