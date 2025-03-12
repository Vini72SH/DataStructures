/**
 * @file circularBuffer.h
 * @brief generic circular buffer struct
 * @details This is an implementation of a generic buffer in a circular array
 * implementation. Elements are passed by pointers to memory regions and the
 * structure manages the space allocated for the array.
 */

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdlib.h>
#include <string.h>

typedef struct CircularBuffer {
    void* buffer;      /**<The Buffer. */
    int occupation;    /**<Buffer's current occupancy */
    int bufferSize;    /**<The maximum buffer capacity. */
    int sizeOfElement;   /**<The element size supported by the buffer. */
    int startOfBuffer; /**<Sentinel to the start of the buffer. */
    int endOfBuffer;   /*<Sentinel for the end of the buffer. */
}CircularBuffer;

/**
 * @brief Create the buffer.
 * @param bufferSize The size of the buffer.
 * @param sizeOfElement The size of the element stored in the buffer.
 * @return A pointer to the buffer.
 */
CircularBuffer* createBuffer(int bufferSize, int sizeOfElement);

/**
 * @brief Check if the buffer is empty.
 * @param buffer The buffer to be checked.
 * @return 1 if the buffer is empty, 0 otherwise. 
 */
int isBufferEmpty(CircularBuffer* buffer);

/**
 * @brief Check if the buffer is full.
 * @param buffer The buffer to be checked.
 * @return 1 if the buffer is full, 0 otherwise.
 */
int isBufferFull(CircularBuffer* buffer);

/**
 * @brief Get the current occupation of the buffer.
 * @param buffer A pointer to the buffer.
 * @return The current occupation of the buffer.
 */
int getOccupation(CircularBuffer* buffer);

/**
 * @brief Insert an element in the buffer.
 * @param buffer The buffer to insert the element.
 * @param elementInput The element to be inserted.
 * @return 1 if successful, 0 otherwise.
 */
int insertOnBuffer(CircularBuffer* buffer, void* elementInput);

/**
 * @brief Remove the first element of buffer.
 * @param buffer The buffer to remove the element.
 * @param elementOutput The element removed.
 * @return 1 if successful, 0 otherwise. 
 */
int removeFromBuffer(CircularBuffer* buffer, void* elementOutput);

/**
 * @brief Delete the buffer.
 * @param buffer The buffer to be deleted.
 */
void destroyBuffer(CircularBuffer* buffer);

#endif