#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(){
    struct Node* Head = NULL;
    addNode(&Head, 5);
    addNode(&Head, 6);
    addNodeAtBeginning(&Head, 10);
    addNode(&Head, 67);
    printList(Head);
    reverseLinkedList(&Head);
    printList(Head);
    printf("Length = %d\n", listLength(Head));
    return 0;
}