#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* nextNode;
};

void Push(struct Node** top, int data);
void Pop(struct Node**top);
void Print(struct Node* top);
void Top(struct Node* top);
void isEmpty(struct Node* top);

int main(){
	struct Node* top = NULL;
	Push(&top, 77);
	Push(&top, 73);
	Push(&top, 57);
	Print(top);
	Pop(&top);
	Print(top);
	Push(&top, 99);
	Print(top);
	Top(top);
	isEmpty(top);

	return 0;
}

void Print(struct Node*top){
	if(top==NULL){
		printf("Stack is Empty");
		return;
	}
	while(top!=NULL){
		printf(" %d ", top->data);
		top=top->nextNode;
	}
	printf("\n");
}

void Push(struct Node** top,int data){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->nextNode = *top;
	*top = newNode;
}

void Pop(struct Node** top){
	struct Node* temp = *top;
	*top = temp->nextNode;
	free(temp);
}
void Top(struct Node* top){
	printf("%d\n", top->data);
}

void isEmpty(struct Node* top){
	if(top==NULL){
		printf("Stack is Empty");
		return;
	}
	printf("Stack is not Empty");
}