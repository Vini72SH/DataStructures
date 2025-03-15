/**
 * @file queue.h
 * @brief generic queue struct
 * @details This is an implementation of a generic queue that uses the FIFO
 * policy. To enqueue and dequeue values, it is necessary to pass a pointer to a
 * memory region, so that the copy is done efficiently.
 */

#ifndef DLCIRCULAR_LIST_H
#define DLCIRCULAR_LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct CircularList CircularList;
typedef struct Node Node;

struct Node {
    void* element;
    Node* next;
    Node* previous;
};

struct CircularList {
    Node* start;
    Node* end;
    Node* iterator;
    unsigned int listSize;
    unsigned int sizeOfElement;
};

CircularList* createCircularList(unsigned int sizeOfElement);
int isListEmpty(CircularList* list);
int getListSize(CircularList* list);
void addFirst(CircularList* list, void* elementInput);
void addLast(CircularList* list, void* elementInput);
void removeFirst(CircularList* list, void* elementOutput);
void removeLast(CircularList* list, void* elementOutput);
void getFirst(CircularList* list, void* elementOutput);
void getLast(CircularList* list, void* elementOutput);
void clearList(CircularList* list);
void deleteCircularList(CircularList* list);

#endif