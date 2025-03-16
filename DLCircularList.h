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
    void* element;  /**<A pointer to element. */
    Node* next;     /**<A pointer to next element. */
    Node* previous; /**<A pointer to previous element. */
};

struct CircularList {
    Node* start;                /**<A pointer to the first element. */
    Node* end;                  /**<A pointer to the last element. */
    unsigned int listSize;      /**<The size of the list. */
    unsigned int sizeOfElement; /**<The size of the element that will be stored
                                   in the list. */
};

/**
 * @brief Create a new CircularList.
 * @param sizeOfElement The size of the element that will be stored in the list.
 * @return A pointer to the new CircularList.
 */
CircularList* createCircularList(unsigned int sizeOfElement);

/**
 * @brief Check if the list is empty.
 * @param list A pointer to the CircularList.
 * @return 1 if the list is empty, 0 otherwise.
 */
int isListEmpty(CircularList* list);

/**
 * @brief Get the size of the list.
 * @param list A pointer to the CircularList.
 * @return The size of the list.
 */
int getListSize(CircularList* list);

/**
 * @brief Add an element to the beginning of the list.
 * @param list A pointer to the CircularList.
 * @param elementInput A pointer to the element that will be added.
 * @return 1 if the element was added, 0 otherwise.
 */
int addFirst(CircularList* list, void* elementInput);

/**
 * @brief Add an element to the end of the list.
 * @param list A pointer to the CircularList.
 * @param elementInput A pointer to the element that will be added.
 * @return 1 if the element was added, 0 otherwise.
 */
int addLast(CircularList* list, void* elementInput);

/**
 * @brief Remove the first element of the list.
 * @param list A pointer to the CircularList.
 * @param elementOutput A pointer to the memory region where the element will be
 * copied.
 * @return 1 if the element was removed, 0 otherwise.
 */
int removeFirst(CircularList* list, void* elementOutput);

/**
 * @brief Remove the last element of the list.
 * @param list A pointer to the CircularList.
 * @param elementOutput A pointer to the memory region where the element will be
 * copied.
 * @return 1 if the element was removed, 0 otherwise.
 */
int removeLast(CircularList* list, void* elementOutput);

/**
 * @brief Get the first element of the list.
 * @param list A pointer to the CircularList.
 * @param elementOutput A pointer to the memory region where the element will be
 * copied.
 * @return 1 if the element was returned, 0 otherwise.
 */
int getFirst(CircularList* list, void* elementOutput);

/**
 * @brief Get the last element of the list.
 * @param list A pointer to the CircularList.
 * @param elementOutput A pointer to the memory region where the element will be
 * copied.
 * @return 1 if the element was returned, 0 otherwise.
 */
int getLast(CircularList* list, void* elementOutput);

/**
 * @brief Delete the CircularList.
 * @param list A pointer to the CircularList.
 */
void deleteCircularList(CircularList* list);

#endif