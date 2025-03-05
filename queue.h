/**
 * @file queue.hpp
 * @brief generic queue struct
 * @details This is an implementation of a generic queue
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue Queue;
typedef struct Node Node;

struct Node {
    void* element; /**<Element of a node. */
    Node* next;    /**<Pointer to next node. */
};

struct Queue {
    Node* start;                /**<Pointer to start of the queue. */
    Node* end;                  /**<Pointer to end of the queue. */
    unsigned int queueSize;     /**<The queue size. */
    unsigned int sizeOfElement; /**<The size of elements used in the queue. */
};

/**
 * @brief Allocate the struct of the queue
 * @param sizeOfElement The size of elements used in the queue.
 * @return A pointer to a Queue.
 */
Queue* allocateQueue(unsigned int sizeOfElement);

/**
 * @brief Insert an element in the queue.
 * @param queue A pointer to a queue.
 * @param element The element to insert.
 */
void enqueue(Queue* queue, void* element);

/**
 * @brief Get the size of queue.
 * @param queue A pointer to a queue.
 * @return The size of the queue.
 */
int getSizeOfQueue(Queue* queue);

/**
 * @brief The queue is empty?
 * @param queue A pointer to a queue.
 * return 1 if is Empty, 0 otherwise.
 */
char isEmpty(Queue* queue);

/**
 * @brief Remove the first element of the queue.
 * @param queue A pointer to a queue.
 * @return A pointer to the element.
 */
void* dequeue(Queue* queue);

/**
 * @brief Delete the queue, freeing memory.
 * @param queue A pointer to a queue.
 */
void deleteQueue(Queue* queue);

#endif