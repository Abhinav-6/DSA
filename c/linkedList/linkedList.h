struct Node
{
    int data;
    struct Node *nextNode;
};

void printList(struct Node *headNode)
{
    struct Node *temp = headNode;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->nextNode;
    }
    printf("\n");
}

void addNode(struct Node **pointerToHead, int data)
{
    struct Node *temp = *pointerToHead;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*pointerToHead == NULL)
    {
        newNode->nextNode = temp;
        *pointerToHead = newNode;
        return;
    }

    struct Node *prevNode = (struct Node *)malloc(sizeof(struct Node));

    while (temp != NULL)
    {
        prevNode = temp;
        temp = temp->nextNode;
    }
    prevNode->nextNode = newNode;
    newNode->nextNode = NULL;
    free(temp);
}

void addNodeAtBeginning(struct Node **pointerToHead, int data)
{
    struct Node *temp = *pointerToHead;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->nextNode = temp;

    *pointerToHead = newNode;
    return;
}

void deleteNode(struct Node **pointerToHead, int key)
{
    struct Node *temp = *pointerToHead;

    if (temp->data == key)
    {
        *pointerToHead = temp->nextNode;
        free(temp);
        return;
    }

    struct Node *prevNode;

    while (temp != NULL && temp->data != key)
    {
        prevNode = temp;
        temp = temp->nextNode;
    }
    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }
    prevNode->nextNode = temp->nextNode;
    free(temp);
    return;
}

int listLength(struct Node* Head){
    if(Head == NULL){
        printf("List is empty");
        return 0;
    }
    struct Node* temp = Head;
    int count = 0;
    while (temp!=NULL)
    {
        count++;
        temp = temp->nextNode;
    }
    return count;
}


void reverseLinkedList(struct Node** pointerToHead){
    struct Node* currentNode = *pointerToHead, *previousNode = NULL, *nextNode;

    while (currentNode!=NULL)
    {
        nextNode = currentNode->nextNode;
        currentNode->nextNode = previousNode;
        previousNode = currentNode;
        currentNode=nextNode;
    }
    *pointerToHead = previousNode;
    
}