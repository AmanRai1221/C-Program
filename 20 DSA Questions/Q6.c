#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the singly linked list
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
// Function to insert a new node at the beginning of the singly linked list
void insertAtBeginning(Node** head, int data) {
  Node* newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
  } else {
    newNode->next = *head;
    *head = newNode;
  }
}

// Function to insert a new node at the end of the singly linked list
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
  }
}
// Function to delete a node with given data from the singly linked list
void deleteNode(Node** head, int data) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  if ((*head)->data == data) {
    // Node to be deleted is the head node
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
  }
  Node* current = *head;
  while (current->next != NULL) {
    if (current->next->data == data) {
      Node* temp = current->next;
      current->next = current->next->next;
      free(temp);
      return;
    }
    current = current->next;
  }
}
// Function to traverse and print the singly linked list
void traverseList(Node* head) {
  Node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
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
  printf("Singly Linked List: ");
  traverseList(head);
  // Delete a node
  deleteNode(&head, 30);
  printf("Singly Linked List after deletion: ");
  traverseList(head);
  return 0;
}
