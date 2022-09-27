#include <stdio.h>
#include <stdlib.h>
#define MIN_VAL -1000000
#define MAX_VAL 1000000

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
struct bstNode *minEle(struct bstNode *root);
struct bstNode *maxEle(struct bstNode *root);
int isBsTree(struct bstNode *root);
int isbsTree(struct bstNode *root);
int isbsTreeutil(struct bstNode *root, int, int);
struct bstNode *deleteNode(struct bstNode *root, int data);

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
  printf("\n");
  printf("min Ele = %d\n", minEle(root)->data);
  printf("max Ele = %d\n", maxEle(root)->data);
  // isBsTree(root) ? printf("Binary tree is Binay search tree")
  //                : printf("Binary Tree is not Binary Search Tree");

  isbsTree(root) ? printf("Binary tree is Binay search tree")
                 : printf("Binary Tree is not Binary Search Tree");
  root = deleteNode(root, 78);
  Print(root);
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

struct bstNode *minEle(struct bstNode *root) {
  if (root->leftNode == NULL)
    return root;
  minEle(root->leftNode);
}
struct bstNode *maxEle(struct bstNode *root) {
  if (root->rightNode == NULL)
    return root;
  maxEle(root->rightNode);
}

int isBsTree(struct bstNode *root) {
  if (root == NULL)
    return 1;
  if (root->leftNode != NULL) {
    if ((root->data) >= (root->leftNode->data)) {
      if (root->rightNode != NULL) {
        if ((root->data) < (root->rightNode->data)) {
          return 1;
        } else
          return 0;
      }
      return 1;
    } else
      return 0;
  }
  return (isBsTree(root->leftNode)) * (isBsTree(root->rightNode));
}

int isbsTree(struct bstNode *root) {
  return isbsTreeutil(root, MIN_VAL, MAX_VAL);
}

int isbsTreeutil(struct bstNode *root, int min, int max) {
  if (root == NULL)
    return 1;
  if (root->data >= min && root->data < max) {
    if (isbsTreeutil(root->leftNode, min, root->data) &&
        isbsTreeutil(root->rightNode, root->data, max)) {
      return 1;
    }
  } else {
    return 0;
  }
}

struct bstNode *deleteNode(struct bstNode *root, int data) {
  if (root == NULL)
    return root;
  if (data > root->data) {
    root->rightNode = deleteNode(root->rightNode, data);
    return root;
  }
  if (data < root->data) {
   root->leftNode = deleteNode(root->leftNode, data);
    return root;
  }

  if (root->data == data) {

    if (root->leftNode == NULL && root->rightNode == NULL) {
      free(root);
      return NULL;
    }

    if (root->rightNode == NULL) {
      struct bstNode *temp = root->leftNode;
      free(root);
      return temp;
    }

    if (root->leftNode == NULL) {
      struct bstNode *temp = root->rightNode;
      free(root);
      return temp;
    }

    struct bstNode *newRoot = maxEle(root->leftNode);
    free(root);
    return newRoot;
  }
}
