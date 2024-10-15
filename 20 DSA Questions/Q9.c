#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXSTACK 100    // Maximum size of the stack
// Stack structure
typedef struct {
    int top;
    int items[MAXSTACK];
} Stack;
// Function to create a stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}
// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
// Function to push an item onto the stack
void push(Stack* stack, int item) {
    if (stack->top < MAXSTACK - 1) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}
// Function to pop an item from the stack
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}
// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    Stack* stack = createStack();
    for (int i = 0; expression[i]; i++) {
        // If the character is a digit, push it onto the stack
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0'); // Convert char to int
        } 
        // If the character is an operator, pop two elements and apply the operator
        else if (strchr("+-*/", expression[i])) {
            int val2 = pop(stack);
            int val1 = pop(stack);
            switch (expression[i]) {
                case '+':
                    push(stack, val1 + val2);
                    break;
                case '-':
                    push(stack, val1 - val2);
                    break;
                case '*':
                    push(stack, val1 * val2);
                    break;
                case '/':
                    push(stack, val1 / val2);
                    break;
            }
        }
    }
    // The result will be the only element left in the stack
    return pop(stack);
}
// Main function
int main() {
    char expression[MAXSTACK];
    printf("Enter a postfix expression: ");
    scanf("%s", expression); // Read the postfix expression
    int result = evaluatePostfix(expression); // Evaluate the expression
    printf("The result of the postfix expression %s is: %d\n", expression, result);
    return 0;
}
