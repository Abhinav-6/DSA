#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

int main()
{
    struct Node *Head = NULL;
    addNodeAtBeginning(&Head, 76);
    addNodeAtBeginning(&Head, 86);
    addNode(&Head, 66);
    addNode(&Head, 96);
    addNode(&Head, 16);
    addNode(&Head, 36);
    printLinkedList(Head);
    reverseList(&Head);
    printLinkedList(Head);
    return 0;
}