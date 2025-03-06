/**
 * @file queue.h
 * @brief generic queue struct
 * @details This is an implementation of a generic queue that uses the FIFO
 * policy. To enqueue and dequeue values, it is necessary to pass a pointer to a
 * memory region, so that the copy is done efficiently.
 */

#ifndef QUEUE_H
#define QUEUE_H

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
 * @brief Inserts an element at the end of the queue, allocating memory for it
 * in the queue (FIFO)
 * @param queue A pointer to a queue.
 * @param elementInput The element to insert.
 * @return 1 if successful, 0 otherwise.
 */
int enqueue(Queue* queue, void* elementInput);

/**
 * @brief Removes the first element from the queue and inserts it into the
 * memory region (FIFO)
 * @param queue A pointer to a queue.
 * @param elementOutput A pointer to the memory region where the first element
 * of the queue will be sent.
 * @return 1 if successful, 0 otherwise.
 */
int dequeue(Queue* queue, void* elementOutput);

/**
 * @brief Get the size of queue.
 * @param queue A pointer to a queue.
 * @return The size of the queue.
 */
unsigned int getSizeOfQueue(Queue* queue);

/**
 * @brief The queue is empty?
 * @param queue A pointer to a queue.
 * return 1 if is Empty, 0 otherwise.
 */
int isQueueEmpty(Queue* queue);

/**
 * @brief Delete the queue, freeing memory.
 * @param queue A pointer to a queue.
 */
void deleteQueue(Queue* queue);

#endif