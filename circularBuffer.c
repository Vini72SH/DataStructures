#include "circularBuffer.h"

CircularBuffer* createBuffer(int bufferSize, int sizeOfElement) {
    CircularBuffer* newBuffer = malloc(sizeof(CircularBuffer));
    if (!(newBuffer)) return NULL;

    newBuffer->buffer = malloc(bufferSize * sizeOfElement);
    if (!(newBuffer->buffer)) {
        free(newBuffer);
        return NULL;
    }

    newBuffer->bufferSize = bufferSize;
    newBuffer->sizeOfElement = sizeOfElement;
    newBuffer->occupation = 0;
    newBuffer->startOfBuffer = 0;
    newBuffer->endOfBuffer = 0;

    return newBuffer;
};

int isBufferEmpty(CircularBuffer* buffer) {
    return (buffer->occupation == 0);
};

int isBufferFull(CircularBuffer* buffer) {
    return (buffer->occupation == buffer->bufferSize);
};

int getOccupation(CircularBuffer* buffer) {
    return buffer->occupation;
};

int insertOnBuffer(CircularBuffer* buffer, void* elementInput) {
    if (!(buffer) || isBufferFull(buffer)) return 0;

    void* memoryAddress = (char*)buffer->buffer + (buffer->endOfBuffer * buffer->sizeOfElement);
    memcpy(memoryAddress, elementInput, buffer->sizeOfElement);

    buffer->occupation++;
    buffer->endOfBuffer++;

    if (buffer->endOfBuffer == buffer->bufferSize) {
        buffer->endOfBuffer = 0;
    }

    return 1;
};

int removeFromBuffer(CircularBuffer* buffer, void* elementOutput) {
    if (!(buffer) || isBufferEmpty(buffer)) return 0;

    void* memoryAddress = (char*)buffer->buffer + (buffer->startOfBuffer * buffer->sizeOfElement);
    memcpy(elementOutput, memoryAddress, buffer->sizeOfElement);

    buffer->occupation--;
    buffer->startOfBuffer++;

    if (buffer->startOfBuffer == buffer->bufferSize) {
        buffer->startOfBuffer = 0;
    }

    return 1;
};

void destroyBuffer(CircularBuffer* buffer) {
    free(buffer->buffer);
    free(buffer);
};