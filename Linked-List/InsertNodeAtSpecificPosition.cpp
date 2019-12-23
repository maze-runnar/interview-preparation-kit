SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {

    SinglyLinkedListNode *newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    newNode->data = data;

    if (head == NULL) {
        return newNode;
    }

    if (position == 0) {
       newNode->next = head;
       return newNode;
    }

    SinglyLinkedListNode *currentNode = head;
    while (position - 1 > 0) {
        currentNode = currentNode->next;
        position--;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;

    return head;    


}
