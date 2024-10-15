#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
// Structure to represent a stack
typedef struct Stack {
  char data[MAX_SIZE];
  int top;
} Stack;
// Function to create a new stack
Stack* createStack() {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->top = -1;
  return stack;
}
// Function to push an element onto the stack
void push(Stack* stack, char element) {
  if (stack->top == MAX_SIZE - 1) {
    printf("Stack overflow\n");
    return;
  }
  stack->data[++stack->top] = element;
}
// Function to pop an element from the stack
char pop(Stack* stack) {
  if (stack->top == -1) {
    printf("Stack underflow\n");
    return -1;
  }
  return stack->data[stack->top--];
}
// Function to check if the stack is empty
int isEmpty(Stack* stack) {
  return stack->top == -1;
}
// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
  Stack* stack = createStack();
  int i = 0, j = 0;
  while (infix[i] != '\0') {
    if (infix[i] == ' ') {
      i++;
      continue;
    }
    if (infix[i] == '(') {
      push(stack, infix[i]);
    } else if (infix[i] == ')') {
      while (!isEmpty(stack) && stack->data[stack->top] != '(') {
        postfix[j++] = pop(stack);
      }
      if (!isEmpty(stack) && stack->data[stack->top] == '(') {
        pop(stack);
      }
    } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
      while (!isEmpty(stack) && stack->data[stack->top] != '(' && precedence(infix[i]) <= precedence(stack->data[stack->top])) {
        postfix[j++] = pop(stack);
      }
      push(stack, infix[i]);
    } else {
      postfix[j++] = infix[i];
    }
    i++;
  }
  while (!isEmpty(stack)) {
    postfix[j++] = pop(stack);
  }
  postfix[j] = '\0';
}
// Function to get the precedence of an operator
int precedence(char operator) {
  if (operator == '+' || operator == '-') {
    return 1;
  } else if (operator == '*' || operator == '/') {
    return 2;
  } else {
    return 0;
  }
}
int main() {
  char infix[100], postfix[100];
  printf("Enter an infix expression: ");
  scanf("%s", infix);
  infixToPostfix(infix, postfix);
  printf("Postfix expression: %s\n", postfix);
  return 0;
}
