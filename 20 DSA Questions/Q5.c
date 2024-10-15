#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the doubly linked list
typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} Node;
// Function to create a new node with given data
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}
// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(Node** head, int data) {
  Node* newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
  } else {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  }
}
// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(Node** head, int data) {
  Node* newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
  } else {
    Node* current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
  }
}
// Function to delete a node with given data from the doubly linked list
void deleteNode(Node** head, int data) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }

  Node* current = *head;
  while (current != NULL) {
    if (current->data == data) {
      if (current->prev == NULL) {
        // Node to be deleted is the head node
        *head = current->next;
        if (*head != NULL) {
          (*head)->prev = NULL;
        }
      } else {
        current->prev->next = current->next;
        if (current->next != NULL) {
          current->next->prev = current->prev;
        }
      }
      free(current);
      return;
    }
    current = current->next;
  }
}
// Function to traverse and print the doubly linked list in forward direction
void traverseForward(Node* head) {
  Node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}
// Function to traverse and print the doubly linked list in backward direction
void traverseBackward(Node* head) {
  Node* current = head;
  if (current == NULL) {
    return;
  }
  while (current->next != NULL) {
    current = current->next;
  }
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->prev;
  }
  printf("\n");
}
int main() {
  Node* head = NULL;
  // Insert nodes
  insertAtBeginning(&head, 10);
  insertAtEnd(&head, 20);
  insertAtEnd(&head, 30);
  insertAtEnd(&head, 40);
  insertAtEnd(&head, 50);
  printf("Doubly Linked List (Forward): ");
  traverseForward(head);
  printf("Doubly Linked List (Backward): ");
  traverseBackward(head);
  // Delete a node
  deleteNode(&head, 30);
  printf("Doubly Linked List after deletion (Forward): ");
  traverseForward(head);
  printf("Doubly Linked List after deletion (Backward): ");
  traverseBackward(head);
  return 0;
}
