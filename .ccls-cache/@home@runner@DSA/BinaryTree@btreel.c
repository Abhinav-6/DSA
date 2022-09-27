#include <stdio.h>
#include <stdlib.h>

struct bstNode {
  int data;
  struct bstNode *rightNode;
  struct bstNode *leftNode;
};
void Print(struct bstNode *root);
void preOrderTraversal(struct bstNode *root);
void postOrderTraversal(struct bstNode *root);
struct bstNode *getNewNode(int data);
struct bstNode *insert(struct bstNode *root, int data);
void Insert(struct bstNode **root, int data);
int isBsTree(struct bstNode* root);
int main() {
  struct bstNode *root = NULL;
  root = insert(root, 100);
  root = insert(root, 17);
  root = insert(root, 47);
  root = insert(root, 23);
  root = insert(root, 89);
  root = insert(root, 34);
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 122);
  root = insert(root, 124);
  root = insert(root, 78);
  Print(root);
  printf("\n");
  preOrderTraversal(root);
  printf("\n");
  postOrderTraversal(root);
}

void Print(struct bstNode *root) {
  if (root == NULL) {
    return;
  }
  Print(root->leftNode);
  printf(" %d ", root->data);
  Print(root->rightNode);
}

void preOrderTraversal(struct bstNode *root) {
  if (root == NULL)
    return;
  printf(" %d ", root->data);
  preOrderTraversal(root->leftNode);
  preOrderTraversal(root->rightNode);
}

void postOrderTraversal(struct bstNode *root) {
  if (root == NULL)
    return;
  postOrderTraversal(root->leftNode);
  postOrderTraversal(root->rightNode);
  printf(" %d ", root->data);
}

struct bstNode *getNewNode(int data) {
  struct bstNode *newChild = (struct bstNode *)malloc(sizeof(struct bstNode));
  newChild->data = data;
  newChild->rightNode = newChild->leftNode = NULL;
  return newChild;
}

struct bstNode *insert(struct bstNode *root, int data) {
  struct bstNode *newNode = getNewNode(data);
  if (root == NULL) {
    root = newNode;
    return root;
  }

  if (data <= root->data) {
    root->leftNode = insert(root->leftNode, data);
    return root;
  }
  root->rightNode = insert(root->rightNode, data);
  return root;
}

int isBsTree(struct bstNode* root){
	if;
	return 0;
}