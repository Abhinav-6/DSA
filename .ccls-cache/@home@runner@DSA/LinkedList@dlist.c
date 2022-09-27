#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* nextNode;
	struct Node* prevNode;
};

void insertAtStart(struct Node**Head, int data);
void insert(struct Node** Head, int data);
void PrintList(struct Node* Head);

int main(){
	struct Node* Head = NULL;
	insertAtStart(&Head, 77);
	insertAtStart(&Head, 74);
	insert(&Head, 76);
	PrintList(Head);

	return 0;
}
