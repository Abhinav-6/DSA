#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;

void Push(int data);
void Pop();
void Print();
void Top();
void isEmpty();

int main() {
  Push(5);
  Push(58);
  Push(55);
  Print();
  Pop();
  Print();
	Top();
	isEmpty();
  return 0;
}

void Print() {
  if (top == -1) {
    printf("stack is Empty");
    return;
  }
  for (int i = top; i >= 0; i--) {
    printf(" %d ", stack[i]);
  }
  printf("\n");
}

void Push(int data) {
  if (top == sizeof(stack) / sizeof(int)) {
    printf("Stack is full");
    return;
  }
  top++;
  stack[top] = data;
}
void Pop() { 
	if(top==-1){
		printf("Stack is Empty");
		return;
	}
	top--; }
void Top(){
	printf("%d\n", stack[top]);
}
void isEmpty(){
	if(top==-1){
		printf("Stack is Empty\n");
		return;
	}
	printf("stack is not empty\n");
}