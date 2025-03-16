#include "DLCircularList.h"

CircularList* createCircularList(unsigned int sizeOfElement) {
    CircularList* newList = malloc(sizeof(CircularList));
    if (!(newList)) return NULL;

    newList->start = NULL;
    newList->end = NULL;
    newList->listSize = 0;
    newList->sizeOfElement = sizeOfElement;

    return newList;
};

int isListEmpty(CircularList* list) { return (list->listSize == 0); };

int getListSize(CircularList* list) { return list->listSize; };

int addFirst(CircularList* list, void* elementInput) {
    if (!(list)) return 0;

    Node* newNode = malloc(sizeof(Node));
    if (!(newNode)) return 0;

    newNode->element = malloc(list->sizeOfElement);
    if (!(newNode->element)) {
        free(newNode);
        return 0;
    }

    memcpy(newNode->element, elementInput, list->sizeOfElement);
    if (isListEmpty(list)) {
        list->start = newNode;
        list->end = newNode;
        newNode->next = newNode;
        newNode->previous = newNode;
        list->listSize++;

        return 1;
    }

    newNode->next = list->start;
    newNode->previous = list->end;
    list->end->next = newNode;
    list->start->previous = newNode;
    list->start = newNode;
    list->listSize++;

    return 1;
};

int addLast(CircularList* list, void* elementInput) {
    if (!(list)) return 0;

    Node* newNode = malloc(sizeof(Node));
    if (!(newNode)) return 0;

    newNode->element = malloc(list->sizeOfElement);
    if (!(newNode->element)) {
        free(newNode);
        return 0;
    }

    memcpy(newNode->element, elementInput, list->sizeOfElement);
    if (isListEmpty(list)) {
        list->start = newNode;
        list->end = newNode;
        newNode->next = newNode;
        newNode->previous = newNode;
        list->listSize++;

        return 1;
    }

    newNode->next = list->start;
    list->start->previous = newNode;
    newNode->previous = list->end;
    list->end->next = newNode;
    list->end = newNode;
    list->listSize++;

    return 1;
};

int removeFirst(CircularList* list, void* elementOutput) {
    if ((list) && !(isListEmpty(list))) {
        Node* aux = list->start;

        if (getListSize(list) == 1) {
            list->start = NULL;
            list->end = NULL;
            memcpy(elementOutput, aux->element, list->sizeOfElement);
            free(aux->element);
            free(aux);

            list->listSize--;

            return 1;
        }

        list->end->next = aux->next;
        aux->next->previous = list->end;
        list->start = aux->next;
        memcpy(elementOutput, aux->element, list->sizeOfElement);
        free(aux->element);
        free(aux);
        list->listSize--;

        return 1;
    }

    memset(elementOutput, 0, list->sizeOfElement);

    return 0;
};

int removeLast(CircularList* list, void* elementOutput) {
    if ((list) && !(isListEmpty(list))) {
        Node* aux = list->end;

        if (getListSize(list) == 1) {
            list->start = NULL;
            list->end = NULL;
            memcpy(elementOutput, aux->element, list->sizeOfElement);
            free(aux->element);
            free(aux);

            list->listSize--;

            return 1;
        }

        list->start->previous = aux->previous;
        aux->previous->next = list->start;
        list->end = aux->previous;
        memcpy(elementOutput, aux->element, list->sizeOfElement);
        free(aux->element);
        free(aux);
        list->listSize--;

        return 1;
    }

    memset(elementOutput, 0, list->sizeOfElement);

    return 0;
};

int getFirst(CircularList* list, void* elementOutput) {
    if ((list) && !(isListEmpty(list))) {
        Node* aux = list->start;
        memcpy(elementOutput, aux->element, list->sizeOfElement);

        return 1;
    }

    memset(elementOutput, 0, list->sizeOfElement);

    return 0;
};

int getLast(CircularList* list, void* elementOutput) {
    if ((list) && !(isListEmpty(list))) {
        Node* aux = list->end;
        memcpy(elementOutput, aux->element, list->sizeOfElement);

        return 1;
    }

    memset(elementOutput, 0, list->sizeOfElement);

    return 0;
};

void deleteCircularList(CircularList* list) {
    if (!(list)) return;

    Node* next;
    Node* aux = list->start;
    while (list->listSize > 0) {
        next = aux->next;
        free(aux->element);
        free(aux);
        aux = next;

        list->listSize--;
    }

    free(list);
};