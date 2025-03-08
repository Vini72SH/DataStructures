/**
 * @file linkedList.h
 * @brief generic list struct
 * @details This is an implementation of a generic List.
 * To insert and remove elements, it is necessary to pass a pointer to a
 * memory region, so that the copy is done efficiently.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;
struct Node {
    void* element; /**<Element of a node. */
    Node* next;    /**<Pointer to next node. */
};

struct LinkedList {
    Node* head;                 /**<Pointer to the first node. */
    Node* tail;                 /**<Pointer to the last node. */
    unsigned int listSize;      /**<Size of the list. */
    unsigned int sizeOfElement; /**<Size of the element. */
};

/**
 * @brief Allocates memory for a LinkedList.
 * @param sizeOfElement Size of the element.
 * @return Pointer to the LinkedList.
 */
LinkedList* allocateLinkedList(unsigned int sizeOfElement);

/**
 * @brief Inserts an element at the beginning of the list.
 * @param list Pointer to the LinkedList.
 * @param elementInput Pointer to the element to be inserted.
 * @return 1 if successfuly, 0 otherwise.
 */
int insertAtBeginning(LinkedList* list, void* elementInput);

/**
 * @brief Removes the element at the beginning of the list.
 * @param list Pointer to the LinkedList.
 * @param elementOutput Pointer to the memory region where the element will be
 * returned.
 * @return 1 if successfuly, 0 otherwise.
 */
int removeAtBeginning(LinkedList* list, void* elementOutput);

/**
 * @brief Inserts an element at the end of the list.
 * @param list Pointer to the LinkedList.
 * @param elementInput Pointer to the element to be inserted.
 * @return 1 if successfuly, 0 otherwise.
 */
int insertAtEnd(LinkedList* list, void* elementInput);

/**
 * @brief Removes the element at the end of the list.
 * @param list Pointer to the LinkedList.
 * @param elementOutput Pointer to the memory region where the element will be
 * returned.
 * @return 1 if successfuly, 0 otherwise.
 */
int removeAtEnd(LinkedList* list, void* elementOutput);

/**
 * @brief Get the size of the list.
 * @param list Pointer to the LinkedList.
 * @return Size of the list.
 */
int getSizeOfList(LinkedList* list);

/**
 * @brief Is the list empty?
 * @param list Pointer to the LinkedList.
 * @return 1 if the list is empty, 0 otherwise.
 */
int isEmptyList(LinkedList* list);

/**
 * @brief Free the memory allocated for the list.
 * @param list Pointer to the LinkedList.
 */
void freeList(LinkedList* list);

#endif