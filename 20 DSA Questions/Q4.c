#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the circular linked list
typedef struct Node {
  int data;
  struct Node* next;
} Node;
// Function to create a new node with given data
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
// Function to insert a new node at the end of the circular linked list
void insertNode(Node** head, int data) {
  Node* newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
    newNode->next = newNode; // circular link
  } else {
    Node* current = *head;
    while (current->next != *head) {
      current = current->next;
    }
    current->next = newNode;
    newNode->next = *head; // circular link
  }
}
// Function to delete a node with given data from the circular linked list
void deleteNode(Node** head, int data) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node* current = *head;
  Node* previous = NULL;
  while (current->next != *head) {
    if (current->data == data) {
      if (previous == NULL) {
        // Node to be deleted is the head node
        Node* temp = *head;
        while (temp->next != *head) {
          temp = temp->next;
        }
        *head = current->next;
        temp->next = *head; // update circular link
      } else {
        previous->next = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
  // Node to be deleted is the last node
  if (current->data == data) {
    if (previous == NULL) {
      // List has only one node
      free(*head);
      *head = NULL;
    } else {
      previous->next = current->next;
      free(current);
    }
  }
}
// Function to traverse and print the circular linked list
void traverseList(Node* head) {
  Node* current = head;
  do {
    printf("%d ", current->data);
    current = current->next;
  } while (current != head);
  printf("\n");
}
int main() {
  Node* head = NULL;
  // Insert nodes
  insertNode(&head, 10);
  insertNode(&head, 20);
  insertNode(&head, 30);
  insertNode(&head, 40);
  insertNode(&head, 50);
  printf("Circular Linked List: ");
  traverseList(head);
  // Delete a node
  deleteNode(&head, 30);
  printf("Circular Linked List after deletion: ");
  traverseList(head);
  return 0;
}
