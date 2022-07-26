struct Node
{
    int data;
    struct Node *nextNode;
    struct Node *prevNode;
};

void printLinkedList(struct Node *Head)
{
    struct Node *temp = Head;

    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->nextNode;
    }
    printf("\n");
}

void addNodeAtBeginning(struct Node **pointerToHead, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *temp = *pointerToHead;
    newNode->nextNode = temp;
    if (temp != NULL)
    {
        temp->prevNode = newNode;
    }

    *pointerToHead = newNode;
    return;
}

void addNode(struct Node **pointerToHead, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    struct Node *current = *pointerToHead, *prevNode;

    if (current == NULL)
    {
        newNode->prevNode = NULL;
        *pointerToHead = newNode;
        return;
    }

    while (current != NULL)
    {
        prevNode = current;
        current = current->nextNode;
    }
    prevNode->nextNode = newNode;
    newNode->prevNode = prevNode;
    return;
}

void deleteNode(struct Node **pointerToHead, int key)
{
    struct Node *current = *pointerToHead;

    if (current->data == key)
    {
        current->nextNode->prevNode = NULL;
        *pointerToHead = current->nextNode;
        free(current);
        return;
    }
    while (current != NULL)
    {

        if (current->data == key)
        {
            current->prevNode->nextNode = current->nextNode;
            if (current->nextNode != NULL)
            {
                current->nextNode->prevNode = current->prevNode;
            }

            free(current);
            return;
        }
        current = current->nextNode;
    }
    if (current == NULL)
    {
        printf("key not found\n");
        return;
    }
}

int listLength(struct Node* Head){
    struct Node * temp = Head;
int count=0;
    while(temp!=NULL){
        count++;
        temp = temp->nextNode;
    }
    return count;
}

void reverseList(struct Node** pointerToHead){
    struct Node* current = *pointerToHead;

    struct Node* temp = NULL;

    while (current !=NULL)
    {
        temp = current->nextNode;
        current->nextNode = current->prevNode;
        current->prevNode = temp;
        current = temp;
    }
    *pointerToHead = current;
}