#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the binary tree
typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;
// Function to create a new node with given data
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
// Function to create a binary tree
Node* createBinaryTree() {
  Node* root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);
  return root;
}
// Function to traverse the binary tree in preorder
void preorderTraversal(Node* node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->data);
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}
// Function to traverse the binary tree in inorder
void inorderTraversal(Node* node) {
  if (node == NULL) {
    return;
  }
  inorderTraversal(node->left);
  printf("%d ", node->data);
  inorderTraversal(node->right);
}
// Function to traverse the binary tree in postorder
void postorderTraversal(Node* node) {
  if (node == NULL) {
    return;
  }
  postorderTraversal(node->left);
  postorderTraversal(node->right);
  printf("%d ", node->data);
}
int main() {
  Node* root = createBinaryTree();
  printf("Preorder Traversal: ");
  preorderTraversal(root);
  printf("\n");
  printf("Inorder Traversal: ");
  inorderTraversal(root);
  printf("\n");
  printf("Postorder Traversal: ");
  postorderTraversal(root);
  printf("\n");
  return 0;
}
