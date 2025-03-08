#include "linkedList.h"

LinkedList* allocateLinkedList(unsigned int sizeOfElement) {
    LinkedList* newList = malloc(sizeof(LinkedList));
    if (!(newList)) return NULL;

    newList->head = NULL;
    newList->tail = NULL;
    newList->listSize = 0;
    newList->sizeOfElement = sizeOfElement;

    return newList;
};

int insertAtBeginning(LinkedList* list, void* elementInput) {
    if (!(list)) return 0;

    Node* newNode = malloc(sizeof(Node));
    if (!(newNode)) return 0;

    newNode->element = malloc(list->sizeOfElement);
    if (!(newNode->element)) {
        free(newNode);
        return 0;
    }

    memcpy(newNode->element, elementInput, list->sizeOfElement);
    newNode->next = list->head;
    list->head = newNode;

    if (isEmptyList(list)) list->tail = newNode;

    list->listSize++;

    return 1;
};

int removeAtBeginning(LinkedList* list, void* elementOutput) {
    if (!(list) || isEmptyList(list)) return 0;

    Node* nodeToRemove = list->head;
    list->head = nodeToRemove->next;

    memcpy(elementOutput, nodeToRemove->element, list->sizeOfElement);
    free(nodeToRemove->element);
    free(nodeToRemove);

    if (isEmptyList(list)) list->tail = NULL;

    list->listSize--;

    return 1;
};

int insertAtEnd(LinkedList* list, void* elementInput) {
    if (!(list)) return 0;

    Node* newNode = malloc(sizeof(Node));
    if (!(newNode)) return 0;

    newNode->element = malloc(list->sizeOfElement);
    if (!(newNode->element)) {
        free(newNode);
        return 0;
    }

    newNode->next = NULL;
    memcpy(newNode->element, elementInput, list->sizeOfElement);

    if (isEmptyList(list)) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }

    list->tail = newNode;
    list->listSize++;

    return 1;
};

int removeAtEnd(LinkedList* list, void* elementOutput) {
    if (!(list) || isEmptyList(list)) return 0;

    Node* nodeToRemove = list->tail;
    Node* previousNode = list->head;

    while ((previousNode->next != list->tail) && (previousNode->next != NULL))
        previousNode = previousNode->next;

    if (previousNode->next == NULL) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        previousNode->next = NULL;
        list->tail = previousNode;
    }

    memcpy(elementOutput, nodeToRemove->element, list->sizeOfElement);
    free(nodeToRemove->element);
    free(nodeToRemove);

    list->listSize--;

    return 1;
};

int getSizeOfList(LinkedList* list) {
    if (!list) return -1;
    return list->listSize;
};

int isEmptyList(LinkedList* list) { return (list->listSize == 0); };

void freeList(LinkedList* list) {
    if (!(list)) return;

    Node* currentNode = list->head;
    Node* nextNode = NULL;

    while (currentNode) {
        nextNode = currentNode->next;
        free(currentNode->element);
        free(currentNode);
        currentNode = nextNode;
    }

    free(list);
};